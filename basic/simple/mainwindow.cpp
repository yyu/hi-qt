#include "ui_mainwindow.h"
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

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->clickToQuitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

    iconComboBox = new QComboBox;
    iconComboBox->addItem(QIcon(":/images/bad.png"), tr("Bad"));

    minimizeAction = new QAction(tr("Mi&nimize"), this);
    trayIconMenu = new QMenu(this);
    trayIcon = new QSystemTrayIcon(this);

    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addSeparator();

    QIcon icon = iconComboBox->itemIcon(0);
    setWindowIcon(icon);

    trayIcon->setIcon(icon);
    trayIcon->setToolTip(iconComboBox->itemText(0));
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setVisible(true);
    trayIcon->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_qDebugButton_clicked()
{
    static int i = 0;
    char s[1024];
    sprintf(s, "\033[32mthe button was clicked\033[1G %d\033[0m", i++);
    qDebug() << s;
    qDebug() << QSystemTrayIcon::isSystemTrayAvailable();
    qDebug() << trayIcon->isVisible();
}

void MainWindow::on_addStuffButton_clicked()
{
    qDebug() << "adding stuff";
    Stuff* stuff = new Stuff();
    stuffs.append(stuff);
    //ui->simpleHorizontalLayout->addWidget(stuff);
    ui->simpleVerticalLayout->addWidget(stuff);
}
