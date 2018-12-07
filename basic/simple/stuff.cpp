#include "stuff.h"
#include "ui_stuff.h"

Stuff::Stuff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Stuff)
{
    ui->setupUi(this);
}

Stuff::~Stuff()
{
    delete ui;
}
