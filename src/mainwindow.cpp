// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// mainwindow.cpp
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

_MainWindow::_MainWindow(QWidget* parent) {
  // Layouts
  QVBoxLayout* layout    = new QVBoxLayout();
  QHBoxLayout* buttons   = new QHBoxLayout();
  // Widgets
  QWidget*     main_widget    = new QWidget();
  QTabWidget*  tab_widget     = new QTabWidget();
  QPushButton* button_exit    = new QPushButton(tr("Exit"));
  QPushButton* button_restore = new QPushButton(tr("Restore to default settings"));
  QPushButton* button_apply   = new QPushButton(tr("Apply"));
  // Add pages to TabWidget
  tab_looks_   = new _LooksPage();
  tab_modules_ = new QWidget();
  tab_widget->addTab(tab_looks_,   tr("Looks"));
  tab_widget->addTab(tab_modules_, tr("Modules"));
  // Buttons init
  QObject::connect(button_exit,    &QPushButton::clicked, this, &_MainWindow::exit_);
  QObject::connect(button_restore, &QPushButton::clicked, this, &_MainWindow::restore_);
  QObject::connect(button_apply,   &QPushButton::clicked, this, &_MainWindow::apply_);
  buttons->addWidget(button_exit);
  buttons->addWidget(button_restore);
  buttons->addStretch();
  buttons->addWidget(button_apply);
  // Add widgets to layout
  QLabel* header = new QLabel(tr("Settings manager for Alter Linux i3wm edition "));
  header->setStyleSheet("font-size:20px;");
  layout->addWidget(header);
  layout->addWidget(tab_widget);
  layout->addLayout(buttons);
  // Add layout to MainWidget
  main_widget->setLayout(layout);
  setCentralWidget(main_widget);
  setFixedSize(500, 450);
}

void _MainWindow::closeEvent(QCloseEvent* event)
{
  int ans = QMessageBox::question(this, tr("Warning"), tr("Changes will be discarded.\nAre you sure to exit?"));
  if(ans == QMessageBox::No) event->ignore();
}

void _MainWindow::exit_() {
  close();
}

void _MainWindow::restore_() {
  int ans = QMessageBox::question(this, tr("Warning"), tr("Changes will be discarded.\nAre you sure to exit?"));
  if(ans == QMessageBox::No) return;
}

void _MainWindow::apply_() {
  _SettingList list;
  list.shape_        = tab_looks_->SelectedShape_();
  list.theme_color_  = tab_looks_->ThemeColor_();
  list.icon_color_   = tab_looks_->IconColor_();
  list.bar_position_ = tab_looks_->BarPosition_();
  list.translucent_  = tab_looks_->TranslucentBar_();
  bool rounded = tab_looks_->RoundedBothEnds_();
  if (rounded == true) {
    // when bar is on the bottom
    if(list.bar_position_ == "true")
      list.rounded_ = "-top     = 15.0";
    // when bar is on the top
    if(list.bar_position_ == "false")
      list.rounded_ = "-bottom  = 15.0";
  } else
      list.rounded_ = "         = 0";
  ChangeRofiSetting_(list);
  ChangePolybarSetting_(list);
}

void _MainWindow::ChangeRofiSetting_(const _SettingList setting) {
  QFile file(QDir::homePath()+"/.config/rofi/config");
  if(!file.open(QIODevice::ReadOnly))
  {
    QMessageBox::warning( this, tr("error"),tr("Rofi setting file cannnot open: ")+file.errorString() );
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
      QMessageBox::warning( this, tr("error"),tr("Rofi setting file cannnot open: ")+file.errorString() );
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

  /* WritePolybarSettingToConfigFile */
  // 本来関数分けするつもりでしたが、ListOfChangesの値をうまく渡せず統合しました
  QFile file(QDir::homePath()+"/.config/polybar/config.ini");
  if(!file.open(QIODevice::ReadOnly))
  {
    QMessageBox::warning(this, tr("error"), tr("File cannnot open: ")+file.errorString());
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
    QMessageBox::warning(this, tr("error"), tr("File cannnot open: ") + file.errorString());
    return;
    }
    QTextStream outstream(&file);
    outstream<<out;
    file.close();
    system("i3-msg restart");
}
