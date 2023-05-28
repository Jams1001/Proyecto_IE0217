#ifndef SEMESTERS_WINDOW_H
#define SEMESTERS_WINDOW_H

#include <QWidget>

namespace Ui {
class semesters_window;
}

class semesters_window : public QWidget
{
    Q_OBJECT

public:
    explicit semesters_window(QWidget *parent = nullptr);
    ~semesters_window();

private:
    Ui::semesters_window *ui;
};

#endif // SEMESTERS_WINDOW_H
