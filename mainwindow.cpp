#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDir>

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
    ui->mod_i3status->setChecked(true);
    ui->mod_clock   ->setChecked(true);
    ui->mod_network ->setChecked(true);
    ui->mod_cpu     ->setChecked(true);
    ui->mod_memory  ->setChecked(true);
    ui->mod_battery ->setChecked(true);
    ui->mod_power   ->setChecked(true);
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

void MainWindow::updateThemes()
{
    //テーマ
    QString theme;
    if(ui->theme_dark ->isChecked()) theme="dark";
    if(ui->theme_light->isChecked()) theme="light";
    //バー色 (line 16)
    QString color="include-file = ~/.config/polybar/colors/colors_";
    if(ui->opaqueBar->isChecked()) color+="clear_";
    else color+="unclear_";
    color += theme+".ini";
    //アイコン色 (line 17)
    QString icon="include-file  = ~/.config/polybar/colors/icons/icons_";
    if(ui->colorful->isChecked()) icon+="colorful_";
    if(ui->simple  ->isChecked()) icon+="simple_";
    icon += theme+".ini";
    //ブロックの形 (line 18)
    QString block="include-file = ~/.config/polybar/blocks/blocks_";
    if(ui->select_none    ->isChecked()) block+="none";
    if(ui->select_round   ->isChecked()) block+="round";
    if(ui->select_sharp   ->isChecked()) block+="sharp";
    if(ui->select_sharprev->isChecked()) block+="sharprev";
    block += ".ini";
    //バーをしたにするかどうか (line 32
    QString bar;
    if(ui->bar_bottom->isChecked())bar="bottom         = true";
    else bar="bottom         = false";
    //角丸めるかどうか (line 34)
    QString radius;
    if(ui->roundOff->isChecked()) radius="radius-bottom  = 15.0";
    else radius="radius-bottom  = 0";

    //config.iniに以上の設定を書き込む
    QFile file(QDir::homePath()+"/.config/polybar/config.ini");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning( this, tr("error"),tr("File cannnot open:")+file.errorString() );
        return;
    }
    QTextStream stream(&file);
    QString out;
    int i=1;
    while(!stream.atEnd())
    {
        switch(i)
        {
            case 16: out+=color ; stream.readLine(); break;
            case 17: out+=icon  ; stream.readLine(); break;
            case 18: out+=block ; stream.readLine(); break;
            case 32: out+=bar   ; stream.readLine(); break;
            case 34: out+=radius; stream.readLine(); break;
            default: out+=        stream.readLine(); break;
        }
        out+='\n';
        i++;
    }
    file.close();
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning( this, tr("error"),tr("File cannnot open: ")+file.errorString() );
        return;
    }
    QTextStream outstream(&file);
    outstream<<out;
    QMessageBox::information(this, tr("finish"), tr("Completed!\nThe changes will be applied when i3wm is reloaded."));
}

void MainWindow::updateModules()
{
    //left (line 39)
    QString left   = "modules-left   = ";  //i3 left-end
    if(ui->mod_i3status->isChecked()) left+="i3 left-end";
    //center (line 40)
    QString center = "modules-center = ";  //left-begin clock right-end
    if(ui->mod_clock->isChecked()) center+="left-begin clock right-end";
    //right (line 41)
    QString right  = "modules-right  = ";  //right-begin network cpu memory battery right-end right-begin power
    bool alreadyAdd=false;
    if(ui->mod_network->isChecked())
    {
        if(!alreadyAdd) right+="right-begin";
        right+=" network";
        alreadyAdd=true;
    }
    if(ui->mod_cpu->isChecked())
    {
        if(!alreadyAdd) right+="right-begin";
        right+=" cpu";
        alreadyAdd=true;
    }
    if(ui->mod_memory->isChecked())
    {
        if(!alreadyAdd) right+="right-begin";
        right+=" memory";
        alreadyAdd=true;
    }
    if(ui->mod_battery->isChecked())
    {
        if(!alreadyAdd) right+="right-begin";
        right+=" battery";
        alreadyAdd=true;
    }
    if(alreadyAdd) right+=" right-end ";
    if(ui->mod_power->isChecked()) right+="right-begin power";

    //config.iniに以上の設定を書き込む
    QFile file(QDir::homePath()+"/.config/polybar/config.ini");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning( this, tr("error"),tr("File cannnot open: ")+file.errorString() );
        return;
    }
    QTextStream stream(&file);
    QString out;
    int i=1;
    while(!stream.atEnd())
    {
        switch(i)
        {
            case 39: out+=left  ; stream.readLine(); break;
            case 40: out+=center; stream.readLine(); break;
            case 41: out+=right ; stream.readLine(); break;
            default: out+=        stream.readLine(); break;
        }
        out+='\n';
        i++;
    }
    file.close();
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning( this, tr("error"),tr("File cannnot open:")+file.errorString() );
        return;
    }
    QTextStream outstream(&file);
    outstream<<out;
    QMessageBox::information(this, tr("finish"), tr("Completed!\nThe changes will be applied when i3wm is reloaded."));
}

void MainWindow::on_apply_button_clicked()
{
    if(ui->tabWidget->currentIndex() == 0)
        updateThemes();
    else updateModules();
}



void MainWindow::on_exit_button_clicked()
{
    int ans = QMessageBox::question(this, tr("Warning"), tr("Changes will be discarded.\nAre you sure to exit?"));
    if(ans == QMessageBox::Yes) exit(0);
}
