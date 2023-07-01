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
    std::string ciclo; /**< the cycle to which the course belongs. */
    std::string sigla; /**< The course code. */
    std::string nombre; /**< The course name. */
    std::string departamento; /**< The department offering the course. */

    /**
     * @brief Constructs a Curso object.
     * @param ciclo The cycle to which the course belongs.
     * @param sigla The course code.
     * @param nombre The course name.
     * @param departamento The department offering the course.
     */
    Curso(const std::string& ciclo, const std::string& sigla, const std::string& nombre, const std::string& departamento);
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
    std::string ciclo; /**< The cycle to which the course belongs. */
    std::string sigla; /**< The course code. */
    std::string nombrecurso; /**< The course name. */
    std::string grupo; /**< The course group. */
    std::string dia; /**< The day of the week. */
    std::string horainicio; /**< The start time of the class. */
    std::string horafinal; /**< The end time of the class. */
    std::string aula; /**< The classroom number. */
    std::string cupo; /**< The class capacity. */
    std::string profesor; /**< The teacher's name. */
    std::string departamento; /**< The department offering the course. */
    std::string observaciones; /**< Additional observations. */

    /**
     * @brief Constructs a Fila object.
     * @param ciclo The cycle to which the course belongs.
     * @param sigla The course code.
     * @param nombrecurso The course name.
     * @param grupo The course group.
     * @param dia The day of the week.
     * @param horainicio The start time of the class.
     * @param horafinal The end time of the class.
     * @param aula The classroom number.
     * @param cupo The class capacity.
     * @param profesor The teacher's name.
     * @param departamento The department offering the course.
     * @param observaciones Additional observations.
     */
    Fila(const std::string& ciclo, const std::string& sigla, const std::string& nombrecurso, const std::string& grupo,
         const std::string& dia, const std::string& horainicio, const std::string& horafinal, const std::string& aula, const std::string& cupo,
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
