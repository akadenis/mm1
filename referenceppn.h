#ifndef REFERENCEPPN_H
#define REFERENCEPPN_H

#include <QWidget>
#include <QKeyEvent>

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


    int dig[2];
    int digCnt;

    void keyPressEvent(QKeyEvent * ev);
};

#endif // REFERENCEPPN_H
