/**
 * @file fun.h
 * @brief This file contains the declaration of the functional (implementation) classes and functions. 
 * @author Jorge Mora (jorgeadan.mora@ucr.ac.cr)
 * @version 0.1
 * @date 2023-06-25
 */

#ifndef FUN_H
#define FUN_H

#include <string>
#include <vector>

/**
 * @class Curso
 * @brief Represents a course.
 */
class Curso {
public:
    std::string sigla; /**< The course code. */
    std::string nombre; /**< The course name. */
    std::string departamento; /**< The department offering the course. */

    /**
     * @brief Constructs a Curso object.
     * @param sigla The course code.
     * @param nombre The course name.
     * @param departamento The department offering the course.
     */
    Curso(const std::string& sigla, const std::string& nombre, const std::string& departamento);
};

/**
 * @class Teacher
 * @brief Represents a teacher.
 */
class Teacher {
public:
    std::string nombre; /**< The teacher's name. */

    /**
     * @brief Constructs a Teacher object.
     * @param nombre The teacher's name.
     */
    Teacher(const std::string& nombre);
};

/**
 * @class Classroom
 * @brief Represents a classroom.
 */
class Classroom {
public:
    std::string numeroAula; /**< The classroom number. */

    /**
     * @brief Constructs a Classroom object.
     * @param numeroAula The classroom number.
     */
    Classroom(const std::string& numeroAula);
};

/**
 * @class Ciclo
 * @brief Represents a cycle.
 */
class Ciclo {
public:
    int Ciclo; /**< The cycle number. */
    std::vector<Curso> cursos; /**< The courses in the cycle. */

    /**
     * @brief Adds a course to the cycle.
     * @param curso The course to be added.
     */
    void agregarCurso(const Curso& curso);
};

/**
 * @class Fila
 * @brief Represents a row in a schedule.
 */
class Fila {
public:
    Ciclo* ciclo; /**< Pointer to the cycle containing the row. */
    std::string sigla; /**< The course code. */
    std::string nombre; /**< The course name. */
    int grupo; /**< The course group. */
    std::string dia; /**< The day of the week. */
    int horaInicio; /**< The start time of the class. */
    int horaFinal; /**< The end time of the class. */
    int aula; /**< The classroom number. */
    int cupo; /**< The class capacity. */
    std::string profesor; /**< The teacher's name. */
    std::string departamento; /**< The department offering the course. */
    std::string observaciones; /**< Additional observations. */

    /**
     * @brief Constructs a Fila object.
     * @param ciclo Pointer to the cycle containing the row.
     * @param sigla The course code.
     * @param nombre The course name.
     * @param grupo The course group.
     * @param dia The day of the week.
     * @param horaInicio The start time of the class.
     * @param horaFinal The end time of the class.
     * @param aula The classroom number.
     * @param cupo The class capacity.
     * @param profesor The teacher's name.
     * @param departamento The department offering the course.
     * @param observaciones Additional observations.
     */
    Fila(Ciclo* ciclo, const std::string& sigla, const std::string& nombre, int grupo,
         const std::string& dia, int horaInicio, int horaFinal, int aula, int cupo,
         const std::string& profesor, const std::string& departamento, const std::string& observaciones);
};

/**
 * @class Horario
 * @brief Represents a schedule.
 */
class Horario {
public:
    std::vector<Fila> filas; /**< The rows in the schedule. */

    /**
     * @brief Adds a row to the schedule.
     * @param fila The row to be added.
     */
    void agregarFila(const Fila& fila);
};

#endif // FUN_H
