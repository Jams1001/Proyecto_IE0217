/**
 * @file gen.h
 * @brief This file contains the declaration of the Cursog class and some functions related to schedule generation.
 * @author Jorge Mora (jorgeadan.mora@ucr.ac.cr)
 * @version 0.1
 * @date 2023-07-05
 */

#ifndef GEN_H
#define GEN_H

#include <QList>
#include <QString>
#include <QStringList>
#include <QMap>
#include <QTextStream>
#include "fun.h"

/**
 * @class Cursog
 * @brief Class to represent a course with its corresponding attributes.
 * 
 * This class contains all the necessary details to represent a course.
 */
class Cursog {
public:
    QString ciclo; ///< Course term.
    QString sigla_curso; ///< Course code.
    int distribucion_dias_semanales; ///< Distribution of the weekdays on which the course is taught.
    int horas_totales_semanales; ///< Total weekly hours the course is taught.
    QStringList rango_externo_invalido; ///< External time range in which the course cannot be taught.
    QStringList rango_interno_invalido; ///< Internal time range in which the course cannot be taught.
    QList<int> aulas; ///< List of classrooms in which the course can be taught.
    int cantidad_grupos; ///< Number of course groups.

    /**
     * @brief Constructor for the Cursog class.
     * 
     * @param _ciclo Course term.
     * @param _sigla_curso Course code.
     * @param _distribucion_dias_semanales Distribution of weekdays.
     * @param _horas_totales_semanales Total weekly hours.
     * @param _rango_externo_invalido Invalid external time range.
     * @param _rango_interno_invalido Invalid internal time range.
     * @param _aulas List of classrooms.
     * @param _cantidad_grupos Number of groups.
     */
    Cursog(const QString& _ciclo, const QString& _sigla_curso, int _distribucion_dias_semanales,
        int _horas_totales_semanales, const QStringList& _rango_externo_invalido, 
        const QStringList& _rango_interno_invalido, const QList<int>& _aulas, int _cantidad_grupos);

    /**
     * @brief Generates a list of possible schedules for the course.
     * 
     * @return QList<QList<Horario>> List of lists of schedules.
     */
    QList<QList<Horario>> generarHorarios() const;

    /**
     * @brief Checks if a schedule is valid for the course.
     * 
     * @param horario Schedule to check.
     * @return bool True if the schedule is valid, false otherwise.
     */
    bool esHorarioValido(const Horario& horario) const;
};

/**
 * @brief Reads course information from a CSV file and creates a list of Cursog objects.
 * 
 * @param rutaArchivo Path of the CSV file.
 * @return QList<Cursog> List of Cursog objects.
 */
QList<Cursog> leerCursosDesdeCSV(const QString& rutaArchivo);

/**
 * @brief Generates CSV files for a list of courses.
 * 
 * @param cursos List of Cursog objects.
 */
void generarCSVsParaCursos(const QList<Cursog>& cursos);

#endif // GEN_H
