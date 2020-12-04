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

void ChangeLooksSetting(const _SettingList);

_MainWindow::_MainWindow(QWidget* parent) {
  // Layouts
  QVBoxLayout* layout    = new QVBoxLayout();
  QHBoxLayout* buttons   = new QHBoxLayout();
  // Widgets
  QWidget*     main_widget  = new QWidget();
  QTabWidget*  tab_widget   = new QTabWidget();
  QPushButton* button_exit  = new QPushButton(tr("Exit"));
  QPushButton* button_restore = new QPushButton(tr("Restore to default settings"));
  QPushButton* button_apply = new QPushButton(tr("Apply"));
  // Add pages to TabWidget
  tab_looks_   = new _LooksPage();
  tab_modules_ = new QWidget();
  tab_widget->addTab(tab_looks_,   tr("Looks"));
  tab_widget->addTab(tab_modules_, tr("Modules"));
  // Buttons init
  QObject::connect(button_exit, &QPushButton::clicked, this, &_MainWindow::exit_);
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
}

void ChangeLooksSetting(const _SettingList setting) {
  QString after_changes;
  // This is pairs of line number where need to change and string which after change.
  std::vector<std::tuple<int, QString>> changes;
  changes.resize(6);
  ///////////////////////////////////
  // Bar color
  after_changes = QString::asprintf(
    "include-file = ~/.config/polybar/colors/colors_%s%s.ini",
    setting.translucent_, setting.theme_color_
  );
  changes[0] = std::make_tuple(16, after_changes);
  ///////////////////////////////////
  // Icon color
  after_changes = QString::asprintf(
    "include-file = ~/.config/polybar/colors/icons/icons_%s%s.ini",
    setting.icon_color_, setting.theme_color_
  );
  changes[0] = std::make_tuple(17, after_changes);
  ///////////////////////////////////
  // Block shape
  after_changes = QString::asprintf(
    "include-file = ~/.config/polybar/blocks/blocks_%s%s.ini", setting.shape_
  );
  changes[0] = std::make_tuple(17, after_changes);
  ///////////////////////////////////
  // Bar position
  after_changes = QString::asprintf("bottom         = %s", setting.shape_);
  changes[0] = std::make_tuple(17, after_changes);
  ///////////////////////////////////
  // Rounded both ends of bar
  after_changes = QString::asprintf("radius%s", setting.rounded_);
  changes[0] = std::make_tuple(17, after_changes);
}
