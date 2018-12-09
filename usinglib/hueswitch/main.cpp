#include "hueswitch.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // TODO: test on Linux and Windows
    // hide from taskbar
    QWidget dummy;
    HueSwitch w(&dummy);
    w.setWindowFlags(Qt::Tool);

    //w.show();

    return a.exec();
}
