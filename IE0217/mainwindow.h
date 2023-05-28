#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "semesters_window.h"

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
    void showSemestersWindow();

private:
    Ui::MainWindow *ui;
    semesters_window *semestersWindow; // Agregamos un puntero a semesters_window
};
#endif // MAINWINDOW_H
