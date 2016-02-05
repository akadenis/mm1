#ifndef DLGPPN_H
#define DLGPPN_H

#include <QDialog>

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
};

#endif // DLGPPN_H
