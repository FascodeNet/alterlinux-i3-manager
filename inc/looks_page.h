// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// looks_page.h
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#ifndef ALTERLINUX_i3_MANAGER_LOOKS_PAGE_H_
#define ALTERLINUX_i3_MANAGER_LOOKS_PAGE_H_

#include <QtWidgets>

class _LooksPage : public QWidget {
 private:
  // radiobutton for shape select
  QRadioButton* checkbox_none_;
  QRadioButton* checkbox_round_;
  QRadioButton* checkbox_sharp_;
  QRadioButton* checkbox_sharp_rev_;
 public:
  _LooksPage(QWidget* parent = nullptr);
  QString SelectedShape_();
};

#endif