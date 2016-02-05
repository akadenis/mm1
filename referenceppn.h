#ifndef REFERENCEPPN_H
#define REFERENCEPPN_H

#include <QWidget>

namespace Ui {
class referencePpn;
}

class referencePpn : public QWidget
{
    Q_OBJECT

public:
    explicit referencePpn(QWidget *parent = 0);
    ~referencePpn();

private:
    Ui::referencePpn *ui;
};

#endif // REFERENCEPPN_H
