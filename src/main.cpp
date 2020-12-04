// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// main.cpp
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#include <QtWidgets>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QTranslator translator;
  QString locale( QLocale::system().name() );
  if(locale == QString("ja_JP"))
  {
    translator.load("/usr/share/alterlinux-i3-manager/alterlinux-i3-manager_ja");
    a.installTranslator(&translator);
  }
  _MainWindow w;
  w.show();
  return a.exec();
}