#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include "semesters_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile styleFile("/home/jams/Jams/IS_2023/IE0217_Estructuras_abstractas/Proyecto_IE0217/IE0217/style.qss");
    styleFile.open(QFile::ReadOnly);
    QString style(styleFile.readAll());
    this->setStyleSheet(style);

    semestersWindow = new semesters_window(this); // Inicializamos semestersWindow

    // Conectamos la señal clicked() del botón pb_Semesters a la ranura showSemestersWindow
    connect(ui->pb_Semesters, &QPushButton::clicked, this, &MainWindow::showSemestersWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Implementamos la ranura showSemestersWindow
void MainWindow::showSemestersWindow() {
    semestersWindow->show(); // Mostramos semestersWindow
}
