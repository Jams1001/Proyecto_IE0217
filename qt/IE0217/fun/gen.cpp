#include "gen.h"
#include <QDebug>

// Implementación de la clase Cursog
Cursog::Cursog(const QString& _ciclo, const QString& _sigla_curso, int _distribucion_dias_semanales,
        int _horas_totales_semanales, const QStringList& _rango_externo_invalido, 
        const QStringList& _rango_interno_invalido, const QList<int>& _aulas, int _cantidad_grupos)
        : ciclo(_ciclo), sigla_curso(_sigla_curso), 
        distribucion_dias_semanales(_distribucion_dias_semanales),
        horas_totales_semanales(_horas_totales_semanales),
        rango_externo_invalido(_rango_externo_invalido),
        rango_interno_invalido(_rango_interno_invalido),
        aulas(_aulas), cantidad_grupos(_cantidad_grupos) {}

QList<QList<Horario>> Cursog::generarHorarios() const {
    QList<QList<Horario>> horarios;

    // Generar todos los bloques de horarios posibles.
    QStringList dias = {"L", "K", "M", "J", "V"};
    int duracion = horas_totales_semanales / distribucion_dias_semanales; // Fijar la duración al mínimo de horas por día
    for (int i = 0; i < dias.size() - distribucion_dias_semanales + 1; ++i) {
        for (int horaInicio = 7; horaInicio <= 22 - duracion; ++horaInicio) { // Asegurarse de que el bloque de horario no se extienda más allá de las 22:00
            QList<Horario> bloqueHorario;
            for (int j = 0; j < distribucion_dias_semanales; ++j) {
                int horaFinal = horaInicio + duracion;
                Horario horario(dias[i+j].toStdString(), QString::number(horaInicio).toStdString(), QString::number(horaFinal).toStdString());
                bloqueHorario.append(horario);
            }
            horarios.append(bloqueHorario);
        }
    }

    // Filtrar horarios que cumplen con las restricciones
    QList<QList<Horario>> horariosFiltrados;
    for (const auto& bloqueHorario : horarios) {
        bool valido = true;
        for (const auto& horario : bloqueHorario) {
            if (!esHorarioValido(horario)) {
                valido = false;
                break;
            }
        }
        if (valido) {
            horariosFiltrados.append(bloqueHorario);
        }
    }

    return horariosFiltrados;
}




bool Cursog::esHorarioValido(const Horario& horario) const {
    // Convierte las horas de inicio y final a enteros para la comparación
    int horaInicio = std::stoi(horario.horaInicio);
    int horaFinal = std::stoi(horario.horaFinal);

    // Comprobar rango interno invalido.
    for (const auto& rango : rango_interno_invalido) {
        QStringList partes = rango.split(':');
        QString dia = partes[0];
        QStringList horas = partes[1].split('-');
        int inicioInvalido = horas[0].toInt();
        int finalInvalido = horas[1].toInt();
        if (horario.dia == dia.toStdString() && !(horaFinal <= inicioInvalido || horaInicio >= finalInvalido)) {
            return false; // El horario está en un rango inválido
        }
    }
    // Comprobar rango externo invalido
    for (const auto& rango : rango_externo_invalido) {
        QStringList partes = rango.split(':');
        QString dia = partes[0];
        QStringList horas = partes[1].split('-');
        int inicioInvalido = horas[0].toInt();
        int finalInvalido = horas[1].toInt();
        if (horario.dia == dia.toStdString() && !(horaFinal <= inicioInvalido || horaInicio >= finalInvalido)) {
            return false; // El horario está en un rango inválido
        }
    }

    // Si llegamos hasta aquí, el horario es válido
    return true;
}


QList<Cursog> leerCursosDesdeCSV(const QString& rutaArchivo) {
    QList<Cursog> cursos;
    QFile archivo(rutaArchivo);

    if (archivo.open(QIODevice::ReadOnly)) {
        QTextStream in(&archivo);
        in.readLine(); // Ignora primera linea

        while (!in.atEnd()) {
            QString linea = in.readLine();
            QStringList campos = linea.split(',');

            QString ciclo = campos[0];
            QString sigla_curso = campos[1];
            int distribucion_dias_semanales = campos[2].toInt();
            int horas_totales_semanales = campos[3].toInt();

            // Procesa los rangos invalidos externos e internos
            QStringList rango_externo_invalido = campos[4].split('y', QString::SkipEmptyParts);
            QStringList rango_interno_invalido = campos[5].split('y', QString::SkipEmptyParts);

            // Procesa las aulas
            QStringList aulasStrList = campos[6].split('y', QString::SkipEmptyParts);
            QList<int> aulas;
            for (const QString& aula : aulasStrList) {
                aulas.append(aula.toInt());
            }

            int cantidad_grupos = campos[7].toInt();

            // Creandp el objeto Cursog y lo añadiedo a la lista
            Cursog curso(ciclo, sigla_curso, distribucion_dias_semanales, horas_totales_semanales,
                        rango_externo_invalido, rango_interno_invalido, aulas, cantidad_grupos);
            cursos.append(curso);
        }

        archivo.close();
    }

    return cursos;
}

void generarCSVsParaCursos(const QList<Cursog>& cursos) {
    // Guarda todas las combinaciones válidas para cada curso.
    QMap<QString, QList<QList<Horario>>> combinacionesValidasPorCurso;

    // Bucle sobre todos los cursos
    for (const Cursog& curso : cursos) {
        // Obtener todas las posibles combinaciones de horarios para el curso actual
        QList<QList<Horario>> horarios = curso.generarHorarios();

        // Bucle sobre todos los horarios posibles.
        for (const QList<Horario>& bloqueHorario : horarios) {
            // Asume que todos los horarios en un bloque son válidos ya que ya hemos filtrado los bloques inválidos.
            combinacionesValidasPorCurso[curso.ciclo + "_" + curso.sigla_curso].append(bloqueHorario);
        }
    }

    // Ahora, vamos a generar dos archivos CSV de salida.
    for (int i = 0; i < 2; ++i) {
        // Abre el archivo CSV para escritura.
        QString rutaCarpeta = "./posibilidades/";
        QFile file(rutaCarpeta + "combinacion" + QString::number(i + 1) + ".csv");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }

        QTextStream out(&file);

        // Escribe la cabecera del CSV.
        out << "Ciclo,Sigla,Grupo,Horario,Aula\n";

        // Escribe los datos de las combinaciones válidas.
        for (auto it = combinacionesValidasPorCurso.begin(); it != combinacionesValidasPorCurso.end(); ++it) {
            // Para cada curso, escribe los detalles del curso y el horario.
            for (const Cursog& curso : cursos) {
                if (it.key().split("_")[1] == curso.sigla_curso && i < it.value().size()) {
                    QString horarioString;
                    for (const Horario& horario : it.value()[i]) {
                        horarioString += QString::fromStdString(horario.formatear()) + " y ";
                    }
                    horarioString.chop(3); // Remueve el " y " final
                    out << it.key().split("_")[0] << ',' << curso.sigla_curso << ',' << 1 << ',' << horarioString << ',' << curso.aulas[0] << '\n';
                }
            }
        }

        // Cierra el archivo CSV.
        file.close();
    }
}
