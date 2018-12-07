#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->clickToQuitButton, &QPushButton::clicked, QApplication::instance(), &QApplication::quit);
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
}

void MainWindow::on_addStuffButton_clicked()
{
    qDebug() << "adding stuff";
    Stuff* stuff = new Stuff();
    stuffs.append(stuff);
    //ui->simpleHorizontalLayout->addWidget(stuff);
    ui->simpleVerticalLayout->addWidget(stuff);
}
