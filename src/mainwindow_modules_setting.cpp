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
  QString after_changes;
  ListOfChanges changes;
  changes.resize(3);
  {
    bool launcher, i3, clock, network, cpu, memory, battery, power;
    {
      int num = tab_modules_->CheckBoxesStatus();
      if (num >= 128) {power    = true; num -= 128;}
      if (num >=  64) {battery  = true; num -=  64;}
      if (num >=  32) {memory   = true; num -=  32;}
      if (num >=  16) {cpu      = true; num -=  16;}
      if (num >=   8) {network  = true; num -=   8;}
      if (num >=   4) {clock    = true; num -=   4;}
      if (num >=   2) {i3       = true; num -=   2;}
      if (num >=   1) {launcher = true; num -=   1;}
    }
    bool added=false;
    // Left
    QString left   = "modules-left   = ";
    if (launcher) { left += "launcher "; added = true; }
    if (i3)       { left += "i3 ";       added = true; }
    if (added) left += "left-end";
    // Center
    QString center = "modules-center = ";
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

    changes[0] = std::make_tuple(39, left);
    changes[1] = std::make_tuple(40, center);
    changes[2] = std::make_tuple(41, right);
  }

  /* WritePolybarSettingToConfigFile */
  // 本来関数分けするつもりでしたが、ListOfChangesの値をうまく渡せず統合しました
  {
    QFile file(QDir::homePath()+"/.config/polybar/config.ini");
    if(!file.open(QIODevice::ReadOnly))
    {
      QMessageBox::warning(this, tr("error"), tr("Cannot open the Polybar config file: ")+file.errorString());
      return;
    }
    QTextStream stream(&file);
    QString out;
    int i=1;
    bool edited = false;
    // Read from file
    while (!stream.atEnd()) {
      edited = false;
      // 変更が要求されている行に達したら、変更内容を適用する
      for (int j = 0; j < changes.size(); j++)
        if (std::get<0>(changes[j]) == i) {
          edited = true;
          out += std::get<1>(changes[j]);
          stream.readLine();
          break;
        }
      // 変更が要求されている行でなければ、そのまま読み込み
      if (!edited)
        out += stream.readLine();
      out += '\n';
      i++;
    }
    file.close();
    // Write to file
    if (!file.open(QIODevice::WriteOnly))
    {
      QMessageBox::warning(this, tr("error"), tr("Cannot open the Polybar config file: ") + file.errorString());
      return;
    }
    QTextStream outstream(&file);
    outstream<<out;
    file.close();
  }
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
