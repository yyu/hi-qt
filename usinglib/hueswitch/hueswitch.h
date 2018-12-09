#ifndef HUESWITCH_H
#define HUESWITCH_H

#include <QDialog>
#include <QSystemTrayIcon>

class HueSwitch : public QDialog
{
    Q_OBJECT

public:
    explicit HueSwitch(QWidget *parent = nullptr);
    ~HueSwitch();

public Q_SLOTS:
    void switchOn();
    void switchOff();

private:
    QSystemTrayIcon* trayIcon;
    std::map<std::string, QIcon> iconMap;
};

#endif // HUESWITCH_H
