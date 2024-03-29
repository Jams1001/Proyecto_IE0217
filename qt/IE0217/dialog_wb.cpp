#include "dialog_wb.h"
#include "ui_dialog_wb.h"

dialog_wb::dialog_wb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_wb)
{
    ui->setupUi(this);
}

dialog_wb::~dialog_wb()
{
    delete ui;
}

QString dialog_wb::getButtonName() const {
    return ui->lineEdit->text();
}
