// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// setting_list.h
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#ifndef ALTERLINUX_i3_MANAGER_SETTING_LIST_H_
#define ALTERLINUX_i3_MANAGER_SETTING_LIST_H_

#include <QtWidgets>

typedef struct {
  QString shape_;
  QString theme_color_;
  QString icon_color_;
  QString bar_position_;
  QString translucent_;
  QString rounded_;
}_SettingList;

#endif