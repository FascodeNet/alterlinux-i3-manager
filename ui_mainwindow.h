/********************************************************************************
** Form generated from reading UI file 'mainwindowzEEkSb.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWZEEKSB_H
#define MAINWINDOWZEEKSB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *polybar_config;
    QTabWidget *tabWidget;
    QWidget *theme_select;
    QWidget *gridLayoutWidget;
    QGridLayout *setting;
    QCheckBox *opaqueBar;
    QRadioButton *bar_bottom;
    QRadioButton *bar_top;
    QCheckBox *roundOff;
    QRadioButton *theme_light;
    QRadioButton *theme_dark;
    QRadioButton *colorful;
    QRadioButton *simple;
    QWidget *verticalLayoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *none;
    QLabel *sharprev;
    QLabel *round;
    QLabel *sharp;
    QRadioButton *select_none;
    QRadioButton *select_round;
    QRadioButton *select_sharp;
    QRadioButton *select_sharprev;
    QWidget *module;
    QLabel *label_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QCheckBox *mod_battery;
    QCheckBox *mod_clock;
    QCheckBox *mod_network;
    QCheckBox *mod_power;
    QCheckBox *mod_cpu;
    QCheckBox *mod_memory;
    QCheckBox *mod_i3status;
    QCheckBox *mod_launcher;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *exit_button;
    QPushButton *apply_button;
    QPushButton *pushButton;
    QButtonGroup *bar;
    QButtonGroup *theme;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(500, 450);
        MainWindow->setMinimumSize(QSize(500, 450));
        MainWindow->setMaximumSize(QSize(500, 450));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(500, 450));
        centralwidget->setMaximumSize(QSize(500, 450));
        polybar_config = new QLabel(centralwidget);
        polybar_config->setObjectName(QString::fromUtf8("polybar_config"));
        polybar_config->setGeometry(QRect(10, 10, 141, 31));
        QFont font;
        font.setPointSize(14);
        polybar_config->setFont(font);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 50, 481, 351));
        theme_select = new QWidget();
        theme_select->setObjectName(QString::fromUtf8("theme_select"));
        gridLayoutWidget = new QWidget(theme_select);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 175, 441, 101));
        setting = new QGridLayout(gridLayoutWidget);
        setting->setObjectName(QString::fromUtf8("setting"));
        setting->setContentsMargins(0, 0, 0, 0);
        opaqueBar = new QCheckBox(gridLayoutWidget);
        opaqueBar->setObjectName(QString::fromUtf8("opaqueBar"));

        setting->addWidget(opaqueBar, 0, 1, 1, 1);

        bar_bottom = new QRadioButton(gridLayoutWidget);
        bar = new QButtonGroup(MainWindow);
        bar->setObjectName(QString::fromUtf8("bar"));
        bar->addButton(bar_bottom);
        bar_bottom->setObjectName(QString::fromUtf8("bar_bottom"));

        setting->addWidget(bar_bottom, 3, 2, 1, 1);

        bar_top = new QRadioButton(gridLayoutWidget);
        bar->addButton(bar_top);
        bar_top->setObjectName(QString::fromUtf8("bar_top"));

        setting->addWidget(bar_top, 1, 2, 1, 1);

        roundOff = new QCheckBox(gridLayoutWidget);
        roundOff->setObjectName(QString::fromUtf8("roundOff"));

        setting->addWidget(roundOff, 0, 2, 1, 1);

        theme_light = new QRadioButton(gridLayoutWidget);
        theme = new QButtonGroup(MainWindow);
        theme->setObjectName(QString::fromUtf8("theme"));
        theme->addButton(theme_light);
        theme_light->setObjectName(QString::fromUtf8("theme_light"));

        setting->addWidget(theme_light, 3, 1, 1, 1);

        theme_dark = new QRadioButton(gridLayoutWidget);
        theme->addButton(theme_dark);
        theme_dark->setObjectName(QString::fromUtf8("theme_dark"));

        setting->addWidget(theme_dark, 1, 1, 1, 1);

        colorful = new QRadioButton(gridLayoutWidget);
        colorful->setObjectName(QString::fromUtf8("colorful"));

        setting->addWidget(colorful, 3, 3, 1, 1);

        simple = new QRadioButton(gridLayoutWidget);
        simple->setObjectName(QString::fromUtf8("simple"));

        setting->addWidget(simple, 1, 3, 1, 1);

        verticalLayoutWidget_2 = new QWidget(theme_select);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(80, 10, 321, 131));
        gridLayout = new QGridLayout(verticalLayoutWidget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        none = new QLabel(verticalLayoutWidget_2);
        none->setObjectName(QString::fromUtf8("none"));

        gridLayout->addWidget(none, 0, 1, 1, 1);

        sharprev = new QLabel(verticalLayoutWidget_2);
        sharprev->setObjectName(QString::fromUtf8("sharprev"));

        gridLayout->addWidget(sharprev, 3, 1, 1, 1);

        round = new QLabel(verticalLayoutWidget_2);
        round->setObjectName(QString::fromUtf8("round"));

        gridLayout->addWidget(round, 1, 1, 1, 1);

        sharp = new QLabel(verticalLayoutWidget_2);
        sharp->setObjectName(QString::fromUtf8("sharp"));

        gridLayout->addWidget(sharp, 2, 1, 1, 1);

        select_none = new QRadioButton(verticalLayoutWidget_2);
        select_none->setObjectName(QString::fromUtf8("select_none"));

        gridLayout->addWidget(select_none, 0, 0, 1, 1);

        select_round = new QRadioButton(verticalLayoutWidget_2);
        select_round->setObjectName(QString::fromUtf8("select_round"));

        gridLayout->addWidget(select_round, 1, 0, 1, 1);

        select_sharp = new QRadioButton(verticalLayoutWidget_2);
        select_sharp->setObjectName(QString::fromUtf8("select_sharp"));

        gridLayout->addWidget(select_sharp, 2, 0, 1, 1);

        select_sharprev = new QRadioButton(verticalLayoutWidget_2);
        select_sharprev->setObjectName(QString::fromUtf8("select_sharprev"));

        gridLayout->addWidget(select_sharprev, 3, 0, 1, 1);

        tabWidget->addTab(theme_select, QString());
        module = new QWidget();
        module->setObjectName(QString::fromUtf8("module"));
        label_2 = new QLabel(module);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 431, 21));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);
        gridLayoutWidget_2 = new QWidget(module);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 60, 401, 171));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        mod_battery = new QCheckBox(gridLayoutWidget_2);
        mod_battery->setObjectName(QString::fromUtf8("mod_battery"));
        QFont font2;
        font2.setPointSize(12);
        mod_battery->setFont(font2);

        gridLayout_2->addWidget(mod_battery, 4, 0, 1, 1);

        mod_clock = new QCheckBox(gridLayoutWidget_2);
        mod_clock->setObjectName(QString::fromUtf8("mod_clock"));
        mod_clock->setFont(font2);

        gridLayout_2->addWidget(mod_clock, 2, 0, 1, 1);

        mod_network = new QCheckBox(gridLayoutWidget_2);
        mod_network->setObjectName(QString::fromUtf8("mod_network"));
        mod_network->setFont(font2);

        gridLayout_2->addWidget(mod_network, 2, 1, 1, 1);

        mod_power = new QCheckBox(gridLayoutWidget_2);
        mod_power->setObjectName(QString::fromUtf8("mod_power"));
        mod_power->setFont(font2);

        gridLayout_2->addWidget(mod_power, 4, 1, 1, 1);

        mod_cpu = new QCheckBox(gridLayoutWidget_2);
        mod_cpu->setObjectName(QString::fromUtf8("mod_cpu"));
        mod_cpu->setFont(font2);

        gridLayout_2->addWidget(mod_cpu, 3, 0, 1, 1);

        mod_memory = new QCheckBox(gridLayoutWidget_2);
        mod_memory->setObjectName(QString::fromUtf8("mod_memory"));
        mod_memory->setFont(font2);

        gridLayout_2->addWidget(mod_memory, 3, 1, 1, 1);

        mod_i3status = new QCheckBox(gridLayoutWidget_2);
        mod_i3status->setObjectName(QString::fromUtf8("mod_i3status"));
        mod_i3status->setFont(font2);

        gridLayout_2->addWidget(mod_i3status, 1, 1, 1, 1);

        mod_launcher = new QCheckBox(gridLayoutWidget_2);
        mod_launcher->setObjectName(QString::fromUtf8("mod_launcher"));
        mod_launcher->setFont(font2);

        gridLayout_2->addWidget(mod_launcher, 1, 0, 1, 1);

        tabWidget->addTab(module, QString());
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(310, 410, 181, 36));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        exit_button = new QPushButton(horizontalLayoutWidget);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));

        horizontalLayout->addWidget(exit_button);

        apply_button = new QPushButton(horizontalLayoutWidget);
        apply_button->setObjectName(QString::fromUtf8("apply_button"));

        horizontalLayout->addWidget(apply_button);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 410, 121, 31));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "polybar-config", nullptr));
        polybar_config->setText(QCoreApplication::translate("MainWindow", "Polybar Config", nullptr));
        opaqueBar->setText(QCoreApplication::translate("MainWindow", "Opaque bar", nullptr));
        bar_bottom->setText(QCoreApplication::translate("MainWindow", "Bottom", nullptr));
        bar_top->setText(QCoreApplication::translate("MainWindow", "Top", nullptr));
        roundOff->setText(QCoreApplication::translate("MainWindow", "Round off the corners", nullptr));
        theme_light->setText(QCoreApplication::translate("MainWindow", "Light theme", nullptr));
        theme_dark->setText(QCoreApplication::translate("MainWindow", "Dark theme", nullptr));
        colorful->setText(QCoreApplication::translate("MainWindow", "Colorful", nullptr));
        simple->setText(QCoreApplication::translate("MainWindow", "Simple", nullptr));
        none->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        sharprev->setText(QCoreApplication::translate("MainWindow", "sharprev", nullptr));
        round->setText(QCoreApplication::translate("MainWindow", "round", nullptr));
        sharp->setText(QCoreApplication::translate("MainWindow", "sharp", nullptr));
        select_none->setText(QString());
        select_round->setText(QString());
        select_sharp->setText(QString());
        select_sharprev->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(theme_select), QCoreApplication::translate("MainWindow", "Theme", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Check the modules you want to display", nullptr));
        mod_battery->setText(QCoreApplication::translate("MainWindow", "Battery", nullptr));
        mod_clock->setText(QCoreApplication::translate("MainWindow", "Clock", nullptr));
        mod_network->setText(QCoreApplication::translate("MainWindow", "network status", nullptr));
        mod_power->setText(QCoreApplication::translate("MainWindow", "Power button", nullptr));
        mod_cpu->setText(QCoreApplication::translate("MainWindow", "CPU used", nullptr));
        mod_memory->setText(QCoreApplication::translate("MainWindow", "Memory used", nullptr));
        mod_i3status->setText(QCoreApplication::translate("MainWindow", "i3 status", nullptr));
        mod_launcher->setText(QCoreApplication::translate("MainWindow", "Launcher", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(module), QCoreApplication::translate("MainWindow", "Module", nullptr));
        exit_button->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        apply_button->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Default Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWZEEKSB_H
