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
  QButtonGroup* group_shape_;
  QRadioButton* shape_none_;
  QRadioButton* shape_round_;
  QRadioButton* shape_sharp_;
  QRadioButton* shape_sharp_rev_;
  // select theme color
  QButtonGroup* group_theme_color_;
  QRadioButton* theme_dark_;
  QRadioButton* theme_light_;
  // select icon color
  QButtonGroup* group_icon_color_;
  QRadioButton* icon_colorful_;
  QRadioButton* icon_simple_;
  // select bar position
  QButtonGroup* group_bar_position_;
  QRadioButton* bar_top_;
  QRadioButton* bar_bottom_;
  // other
  QCheckBox* translucent_bar_;
  QCheckBox* rounded_both_ends_;
  // function
  void LoadSettings_();

 public:
  _LooksPage(QWidget* parent = nullptr);
  QString SelectedShape_();
  QString ThemeColor_();
  QString IconColor_();
  QString BarPosition_();
  QString TranslucentBar_();
  bool    RoundedBothEnds_();
};

#endif