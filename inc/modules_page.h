// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// modules_page.h
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#ifndef ALTERLINUX_i3_MANAGER_MODULES_PAGE_H_
#define ALTERLINUX_i3_MANAGER_MODULES_PAGE_H_

#include <QtWidgets>

class _ModulesPage : public QWidget {
  Q_OBJECT
 private:
  // Checkboxes
  QCheckBox* box_launcher;
  QCheckBox* box_i3;
  QCheckBox* box_clock;
  QCheckBox* box_network;
  QCheckBox* box_cpu;
  QCheckBox* box_memory;
  QCheckBox* box_battery;
  QCheckBox* box_power;
  // function
  void LoadSettings_();

 public:
  _ModulesPage(QWidget* parent = nullptr);
  int  CheckBoxesStatus();
  void ResetAllState();
};

#endif