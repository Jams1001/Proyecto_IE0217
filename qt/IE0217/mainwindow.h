#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QVBoxLayout>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSemesters_clicked();
    void on_pushButtonTeachers_clicked();
    void on_pushButtonExternalCourses_clicked();
    void on_pushButtonCycles_clicked();
    void on_pushButtonCourses_clicked();
    void on_pushButtonClassrooms_clicked();
    void on_pushButton_HomeS_clicked();
    void on_pushButton_HomeT_clicked();
    void on_pushButton_HomeEC_clicked();
    void on_pushButton_HomeCy_clicked();
    void on_pushButton_HomeCo_clicked();
    void on_pushButton_HomeCl_clicked();

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

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MainWindow *ui;
    QVBoxLayout *layout_Semesters;
    QVBoxLayout *layout_Teachers;
    QVBoxLayout *layout_ExternalCourses;
    QVBoxLayout *layout_Cycles;
    QVBoxLayout *layout_Courses;
    QVBoxLayout *layout_Classrooms;
    bool isSelectionMode;
};
#endif // MAINWINDOW_H