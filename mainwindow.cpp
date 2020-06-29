#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //テーマのデフォルト設定
    ui->select_none->setChecked(true);
    ui->theme_dark ->setChecked(true);
    ui->simple     ->setChecked(true);
    ui->bar_top    ->setChecked(true);
    //モジュールのデフォルト設定
    //画像読み込み
    ui->none    ->setPixmap(QPixmap("./pic/polybar-none.png"    ));
    ui->round   ->setPixmap(QPixmap("./pic/polybar-round.png"   ));
    ui->sharp   ->setPixmap(QPixmap("./pic/polybar-sharp.png"   ));
    ui->sharprev->setPixmap(QPixmap("./pic/polybar-sharprev.png"));
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
