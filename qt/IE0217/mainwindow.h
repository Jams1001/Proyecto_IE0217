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
    void on_pushButton_HomeS_clicked();
    void on_pushButton_HomeT_clicked();
    void on_pushButtonExternal_Courses_clicked();
    void on_pushButtonCycles_clicked();
    void on_pushButtonCourses_clicked();
    void on_pushButtonClassrooms_clicked();
    void on_pushButton_HomeEC_clicked();
    void on_pushButton_HomeCy_clicked();
    void on_pushButton_HomeCo_clicked();
    void on_pushButton_Cl_clicked();

    void addNewButton();
    void enterSelectionMode();
    void exitSelectionMode();
    void removeSelectedButtons();
    void duplicateSelectedButtons();
    void buttonClicked();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::MainWindow *ui;
    QLayout *layout1;
    bool isSelectionMode;
};
#endif // MAINWINDOW_H
