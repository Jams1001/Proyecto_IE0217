/**
 * @file mainwindow.h
 * @brief This file contains the declaration of the MainWindow class.
 * @author Jorge Mora (jorgeadan.mora@ucr.ac.cr)
 * @version 0.1
 * @date 2023-07-05
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QMainWindow>
#include <QMap>
#include "fun/fun.h"
#include "fun/gen.h"
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

    QMap<QPushButton*, int> teacherIndices; /**< Map to store the indices of the teachers. */
    QMap<QPushButton*, int> classroomIndices; /**< Map to store the indices of the classrooms. */

    std::vector<Classroom> classrooms; /**< Vector to store the classrooms. */
    std::vector<Teacher> teachers; /**< Vector to store the teachers. */
    std::vector<Curso> cursos; /**< Vector to store the courses. */
    std::vector<Fila> filas; /**< Vector to store the rows. */

private slots:
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButtonSemesters_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButtonTeachers_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButtonExternalCourses_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButtonCycles_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButtonCourses_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButtonClassrooms_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButtonCurrentSchedule_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButtonScheduleGenerator_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButton_HomeS_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButton_HomeT_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButton_HomeEC_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButton_HomeCy_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButton_HomeCo_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButton_HomeCl_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButton_HomeCu_clicked();
    /**
     * @brief Handle button clicks for tabs navegation.
     */
    void on_pushButton_HomeSG_clicked();

    /**
     * @brief Connects buttons to their respective handlers based on the tab name.
     *
     * @param tabName A string representing the name of the tab where the buttons to be connected are located.
     */
    void connectButtons(const QString &tabName);

    /**
     * @brief To hide buttons depending on the configuration
     */
    void hideButtons();

    /**
     * @brief To add new button in a tab.
     */
    void addNewButton();

    /**
     * @brief To enter selection mode.
     */
    void enterSelectionMode();

    /**
     * @brief To exit selection mode.
     */
    void exitSelectionMode();

    /**
     * @brief To remove buttons selected.
     */
    void removeSelectedButtons();

    /**
     * @brief To duplicate buttons selected.
     */
    void duplicateSelectedButtons();

    /**
     * @brief To edit buttons selected in selection mode
     */
    void buttonClicked();

    /**
     * @brief Return the current layout.
     * @return A pointer to the QVBoxLayout representing the current layout.
     */
    QVBoxLayout* getCurrentLayout();
    
    /**
     * @brief Return the name of the tab from the given layout.
     * @param layout A pointer to the QVBoxLayout from which to get the tab name.
     * @return The name of the tab as a QString.
     */
    QString getTabNameFromLayout(QVBoxLayout *layout);

    /**
     * @brief  To add new row in CurrentSchedul tab.
     */
    void addRowToCurrentSchedule();

    /**
     * @brief To note that the row was edited in CurrentSchedul tab.
     */
    void editTextInCurrentSchedule();

    /**
     * @brief To delete the row selected in CurrentSchedul tab.
     */
    void deleteSelectedRowsInCurrentSchedule();

    /**
     * @brief To save the row edited in CurrentSchedul tab.
     */
    void saveRowInCurrentSchedule();

    /**
     * @brief To edit a cell in cell in Current schedule tab.
     */
    void editComboBoxTextInCurrentSchedule();

    /**
     * @brief To add new row in Courses tab.
     */
    void addRowToCourses();

    /**
     * @brief To note that the row was edited in Courses tab.
     */
    void editTextInCourses();

    /**
     * @brief To delete the row selected in Courses tab.
     */
    void deleteSelectedRowsInCourses();

    /**
     * @brief To save the row edited in Courses tab.
     */
    void saveRowInCourses();

    /**
     * @brief Update course options in a cell on cycle or department change..
     * @param index The index at which the change occurred.
     */
    void updateCourseOptionsOnCycleOrDepartmentChange(int index);

    /**
     * @brief Update course options in a cell on sigla or name change.
     * @param index The index at which the change occurred.
     */
    void updateCourseOptionsOnSiglaOrNameChange(int index);

    /**
     * @brief Handle the addition of a CSV in the schedule generator.
     */
    void on_pushButtonAddCSV_ScheduleGenerator_clicked();
};

#endif // MAINWINDOW_H
