#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exit_button_clicked();

    void on_apply_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void loadSettings();
    void updateSettings();
    void updateThemes();
    void updateModules();
    void setDefaultSettings();
};
#endif // MAINWINDOW_H
