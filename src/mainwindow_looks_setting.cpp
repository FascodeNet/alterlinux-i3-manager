// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// mainwindow_looks_setting.cpp
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#include "mainwindow.h"
#include <tuple>
#include <vector>
#include <QtWidgets>
#include "setting_list.h"
#include "looks_page.h"
#include "edit_file_specific_line.h"

void _MainWindow::ChangeRofiSetting_(const _SettingList setting) {
  QFile file(QDir::homePath()+"/.config/rofi/config");
  if(!file.open(QIODevice::ReadOnly))
  {
    QMessageBox::warning( this, tr("error"),tr("Cannot open the Rofi config file: ")+file.errorString() );
    return;
  }
  QTextStream stream(&file);
  QString out;
  QString theme=QString::asprintf(
    "rofi.theme      : ~/.config/rofi/alter-%s.rasi",
    setting.theme_color_.toUtf8().constData()
  );
  int i=1;
  // Read from file
  while(!stream.atEnd()) {
    if (i == 16) {
      out += theme+'\n';
      stream.readLine();
      i++;
    }
    out += stream.readLine()+'\n';
    i++;
  }
  file.close();
  // Write to file
  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::warning( this, tr("error"),tr("Cannot open the Rofi config file: ")+file.errorString() );
    return;
  }
  QTextStream outstream(&file);
  outstream<<out;
  file.close();
}

void _MainWindow::ChangePolybarSetting_(const _SettingList setting) {
  const QString file_path = QDir::homePath()+"/.config/polybar/config.ini";
  QString after_changes;
  int status = 0;
  ///////////////////////////////////
  // Bar color
  after_changes = QString::asprintf(
    "include-file = ~/.config/polybar/colors/colors_%s%s.ini",
    setting.translucent_.toUtf8().constData(), setting.theme_color_.toUtf8().constData()
  );
  status += EditFileSpecificLine(16, after_changes, file_path);
  ///////////////////////////////////
  // Icon color
  after_changes = QString::asprintf(
    "include-file = ~/.config/polybar/colors/icons/icons_%s%s.ini",
    setting.icon_color_.toUtf8().constData(), setting.theme_color_.toUtf8().constData()
  );
  status += EditFileSpecificLine(17, after_changes, file_path);
  ///////////////////////////////////
  // Block shape
  after_changes = QString::asprintf(
    "include-file = ~/.config/polybar/blocks/blocks_%s.ini",
    setting.shape_.toUtf8().constData()
  );
  status += EditFileSpecificLine(18, after_changes, file_path);
  ///////////////////////////////////
  // Bar position
  after_changes = QString::asprintf(
    "bottom         = %s",
    setting.bar_position_.toUtf8().constData()
  );
  status += EditFileSpecificLine(32, after_changes, file_path);
  ///////////////////////////////////
  // Rounded both ends of bar
  after_changes = QString::asprintf(
    "radius%s",
    setting.rounded_.toUtf8().constData()
  );
  status += EditFileSpecificLine(34, after_changes, file_path);
  if (status != 5)
    QMessageBox::warning(this, tr("error"), tr("Cannot open the Polybar config file"));
  system("i3-msg restart");
}

void _MainWindow::ChangeManagersPolybarSetting_(const _SettingList setting) {
  QString out="";
  // Block shape
  if      (setting.shape_ == "sharprev") out += "3\n";
  else if (setting.shape_ == "sharp")    out += "2\n";
  else if (setting.shape_ == "round")    out += "1\n";
  else                                   out += "0\n";
  //Color theme
  if (setting.theme_color_ == "light") out += "1\n";
  else                                 out += "0\n";
  // Icon Color
  if (setting.icon_color_ == "colorful_") out += "1\n";
  else                                    out += "0\n";
  // Bar position
  if (setting.bar_position_ == "true") out += "1\n";
  else                                 out += "0\n";
  // Translucent
  if (setting.translucent_ == "clear_") out += "1\n";
  else                                  out += "0\n";
  // Rounded bar
  if (setting.rounded_ == "         = 0") out += "0\n";
  else                                    out += "1\n";
  // Write to file
  CreateManagerConfigDirectory();
  QFile file(QDir::homePath() + "/.config/alterlinux-i3-manager/polybar.conf");
  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::warning(this, tr("error"),tr("Cannot open this setting manager config file: ")+file.errorString() );
    return;
  } else {
    QTextStream stream(&file);
    stream << out;
  }
}
