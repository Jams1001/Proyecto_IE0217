/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Home;
    QLabel *label_10;
    QPushButton *pushButtonSchedule_Generator;
    QPushButton *pushButtonCurrent_Schedule;
    QPushButton *pushButtonClassrooms;
    QPushButton *pushButtonSemesters;
    QPushButton *pushButton_Home;
    QPushButton *pushButtonCycles;
    QLabel *label_9;
    QPushButton *pushButtonCourses;
    QPushButton *pushButtonExternal_Courses;
    QPushButton *pushButtonTeachers;
    QWidget *Semesters;
    QPushButton *pushButtonAdd_Semesters;
    QPushButton *pushButtonSelectSemesters;
    QPushButton *pushButton_HomeS;
    QPushButton *pushButton_Semesters;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *Teachers;
    QPushButton *pushButtonSelect_Teachers;
    QPushButton *pushButtonAdd_Teachers;
    QPushButton *pushButton_Teachers;
    QPushButton *pushButton_HomeT;
    QWidget *External_Courses;
    QPushButton *pushButton_HomeEC;
    QPushButton *pushButton_External_Courses;
    QPushButton *pushButtonAdd_External_Courses;
    QPushButton *pushButtonSelect_External_Courses;
    QWidget *Cycles;
    QPushButton *pushButton_Cycles;
    QPushButton *pushButton_HomeCy;
    QPushButton *pushButtonSelect_Cycles;
    QPushButton *pushButtonAdd_Cycles;
    QWidget *Courses;
    QPushButton *pushButton_Courses;
    QPushButton *pushButton_HomeCo;
    QPushButton *pushButtonSelect_Courses;
    QPushButton *pushButtonAdd_Courses;
    QWidget *Classrooms;
    QPushButton *pushButtonSelect_Classrooms;
    QPushButton *pushButtonAdd_Classrooms;
    QPushButton *pushButton_HomeCl;
    QPushButton *pushButton_Cl;
    QWidget *Home_f;
    QGridLayout *gridLayout_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(787, 573);
        QFont font;
        font.setFamily(QString::fromUtf8("Umpush"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 781, 511));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMaximumSize(QSize(781, 511));
        Home = new QWidget();
        Home->setObjectName(QString::fromUtf8("Home"));
        label_10 = new QLabel(Home);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(30, 90, 211, 51));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMaximumSize(QSize(211, 51));
        label_10->setFont(font);
        pushButtonSchedule_Generator = new QPushButton(Home);
        pushButtonSchedule_Generator->setObjectName(QString::fromUtf8("pushButtonSchedule_Generator"));
        pushButtonSchedule_Generator->setGeometry(QRect(540, 350, 161, 51));
        sizePolicy.setHeightForWidth(pushButtonSchedule_Generator->sizePolicy().hasHeightForWidth());
        pushButtonSchedule_Generator->setSizePolicy(sizePolicy);
        pushButtonSchedule_Generator->setMaximumSize(QSize(161, 51));
        pushButtonCurrent_Schedule = new QPushButton(Home);
        pushButtonCurrent_Schedule->setObjectName(QString::fromUtf8("pushButtonCurrent_Schedule"));
        pushButtonCurrent_Schedule->setGeometry(QRect(30, 190, 161, 51));
        sizePolicy.setHeightForWidth(pushButtonCurrent_Schedule->sizePolicy().hasHeightForWidth());
        pushButtonCurrent_Schedule->setSizePolicy(sizePolicy);
        pushButtonCurrent_Schedule->setMaximumSize(QSize(161, 51));
        pushButtonClassrooms = new QPushButton(Home);
        pushButtonClassrooms->setObjectName(QString::fromUtf8("pushButtonClassrooms"));
        pushButtonClassrooms->setGeometry(QRect(540, 290, 161, 51));
        sizePolicy.setHeightForWidth(pushButtonClassrooms->sizePolicy().hasHeightForWidth());
        pushButtonClassrooms->setSizePolicy(sizePolicy);
        pushButtonClassrooms->setMaximumSize(QSize(161, 51));
        pushButtonSemesters = new QPushButton(Home);
        pushButtonSemesters->setObjectName(QString::fromUtf8("pushButtonSemesters"));
        pushButtonSemesters->setGeometry(QRect(30, 250, 161, 51));
        sizePolicy.setHeightForWidth(pushButtonSemesters->sizePolicy().hasHeightForWidth());
        pushButtonSemesters->setSizePolicy(sizePolicy);
        pushButtonSemesters->setMaximumSize(QSize(161, 51));
        pushButton_Home = new QPushButton(Home);
        pushButton_Home->setObjectName(QString::fromUtf8("pushButton_Home"));
        pushButton_Home->setGeometry(QRect(30, 10, 89, 25));
        sizePolicy.setHeightForWidth(pushButton_Home->sizePolicy().hasHeightForWidth());
        pushButton_Home->setSizePolicy(sizePolicy);
        pushButton_Home->setMaximumSize(QSize(89, 25));
        pushButtonCycles = new QPushButton(Home);
        pushButtonCycles->setObjectName(QString::fromUtf8("pushButtonCycles"));
        pushButtonCycles->setGeometry(QRect(540, 170, 161, 51));
        sizePolicy.setHeightForWidth(pushButtonCycles->sizePolicy().hasHeightForWidth());
        pushButtonCycles->setSizePolicy(sizePolicy);
        pushButtonCycles->setMaximumSize(QSize(161, 51));
        label_9 = new QLabel(Home);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 50, 211, 41));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMaximumSize(QSize(211, 41));
        label_9->setFont(font);
        pushButtonCourses = new QPushButton(Home);
        pushButtonCourses->setObjectName(QString::fromUtf8("pushButtonCourses"));
        pushButtonCourses->setGeometry(QRect(540, 230, 161, 51));
        sizePolicy.setHeightForWidth(pushButtonCourses->sizePolicy().hasHeightForWidth());
        pushButtonCourses->setSizePolicy(sizePolicy);
        pushButtonCourses->setMaximumSize(QSize(161, 51));
        pushButtonExternal_Courses = new QPushButton(Home);
        pushButtonExternal_Courses->setObjectName(QString::fromUtf8("pushButtonExternal_Courses"));
        pushButtonExternal_Courses->setGeometry(QRect(540, 110, 161, 51));
        sizePolicy.setHeightForWidth(pushButtonExternal_Courses->sizePolicy().hasHeightForWidth());
        pushButtonExternal_Courses->setSizePolicy(sizePolicy);
        pushButtonExternal_Courses->setMaximumSize(QSize(161, 51));
        pushButtonTeachers = new QPushButton(Home);
        pushButtonTeachers->setObjectName(QString::fromUtf8("pushButtonTeachers"));
        pushButtonTeachers->setGeometry(QRect(540, 50, 161, 51));
        sizePolicy.setHeightForWidth(pushButtonTeachers->sizePolicy().hasHeightForWidth());
        pushButtonTeachers->setSizePolicy(sizePolicy);
        pushButtonTeachers->setMaximumSize(QSize(161, 51));
        stackedWidget->addWidget(Home);
        Semesters = new QWidget();
        Semesters->setObjectName(QString::fromUtf8("Semesters"));
        pushButtonAdd_Semesters = new QPushButton(Semesters);
        pushButtonAdd_Semesters->setObjectName(QString::fromUtf8("pushButtonAdd_Semesters"));
        pushButtonAdd_Semesters->setGeometry(QRect(490, 450, 121, 41));
        pushButtonSelectSemesters = new QPushButton(Semesters);
        pushButtonSelectSemesters->setObjectName(QString::fromUtf8("pushButtonSelectSemesters"));
        pushButtonSelectSemesters->setGeometry(QRect(640, 450, 121, 41));
        pushButton_HomeS = new QPushButton(Semesters);
        pushButton_HomeS->setObjectName(QString::fromUtf8("pushButton_HomeS"));
        pushButton_HomeS->setGeometry(QRect(20, 10, 89, 25));
        pushButton_Semesters = new QPushButton(Semesters);
        pushButton_Semesters->setObjectName(QString::fromUtf8("pushButton_Semesters"));
        pushButton_Semesters->setGeometry(QRect(110, 10, 89, 25));
        scrollArea = new QScrollArea(Semesters);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 50, 761, 381));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 759, 379));
        scrollArea->setWidget(scrollAreaWidgetContents);
        stackedWidget->addWidget(Semesters);
        Teachers = new QWidget();
        Teachers->setObjectName(QString::fromUtf8("Teachers"));
        pushButtonSelect_Teachers = new QPushButton(Teachers);
        pushButtonSelect_Teachers->setObjectName(QString::fromUtf8("pushButtonSelect_Teachers"));
        pushButtonSelect_Teachers->setGeometry(QRect(640, 450, 121, 41));
        pushButtonAdd_Teachers = new QPushButton(Teachers);
        pushButtonAdd_Teachers->setObjectName(QString::fromUtf8("pushButtonAdd_Teachers"));
        pushButtonAdd_Teachers->setGeometry(QRect(490, 450, 121, 41));
        pushButton_Teachers = new QPushButton(Teachers);
        pushButton_Teachers->setObjectName(QString::fromUtf8("pushButton_Teachers"));
        pushButton_Teachers->setGeometry(QRect(110, 10, 89, 25));
        pushButton_HomeT = new QPushButton(Teachers);
        pushButton_HomeT->setObjectName(QString::fromUtf8("pushButton_HomeT"));
        pushButton_HomeT->setGeometry(QRect(20, 10, 89, 25));
        stackedWidget->addWidget(Teachers);
        External_Courses = new QWidget();
        External_Courses->setObjectName(QString::fromUtf8("External_Courses"));
        pushButton_HomeEC = new QPushButton(External_Courses);
        pushButton_HomeEC->setObjectName(QString::fromUtf8("pushButton_HomeEC"));
        pushButton_HomeEC->setGeometry(QRect(20, 10, 89, 25));
        pushButton_External_Courses = new QPushButton(External_Courses);
        pushButton_External_Courses->setObjectName(QString::fromUtf8("pushButton_External_Courses"));
        pushButton_External_Courses->setGeometry(QRect(110, 10, 141, 25));
        pushButtonAdd_External_Courses = new QPushButton(External_Courses);
        pushButtonAdd_External_Courses->setObjectName(QString::fromUtf8("pushButtonAdd_External_Courses"));
        pushButtonAdd_External_Courses->setGeometry(QRect(490, 450, 121, 41));
        pushButtonSelect_External_Courses = new QPushButton(External_Courses);
        pushButtonSelect_External_Courses->setObjectName(QString::fromUtf8("pushButtonSelect_External_Courses"));
        pushButtonSelect_External_Courses->setGeometry(QRect(640, 450, 121, 41));
        stackedWidget->addWidget(External_Courses);
        Cycles = new QWidget();
        Cycles->setObjectName(QString::fromUtf8("Cycles"));
        pushButton_Cycles = new QPushButton(Cycles);
        pushButton_Cycles->setObjectName(QString::fromUtf8("pushButton_Cycles"));
        pushButton_Cycles->setGeometry(QRect(110, 10, 91, 25));
        pushButton_HomeCy = new QPushButton(Cycles);
        pushButton_HomeCy->setObjectName(QString::fromUtf8("pushButton_HomeCy"));
        pushButton_HomeCy->setGeometry(QRect(20, 10, 89, 25));
        pushButtonSelect_Cycles = new QPushButton(Cycles);
        pushButtonSelect_Cycles->setObjectName(QString::fromUtf8("pushButtonSelect_Cycles"));
        pushButtonSelect_Cycles->setGeometry(QRect(640, 450, 121, 41));
        pushButtonAdd_Cycles = new QPushButton(Cycles);
        pushButtonAdd_Cycles->setObjectName(QString::fromUtf8("pushButtonAdd_Cycles"));
        pushButtonAdd_Cycles->setGeometry(QRect(490, 450, 121, 41));
        stackedWidget->addWidget(Cycles);
        Courses = new QWidget();
        Courses->setObjectName(QString::fromUtf8("Courses"));
        pushButton_Courses = new QPushButton(Courses);
        pushButton_Courses->setObjectName(QString::fromUtf8("pushButton_Courses"));
        pushButton_Courses->setGeometry(QRect(110, 10, 91, 25));
        pushButton_HomeCo = new QPushButton(Courses);
        pushButton_HomeCo->setObjectName(QString::fromUtf8("pushButton_HomeCo"));
        pushButton_HomeCo->setGeometry(QRect(20, 10, 89, 25));
        pushButtonSelect_Courses = new QPushButton(Courses);
        pushButtonSelect_Courses->setObjectName(QString::fromUtf8("pushButtonSelect_Courses"));
        pushButtonSelect_Courses->setGeometry(QRect(640, 450, 121, 41));
        pushButtonAdd_Courses = new QPushButton(Courses);
        pushButtonAdd_Courses->setObjectName(QString::fromUtf8("pushButtonAdd_Courses"));
        pushButtonAdd_Courses->setGeometry(QRect(490, 450, 121, 41));
        stackedWidget->addWidget(Courses);
        Classrooms = new QWidget();
        Classrooms->setObjectName(QString::fromUtf8("Classrooms"));
        pushButtonSelect_Classrooms = new QPushButton(Classrooms);
        pushButtonSelect_Classrooms->setObjectName(QString::fromUtf8("pushButtonSelect_Classrooms"));
        pushButtonSelect_Classrooms->setGeometry(QRect(640, 450, 121, 41));
        pushButtonAdd_Classrooms = new QPushButton(Classrooms);
        pushButtonAdd_Classrooms->setObjectName(QString::fromUtf8("pushButtonAdd_Classrooms"));
        pushButtonAdd_Classrooms->setGeometry(QRect(490, 450, 121, 41));
        pushButton_HomeCl = new QPushButton(Classrooms);
        pushButton_HomeCl->setObjectName(QString::fromUtf8("pushButton_HomeCl"));
        pushButton_HomeCl->setGeometry(QRect(110, 10, 91, 25));
        pushButton_Cl = new QPushButton(Classrooms);
        pushButton_Cl->setObjectName(QString::fromUtf8("pushButton_Cl"));
        pushButton_Cl->setGeometry(QRect(20, 10, 89, 25));
        stackedWidget->addWidget(Classrooms);
        Home_f = new QWidget();
        Home_f->setObjectName(QString::fromUtf8("Home_f"));
        gridLayout_2 = new QGridLayout(Home_f);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stackedWidget->addWidget(Home_f);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 787, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Escuela de Ingenier\303\255a El\303\251ctrica", nullptr));
        pushButtonSchedule_Generator->setText(QApplication::translate("MainWindow", "Schedule Generator", nullptr));
        pushButtonCurrent_Schedule->setText(QApplication::translate("MainWindow", "Current Schedule", nullptr));
        pushButtonClassrooms->setText(QApplication::translate("MainWindow", "Classrooms", nullptr));
        pushButtonSemesters->setText(QApplication::translate("MainWindow", "Semesters", nullptr));
        pushButton_Home->setText(QApplication::translate("MainWindow", "Home", nullptr));
        pushButtonCycles->setText(QApplication::translate("MainWindow", "Cycles", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Universidad de Costa Rica", nullptr));
        pushButtonCourses->setText(QApplication::translate("MainWindow", "Courses", nullptr));
        pushButtonExternal_Courses->setText(QApplication::translate("MainWindow", "External Courses", nullptr));
        pushButtonTeachers->setText(QApplication::translate("MainWindow", "Teachers", nullptr));
        pushButtonAdd_Semesters->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushButtonSelectSemesters->setText(QApplication::translate("MainWindow", "Select", nullptr));
        pushButton_HomeS->setText(QApplication::translate("MainWindow", "Home", nullptr));
        pushButton_Semesters->setText(QApplication::translate("MainWindow", "Semesters", nullptr));
        pushButtonSelect_Teachers->setText(QApplication::translate("MainWindow", "Select", nullptr));
        pushButtonAdd_Teachers->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushButton_Teachers->setText(QApplication::translate("MainWindow", "Teachers", nullptr));
        pushButton_HomeT->setText(QApplication::translate("MainWindow", "Home", nullptr));
        pushButton_HomeEC->setText(QApplication::translate("MainWindow", "Home", nullptr));
        pushButton_External_Courses->setText(QApplication::translate("MainWindow", "External Courses", nullptr));
        pushButtonAdd_External_Courses->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushButtonSelect_External_Courses->setText(QApplication::translate("MainWindow", "Select", nullptr));
        pushButton_Cycles->setText(QApplication::translate("MainWindow", "Cycles", nullptr));
        pushButton_HomeCy->setText(QApplication::translate("MainWindow", "Home", nullptr));
        pushButtonSelect_Cycles->setText(QApplication::translate("MainWindow", "Select", nullptr));
        pushButtonAdd_Cycles->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushButton_Courses->setText(QApplication::translate("MainWindow", "Courses", nullptr));
        pushButton_HomeCo->setText(QApplication::translate("MainWindow", "Home", nullptr));
        pushButtonSelect_Courses->setText(QApplication::translate("MainWindow", "Select", nullptr));
        pushButtonAdd_Courses->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushButtonSelect_Classrooms->setText(QApplication::translate("MainWindow", "Select", nullptr));
        pushButtonAdd_Classrooms->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushButton_HomeCl->setText(QApplication::translate("MainWindow", "Classrooms", nullptr));
        pushButton_Cl->setText(QApplication::translate("MainWindow", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
