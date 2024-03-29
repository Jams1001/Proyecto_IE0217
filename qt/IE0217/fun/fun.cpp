#include "fun.h"

Curso::Curso(const std::string& ciclo, const std::string& sigla, const std::string& nombre, const std::string& departamento)
    : ciclo(ciclo), sigla(sigla), nombre(nombre), departamento(departamento) {}

Teacher::Teacher(const std::string& nombre) : nombre(nombre) {}

Classroom::Classroom(const std::string& numeroAula) : numeroAula(numeroAula) {}

void Ciclo::agregarCurso(const Curso& curso) {
    cursos.push_back(curso);
}

Fila::Fila(const std::string& ciclo, const std::string& sigla, const std::string& nombrecurso, const std::string& grupo,
           const std::vector<Horario>& horarios, const std::string& aula, const std::string& cupo,
           const std::string& profesor, const std::string& departamento, const std::string& observaciones)
    : ciclo(ciclo), sigla(sigla), nombrecurso(nombrecurso), grupo(grupo), horarios(horarios),
      aula(aula), cupo(cupo), profesor(profesor), departamento(departamento), observaciones(observaciones) {}


void Guia::agregarFila(const Fila& fila) {
    filas.push_back(fila);
}
