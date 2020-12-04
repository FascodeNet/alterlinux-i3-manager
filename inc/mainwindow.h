// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// mainwindow.h
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#ifndef ALTERLINUX_i3_MANAGER_MAINWINDOW_H_
#define ALTERLINUX_i3_MANAGER_MAINWINDOW_H_

#include <tuple>
#include <vector>
#include <QtWidgets>
#include "looks_page.h"
#include "modules_page.h"
#include "setting_list.h"

// This is pairs of line number where need to change and string which after change.
typedef std::vector<std::tuple<int, QString>> ListOfChanges;

class _MainWindow : public QMainWindow {
 private:
  _LooksPage*   tab_looks_;
  _ModulesPage* tab_modules_;
  void closeEvent(QCloseEvent*);
 private slots:
  void exit_();
  void restore_();
  void apply_();
 public:
  _MainWindow(QWidget* parent = nullptr);
  void ChangeRofiSetting_(const _SettingList);
  void ChangePolybarSetting_(const _SettingList);
  void ChangeManagerSetting_(const _SettingList);
};

#endif