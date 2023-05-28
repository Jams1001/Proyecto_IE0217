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

    semesters_window *semestersWindow = new semesters_window(this);
    connect(ui->pb_Semesters, &QPushButton::clicked, [=]() {
        semestersWindow->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
