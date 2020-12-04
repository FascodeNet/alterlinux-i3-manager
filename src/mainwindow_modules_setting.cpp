// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// mainwindow_modules_setting.cpp
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#include "mainwindow.h"
#include <QtWidgets>

void _MainWindow::ChangeModulesSetting_() {
}

void _MainWindow::ChangeManagersModulesSetting_(const _SettingList setting) {
  // Write to file
  CreateManagerConfigDirectory();
  QFile file(QDir::homePath() + "/.config/alterlinux-i3-manager/modules.conf");
  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::warning(this, tr("error"),tr("Cannot open this setting manager config file: ")+file.errorString() );
    return;
  } else {
    QTextStream stream(&file);
    stream << QString(tab_modules_->CheckBoxesStatus());
  }
}
