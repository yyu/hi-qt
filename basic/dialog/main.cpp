#include "dialog.h"
#include <QApplication>
//#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // TODO: test on Linux and Windows
    // hide from taskbar
    QWidget dummy;
    Dialog w(&dummy);
    w.setWindowFlags(Qt::Tool);

    //w.show();

    return a.exec();
}
