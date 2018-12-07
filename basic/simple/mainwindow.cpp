#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QAction>
#include <QSystemTrayIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->clickToQuitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);

    QIcon icon = QIcon(":/images/lighton80.png");
    setWindowIcon(icon);

    QAction* minimizeAction = new QAction(tr("Mi&nimize"), this);

    trayIcon = new QSystemTrayIcon(this);

    QMenu* trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addSeparator();

    trayIcon->setIcon(icon);
    trayIcon->setContextMenu(trayIconMenu);
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
    qDebug() << s << QSystemTrayIcon::isSystemTrayAvailable() << trayIcon->isVisible();
}

void MainWindow::on_addStuffButton_clicked()
{
    qDebug() << "adding stuff";
    Stuff* stuff = new Stuff();
    stuffs.append(stuff);
    //ui->simpleHorizontalLayout->addWidget(stuff);
    ui->simpleVerticalLayout->addWidget(stuff);
}
