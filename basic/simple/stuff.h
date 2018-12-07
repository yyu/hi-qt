#ifndef STUFF_H
#define STUFF_H

#include <QWidget>

namespace Ui {
class Stuff;
}

class Stuff : public QWidget
{
    Q_OBJECT

public:
    explicit Stuff(QWidget *parent = nullptr);
    ~Stuff();

private:
    Ui::Stuff *ui;
};

#endif // STUFF_H
