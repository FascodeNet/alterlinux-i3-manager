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
#include <QtWidgets>

_MainWindow::_MainWindow(QWidget* parent)
{
  // Layouts
  QVBoxLayout* layout    = new QVBoxLayout();
  QHBoxLayout* buttons   = new QHBoxLayout();
  // Widgets
  QWidget*     main_widget  = new QWidget();
  QTabWidget*  tab_widget   = new QTabWidget();
  QPushButton* button_exit  = new QPushButton(tr("Exit"));
  QPushButton* button_reset = new QPushButton(tr("Restore to default settings"));
  QPushButton* button_apply = new QPushButton(tr("Apply"));
  // Add pages to TabWidget
  QWidget *tab_looks   = new QWidget();
  QWidget *tab_modules = new QWidget();
  tab_widget->addTab(tab_looks,   tr("Looks"));
  tab_widget->addTab(tab_modules, tr("Modules"));
  // Add widgets to layout
  buttons->addWidget(button_exit);
  buttons->addWidget(button_reset);
  buttons->addStretch();
  buttons->addWidget(button_apply);
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