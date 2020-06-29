#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //デフォルト設定
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
