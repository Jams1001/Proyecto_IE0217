#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVBoxLayout *layout1 = new QVBoxLayout;
    ui->scrollAreaWidgetContents->setLayout(layout1);
    QVBoxLayout *layout2 = new QVBoxLayout;
    ui->Semesters->setLayout(layout2);
    connect(ui->pushButtonAdd_Semesters, &QPushButton::clicked, this, &MainWindow::addNewButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonSemesters_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_pushButtonTeachers_clicked(){ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_pushButton_HomeS_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeT_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButtonExternal_Courses_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_pushButtonCycles_clicked(){ui->stackedWidget->setCurrentIndex(4);}
void MainWindow::on_pushButtonCourses_clicked(){ui->stackedWidget->setCurrentIndex(5);}
void MainWindow::on_pushButtonClassrooms_clicked(){ui->stackedWidget->setCurrentIndex(6);}
void MainWindow::on_pushButton_HomeEC_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCy_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_HomeCo_clicked(){ui->stackedWidget->setCurrentIndex(0);}
void MainWindow::on_pushButton_Cl_clicked(){ui->stackedWidget->setCurrentIndex(0);}

void MainWindow::addNewButton()
{
    QPushButton *newButton = new QPushButton(this);
    newButton->setText("Semester 1");

    QLayout *layout = ui->scrollAreaWidgetContents->layout();
    if (layout) {
        layout->addWidget(newButton);
    }

    this->update();
}
