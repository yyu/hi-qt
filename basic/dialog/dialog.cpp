#include "dialog.h"

#include <QtGui>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QSystemTrayIcon>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    QIcon icon = QIcon(":/images/table-light-black.png");
    setWindowIcon(icon);

    QAction* hideAction = new QAction(tr("&Hide"), this);
    QAction* showAction = new QAction(tr("&Show"), this);
    QAction* quitAction = new QAction(tr("&Quit"), this);
    connect(hideAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect(showAction, SIGNAL(triggered()), this, SLOT(showNormal()));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu* trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(hideAction);
    trayIconMenu->addAction(showAction);
    trayIconMenu->addAction(quitAction);
    trayIconMenu->addSeparator();

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(icon);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
}

Dialog::~Dialog()
{

}
