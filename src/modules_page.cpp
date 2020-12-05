// alterlinux-i3-manager - A i3wm setting manager for Alter Linux
// mainwindow.cpp
//
// Watasuke
// Email  : <watasuke102@gmail.com>
// Twitter: @Watasuke102
//
// (c) 2020 Fascode Network.
// This software is released under the GPL-3.0 License.

#include "modules_page.h"
#include <QtWidgets>

_ModulesPage::_ModulesPage(QWidget* parent) {
  // Layouts
  QVBoxLayout* layout     = new QVBoxLayout();
  QGridLayout* checkboxes = new QGridLayout();
  // Init checkboxes
  box_launcher = new QCheckBox();
  box_i3       = new QCheckBox();
  box_clock    = new QCheckBox();
  box_network  = new QCheckBox();
  box_cpu      = new QCheckBox();
  box_memory   = new QCheckBox();
  box_battery  = new QCheckBox();
  box_power    = new QCheckBox();
  // Set text
  box_launcher->setText(tr("Launcher"));
  box_i3      ->setText(tr("i3 status"));
  box_clock   ->setText(tr("Clock"));
  box_network ->setText(tr("Wi-Fi SSID"));
  box_cpu     ->setText(tr("CPU used"));
  box_memory  ->setText(tr("Memory used"));
  box_battery ->setText(tr("Battery"));
  box_power   ->setText(tr("Power button"));
  // Set style
  QString style = "font-size:16px;";
  box_launcher->setStyleSheet(style);
  box_i3      ->setStyleSheet(style);
  box_clock   ->setStyleSheet(style);
  box_network ->setStyleSheet(style);
  box_cpu     ->setStyleSheet(style);
  box_memory  ->setStyleSheet(style);
  box_battery ->setStyleSheet(style);
  box_power   ->setStyleSheet(style);
  // Add checkbox to grid
  checkboxes->addWidget(box_launcher, 0, 0);
  checkboxes->addWidget(box_i3      , 0, 1);
  checkboxes->addWidget(box_clock   , 1, 0);
  checkboxes->addWidget(box_network , 1, 1);
  checkboxes->addWidget(box_cpu     , 2, 0);
  checkboxes->addWidget(box_memory  , 2, 1);
  checkboxes->addWidget(box_battery , 3, 0);
  checkboxes->addWidget(box_power   , 3, 1);
  // Add widgets to layout
  layout->addWidget(new QLabel(tr("Check the modules you want to display")), 0, Qt::AlignTop);
  layout->addLayout(checkboxes);
  setLayout(layout);

  LoadSettings_();
}

void _ModulesPage::LoadSettings_() {
  //Open setting file
  QFile file(QDir::homePath()+"/.config/alterlinux-i3-manager/modules.conf");
  if (!file.open(QIODevice::ReadOnly)) {
    ResetAllState();
    return;
  }
  QTextStream stream(&file);
  int num=stream.readLine().toInt();
  if (num >= 128) {box_power   ->setChecked(true); num -= 128;}
  if (num >=  64) {box_battery ->setChecked(true); num -=  64;}
  if (num >=  32) {box_memory  ->setChecked(true); num -=  32;}
  if (num >=  16) {box_cpu     ->setChecked(true); num -=  16;}
  if (num >=   8) {box_network ->setChecked(true); num -=   8;}
  if (num >=   4) {box_clock   ->setChecked(true); num -=   4;}
  if (num >=   2) {box_i3      ->setChecked(true); num -=   2;}
  if (num >=   1) {box_launcher->setChecked(true); num -=   1;}
  file.close();
}

int _ModulesPage::CheckBoxesStatus() {
  int num = 0;
  if (box_power   ->isChecked()) num += 128;
  if (box_battery ->isChecked()) num +=  64;
  if (box_memory  ->isChecked()) num +=  32;
  if (box_cpu     ->isChecked()) num +=  16;
  if (box_network ->isChecked()) num +=   8;
  if (box_clock   ->isChecked()) num +=   4;
  if (box_i3      ->isChecked()) num +=   2;
  if (box_launcher->isChecked()) num +=   1;
  return num;
}

void _ModulesPage::ResetAllState() {
  box_launcher->setChecked(true);
  box_i3      ->setChecked(true);
  box_clock   ->setChecked(true);
  box_network ->setChecked(true);
  box_cpu     ->setChecked(true);
  box_memory  ->setChecked(true);
  box_battery ->setChecked(true);
  box_power   ->setChecked(true);
}
