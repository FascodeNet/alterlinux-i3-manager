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

_LooksPage::_LooksPage(QWidget* parent)
{
  // Layouts
  QVBoxLayout* layout       = new QVBoxLayout();
  QGridLayout* shape_select = new QGridLayout();
  QGridLayout* properties   = new QGridLayout();

  /* Block shape */
  // Create label and load picture
  QLabel* shape_none      = new QLabel();
  QLabel* shape_round     = new QLabel();
  QLabel* shape_sharp     = new QLabel();
  QLabel* shape_sharp_rev = new QLabel();
  /*shape_none     ->setPixmap(QPixmap("/usr/share/alterlinux-i3-manager/data/pic/polybar-none.png"));
  shape_round    ->setPixmap(QPixmap("/usr/share/alterlinux-i3-manager/data/pic/polybar-round.png"));
  shape_sharp    ->setPixmap(QPixmap("/usr/share/alterlinux-i3-manager/data/pic/polybar-sharp.png"));
  shape_sharp_rev->setPixmap(QPixmap("/usr/share/alterlinux-i3-manager/data/pic/polybar-sharprev.png"));*/
  shape_none     ->setPixmap(QPixmap("data/pic/polybar-none.png"));
  shape_round    ->setPixmap(QPixmap("data/pic/polybar-round.png"));
  shape_sharp    ->setPixmap(QPixmap("data/pic/polybar-sharp.png"));
  shape_sharp_rev->setPixmap(QPixmap("data/pic/polybar-sharprev.png"));
  // Checkbox
  checkbox_none_      = new QRadioButton();
  checkbox_round_     = new QRadioButton();
  checkbox_sharp_     = new QRadioButton();
  checkbox_sharp_rev_ = new QRadioButton();
  // add layout
  shape_select->addWidget(checkbox_none_,      0, 0, 1, 1, Qt::AlignRight);
  shape_select->addWidget(checkbox_round_,     1, 0, 1, 1, Qt::AlignRight);
  shape_select->addWidget(checkbox_sharp_,     2, 0, 1, 1, Qt::AlignRight);
  shape_select->addWidget(checkbox_sharp_rev_, 3, 0, 1, 1, Qt::AlignRight);
  shape_select->addWidget(shape_none,          0, 1);
  shape_select->addWidget(shape_round,         1, 1);
  shape_select->addWidget(shape_sharp,         2, 1);
  shape_select->addWidget(shape_sharp_rev,     3, 1);

  /* Other settings */

  layout->addLayout(shape_select);
  setLayout(layout);
}

QString _LooksPage::SelectedShape_()
{
}
