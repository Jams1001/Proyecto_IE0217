#include <QApplication>
#include <QPushButton>
#include <QDebug>

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QPushButton button ("Hello, World!");
    QObject::connect(&button, &QPushButton::clicked, [&]() {
        qDebug() << "Button clicked!";
    });
    button.show();

    return app.exec();
}
