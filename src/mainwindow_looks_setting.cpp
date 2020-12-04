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
    setting.theme_color_
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
  QString after_changes;
  ListOfChanges changes;
  changes.resize(5);
  {
    ///////////////////////////////////
    // Bar color
    after_changes = QString::asprintf(
      "include-file = ~/.config/polybar/colors/colors_%s%s.ini",
      setting.translucent_.toUtf8().constData(), setting.theme_color_.toUtf8().constData()
    );
    changes[0] = std::make_tuple(16, after_changes);
    ///////////////////////////////////
    // Icon color
    after_changes = QString::asprintf(
      "include-file = ~/.config/polybar/colors/icons/icons_%s%s.ini",
      setting.icon_color_.toUtf8().constData(), setting.theme_color_.toUtf8().constData()
    );
    changes[1] = std::make_tuple(17, after_changes);
    ///////////////////////////////////
    // Block shape
    after_changes = QString::asprintf(
      "include-file = ~/.config/polybar/blocks/blocks_%s.ini",
      setting.shape_.toUtf8().constData()
    );
    changes[2] = std::make_tuple(18, after_changes);
    ///////////////////////////////////
    // Bar position
    after_changes = QString::asprintf(
      "bottom         = %s",
      setting.bar_position_.toUtf8().constData()
    );
    changes[3] = std::make_tuple(32, after_changes);
    ///////////////////////////////////
    // Rounded both ends of bar
    after_changes = QString::asprintf(
      "radius%s",
      setting.rounded_.toUtf8().constData()
    );
    changes[4] = std::make_tuple(34, after_changes);
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
      for (int j = 0; j < 5; j++)
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
  system("i3-msg restart");
}

void _MainWindow::ChangeManagerSetting_(const _SettingList setting) {
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
  // Create directory
  QDir config_file_dir(QDir::homePath() + "/.config");
  if (!config_file_dir.exists("alterlinux-i3-manager")) config_file_dir.mkdir("alterlinux-i3-manager");
  // Write to file
  QFile file(QDir::homePath() + "/.config/alterlinux-i3-manager/polybar.conf");
  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::warning(this, tr("error"),tr("Cannot open this setting manager config file: ")+file.errorString() );
    return;
  } else {
    QTextStream stream(&file);
    stream << out;
  }
}
