#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_exit_button_clicked()
{
    int ans = QMessageBox::question(this, tr("Warning"), tr("Changes will be discarded.\nAre you sure to exit?"));
    if(ans == QMessageBox::Yes) exit(0);
}
