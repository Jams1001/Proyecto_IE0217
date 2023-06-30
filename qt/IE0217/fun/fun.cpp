#include "fun.h"

Curso::Curso(const std::string& sigla, const std::string& nombre, const std::string& departamento)
    : sigla(sigla), nombre(nombre), departamento(departamento) {}

Teacher::Teacher(const std::string& nombre) : nombre(nombre) {}

std::string Teacher::getName() const {
    // Devuelve el nombre del profesor (asumiendo que tienes un miembro de clase que almacena el nombre)
    return this->nombre;
}

Classroom::Classroom(const std::string& numeroAula) : numeroAula(numeroAula) {}

std::string Classroom::getName() const {
    // Devuelve el nombre del profesor (asumiendo que tienes un miembro de clase que almacena el nombre)
    return this->numeroAula;
}


void Ciclo::agregarCurso(const Curso& curso) {
    cursos.push_back(curso);
}

Fila::Fila(Ciclo* ciclo, const std::string& sigla, const std::string& nombre, int grupo,
           const std::string& dia, int horaInicio, int horaFinal, int aula, int cupo,
           const std::string& profesor, const std::string& departamento, const std::string& observaciones)
    : ciclo(ciclo), sigla(sigla), nombre(nombre), grupo(grupo), dia(dia),
      horaInicio(horaInicio), horaFinal(horaFinal), aula(aula), cupo(cupo),
      profesor(profesor), departamento(departamento), observaciones(observaciones) {}

void Horario::agregarFila(const Fila& fila) {
    filas.push_back(fila);
}
