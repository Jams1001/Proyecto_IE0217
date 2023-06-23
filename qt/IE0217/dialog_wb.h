#ifndef DIALOG_WB_H
#define DIALOG_WB_H

#include <QDialog>

namespace Ui {
class dialog_wb;
}

class dialog_wb : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_wb(QWidget *parent = nullptr);
    QString getButtonName() const;
    ~dialog_wb();

private:
    Ui::dialog_wb *ui;
};

#endif // DIALOG_WB_H
