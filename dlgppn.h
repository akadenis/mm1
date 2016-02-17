#ifndef DLGPPN_H
#define DLGPPN_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class dlgPpn;
}

class dlgPpn : public QDialog
{
    Q_OBJECT

public:
    explicit dlgPpn(QWidget *parent = 0);
    ~dlgPpn();

private:
    Ui::dlgPpn *ui;

    int dig[2];
    int digCnt;

    void keyPressEvent(QKeyEvent * ev);
};

#endif // DLGPPN_H
