/**
 * @file mainwindow.h
 * @brief This file contains the declaration of the MainWindow class.
 * @author Jorge Mora (jorgeadan.mora@ucr.ac.cr)
 * @version 0.1
 * @date 2023-06-25
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QMainWindow>
#include <QMap>
#include "fun/fun.h"
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class represents the main window of the schedule organizer application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow object.
     * @param parent The parent widget (default is nullptr).
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the MainWindow object.
     */
    ~MainWindow();

private slots:
    // Slots for button clicks
    void on_pushButtonSemesters_clicked();
    void on_pushButtonTeachers_clicked();
    void on_pushButtonExternalCourses_clicked();
    void on_pushButtonCycles_clicked();
    void on_pushButtonCourses_clicked();
    void on_pushButtonClassrooms_clicked();
    void on_pushButtonCurrentSchedule_clicked();
    void on_pushButton_HomeS_clicked();
    void on_pushButton_HomeT_clicked();
    void on_pushButton_HomeEC_clicked();
    void on_pushButton_HomeCy_clicked();
    void on_pushButton_HomeCo_clicked();
    void on_pushButton_HomeCl_clicked();
    void on_pushButton_HomeCu_clicked();


    // Other slots
    void connectButtons(const QString &tabName);
    void hideButtons();
    void addNewButton();
    void enterSelectionMode();
    void exitSelectionMode();
    void removeSelectedButtons();
    void duplicateSelectedButtons();
    void buttonClicked();
    QVBoxLayout* getCurrentLayout();
    QString getTabNameFromLayout(QVBoxLayout *layout);

    // Tab CurrentSchedule
    void on_addRow_CurrentSchedule_clicked();
    void on_lineEdit_textEdited_CurrentSchedule();
    void on_deleteSelectedRows_CurrentSchedule_clicked();
    void on_saveRow_CurrentSchedule_clicked();

    // Tab Courses
    void on_addRow_Courses_clicked();
    void on_comboBox_textEdited_CurrentSchedule();
    void on_lineEdit_textEdited_Courses();
    void on_deleteSelectedRows_Courses_clicked();
    void on_saveRow_Courses_clicked();

protected:
    /**
     * @brief Filters events that occur in the watched object.
     * @param watched The object that is being watched.
     * @param event The event that occurred.
     * @return True if the event was handled, False otherwise.
     */
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MainWindow *ui; /**< The user interface object. */
    QVBoxLayout *layout_Semesters; /**< The layout for the "Semesters" tab. */
    QVBoxLayout *layout_Teachers; /**< The layout for the "Teachers" tab. */
    QVBoxLayout *layout_ExternalCourses; /**< The layout for the "ExternalCourses" tab. */
    QVBoxLayout *layout_Cycles; /**< The layout for the "Cycles" tab. */
    QVBoxLayout *layout_Courses; /**< The layout for the "Courses" tab. */
    QVBoxLayout *layout_Classrooms; /**< The layout for the "Classrooms" tab. */
    bool isSelectionMode; /**< Flag indicating whether the selection mode is enabled or not. */


    QMap<QPushButton*, int> teacherIndices;
    QMap<QPushButton*, int> classroomIndices;


    std::vector<Classroom> classrooms; /**< Vector to store the classrooms. */
    std::vector<Teacher> teachers; /**< Vector to store the teachers. */
    std::vector<Curso> cursos; /**< Vector to store the courses. */
    std::vector<Fila> filas; /**< Vector to store the courses. */
};

#endif // MAINWINDOW_H
