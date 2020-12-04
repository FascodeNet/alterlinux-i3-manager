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
#include "looks_page.h"

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

void _MainWindow::exit_()
{
  close();
}

void _MainWindow::restore_()
{
}

void _MainWindow::apply_()
{
  qDebug() <<"[debug] shape is "<< tab_looks_->GetSelectedShape_();
}
