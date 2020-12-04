// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// mainwindow.cpp
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#include "looks_page.h"
#include <QtWidgets>

_LooksPage::_LooksPage(QWidget* parent) {
  // Layouts
  QVBoxLayout* layout       = new QVBoxLayout();
  QGridLayout* shape_select = new QGridLayout();
  QHBoxLayout* checkboxes   = new QHBoxLayout();
  QGridLayout* properties   = new QGridLayout();

  /* Block shape */
  // Create label and load picture
  QLabel* thumbnail_none      = new QLabel();
  QLabel* thumbnail_round     = new QLabel();
  QLabel* thumbnail_sharp     = new QLabel();
  QLabel* thumbnail_sharp_rev = new QLabel();
  /*thumbnail_none   ->setPixmap(QPixmap("/usr/share/alterlinux-i3-manager/data/pic/polybar-none.png"));
  thumbnail_round    ->setPixmap(QPixmap("/usr/share/alterlinux-i3-manager/data/pic/polybar-round.png"));
  thumbnail_sharp    ->setPixmap(QPixmap("/usr/share/alterlinux-i3-manager/data/pic/polybar-sharp.png"));
  thumbnail_sharp_rev->setPixmap(QPixmap("/usr/share/alterlinux-i3-manager/data/pic/polybar-sharprev.png"));*/
  thumbnail_none     ->setPixmap(QPixmap("data/pic/polybar-none.png"));
  thumbnail_round    ->setPixmap(QPixmap("data/pic/polybar-round.png"));
  thumbnail_sharp    ->setPixmap(QPixmap("data/pic/polybar-sharp.png"));
  thumbnail_sharp_rev->setPixmap(QPixmap("data/pic/polybar-sharprev.png"));
  // Checkbox
  shape_none_      = new QRadioButton();
  shape_round_     = new QRadioButton();
  shape_sharp_     = new QRadioButton();
  shape_sharp_rev_ = new QRadioButton();
  // Add to layout
  shape_select->addWidget(shape_none_,      0, 0, 1, 1, Qt::AlignRight);
  shape_select->addWidget(shape_round_,     1, 0, 1, 1, Qt::AlignRight);
  shape_select->addWidget(shape_sharp_,     2, 0, 1, 1, Qt::AlignRight);
  shape_select->addWidget(shape_sharp_rev_, 3, 0, 1, 1, Qt::AlignRight);
  shape_select->addWidget(thumbnail_none,      0, 1);
  shape_select->addWidget(thumbnail_round,     1, 1);
  shape_select->addWidget(thumbnail_sharp,     2, 1);
  shape_select->addWidget(thumbnail_sharp_rev, 3, 1);

  /* Other settings */
  // Init widgets
  theme_dark_    = new QRadioButton();
  theme_light_   = new QRadioButton();
  icon_simple_   = new QRadioButton();
  icon_colorful_ = new QRadioButton();
  bar_top_       = new QRadioButton();
  bar_bottom_    = new QRadioButton();
  // Set text
  theme_dark_   ->setText(tr("Dark"));
  theme_light_  ->setText(tr("Light"));
  icon_simple_  ->setText(tr("Simple"));
  icon_colorful_->setText(tr("Colorful"));
  bar_top_      ->setText(tr("Top"));
  bar_bottom_   ->setText(tr("Bottom"));
  // Add to group
  group_theme_color_ = new QButtonGroup;
  group_theme_color_->addButton(theme_dark_);
  group_theme_color_->addButton(theme_light_);
  group_icon_color_ = new QButtonGroup;
  group_icon_color_->addButton(icon_simple_);
  group_icon_color_->addButton(icon_colorful_);
  group_bar_position_ = new QButtonGroup;
  group_bar_position_->addButton(bar_top_);
  group_bar_position_->addButton(bar_bottom_);
  // Add to layout
  properties->addWidget(new QLabel(tr("Theme color")) , 0, 0);
  properties->addWidget(new QLabel(tr("Icon color"))  , 0, 1);
  properties->addWidget(new QLabel(tr("Bar position")), 0, 2);
  properties->addWidget(theme_dark_ , 1, 0);
  properties->addWidget(icon_simple_, 1, 1);
  properties->addWidget(bar_top_    , 1, 2);
  properties->addWidget(theme_light_  , 2, 0);
  properties->addWidget(icon_colorful_, 2, 1);
  properties->addWidget(bar_bottom_   , 2, 2);

  /* Checkboxes */
  // Init
  translucent_bar_   = new QCheckBox();
  rounded_both_ends_ = new QCheckBox();
  // Set Text
  translucent_bar_  ->setText(tr("Use translucent bar"));
  rounded_both_ends_->setText(tr("Round both ends of bar"));
  // Add to layout
  checkboxes->addWidget(translucent_bar_);
  checkboxes->addWidget(rounded_both_ends_);

  shape_select->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
  checkboxes->setAlignment(Qt::AlignBottom);
  properties->setAlignment(Qt::AlignBottom);
  layout->addLayout(shape_select);
  layout->addLayout(checkboxes);
  layout->addLayout(properties);
  setLayout(layout);
}

QString _LooksPage::SelectedShape_() {
  return "";
}
