#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSystemTrayIcon>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QSystemTrayIcon* trayIcon;
};

#endif // DIALOG_H
