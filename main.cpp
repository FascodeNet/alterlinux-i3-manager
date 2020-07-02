#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    QString locale( QLocale::system().name() );
    if(locale == QString("ja_JP"))
    {
        translator.load("/usr/share/alterlinux-i3-theme-settingmanager/alterlinux-i3-theme-settingmanager_ja_JP");
        a.installTranslator(&translator);
    }

    MainWindow w;
    w.show();
    return a.exec();
}
