#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QSystemTrayIcon>
#include <QMainWindow>
#include "stuff.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_qDebugButton_clicked();

    void on_addStuffButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Stuff*> stuffs;

    QSystemTrayIcon* trayIcon;
};

#endif // MAINWINDOW_H
