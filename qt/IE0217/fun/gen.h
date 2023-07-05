/**
 * @file gen.h
 * @brief This file contains... 
 * @author Jorge Mora (jorgeadan.mora@ucr.ac.cr)
 * @version 0.1
 * @date 2023-07-95
 */


#ifndef GEN_H
#define GEN_H

#include <QList>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QTextStream>
#include "fun.h"

// Declaración de la clase Cursog
class Cursog {
public:
    // Propiedades del curso.
    QString ciclo;
    QString sigla_curso;
    int distribucion_dias_semanales;
    int horas_totales_semanales;
    QStringList rango_externo_invalido;
    QStringList rango_interno_invalido;
    QList<int> aulas;
    int cantidad_grupos;

    // Constructor para inicializar todas las propiedades.
    Cursog(const QString& _ciclo, const QString& _sigla_curso, int _distribucion_dias_semanales,
        int _horas_totales_semanales, const QStringList& _rango_externo_invalido, 
        const QStringList& _rango_interno_invalido, const QList<int>& _aulas, int _cantidad_grupos);

    // Métodos de la clase
    QList<QList<Horario>> generarHorarios() const;
    bool esHorarioValido(const Horario& horario) const;
};

// Declaración de las funciones
QList<Cursog> leerCursosDesdeCSV(const QString& rutaArchivo);
void generarCSVsParaCursos(const QList<Cursog>& cursos);

#endif // GEN_H
