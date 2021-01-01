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
#include "edit_file_specific_line.h"

void _MainWindow::ChangeModulesSetting_() {
  const QString file_path = QDir::homePath()+"/.config/polybar/config.ini";
  QString after_changes;
  bool launcher=false, i3=false, clock=false;
  bool network=false, cpu=false, memory=false, battery=false, power=false;
  {
    int num = tab_modules_->CheckBoxesStatus();
    qDebug() << "num=" << num;
    if (num >= 128) {power    = true; num -= 128;}
    qDebug() << "pow=" << power;
    if (num >=  64) {battery  = true; num -=  64;}
    qDebug() << "bat=" << battery;
    if (num >=  32) {memory   = true; num -=  32;}
    qDebug() << "mem=" << memory;
    if (num >=  16) {cpu      = true; num -=  16;}
    qDebug() << "cpu=" << cpu;
    if (num >=   8) {network  = true; num -=   8;}
    qDebug() << "net=" << network;
    if (num >=   4) {clock    = true; num -=   4;}
    qDebug() << "clo=" << clock;
    if (num >=   2) {i3       = true; num -=   2;}
    qDebug() << "i3 =" << i3;
    if (num >=   1) {launcher = true; num -=   1;}
    qDebug() << "lau=" << launcher;
  }
  bool added=false;
  // Left
  QString left   = "modules-left   = ";
  if (launcher) { left += "launcher "; added = true; }
  if (i3)       { left += "i3 ";       added = true; }
  if (added) left += "left-end";
  // Center
  QString center = "modules-center =";
  if (clock) center += " left-begin clock right-end";
  // Right
  added = false;
  QString right  = "modules-right  = ";
  if(network) {
    if(!added) right+="right-begin";
    right+=" network";
    added=true;
  }
  if(cpu) {
    if(!added) right+="right-begin";
    right+=" cpu";
    added=true;
  }
  if(memory) {
    if(!added) right+="right-begin";
    right+=" memory";
    added=true;
  }
  if(battery) {
    if(!added) right+="right-begin";
    right+=" battery";
    added=true;
  }
  if(added) right+=" right-end";
  if(power) right+=" right-begin power";

  if (!EditFileSpecificLine(39, left,   file_path) || !EditFileSpecificLine(40, center, file_path) || !EditFileSpecificLine(41, right,  file_path))
    QMessageBox::warning(this, tr("error"), tr("Cannot open the Polybar config file"));
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
    stream << tab_modules_->CheckBoxesStatus();
  }
}
