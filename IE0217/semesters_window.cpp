#include "semesters_window.h"
#include "ui_semesters_window.h"

semesters_window::semesters_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::semesters_window)
{
    ui->setupUi(this);
}

semesters_window::~semesters_window()
{
    delete ui;
}
