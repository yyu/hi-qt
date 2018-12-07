#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QSystemTrayIcon>
#include <QtGui>

#include <QAction>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>


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

    QComboBox* iconComboBox;
    QAction* minimizeAction;
    QMenu* trayIconMenu;
    QSystemTrayIcon* trayIcon;
};

#endif // MAINWINDOW_H
