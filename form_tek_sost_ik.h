#ifndef FORM_TEK_SOST_IK_H
#define FORM_TEK_SOST_IK_H

#include <QWidget>

namespace Ui {
class form_tek_sost_ik;
}

class form_tek_sost_ik : public QWidget
{
    Q_OBJECT

public:
    explicit form_tek_sost_ik(QWidget *parent = 0);
    ~form_tek_sost_ik();

private:
    Ui::form_tek_sost_ik *ui;
};

#endif // FORM_TEK_SOST_IK_H
