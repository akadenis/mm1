#ifndef FORM_TEK_SOST_AFSZ_H
#define FORM_TEK_SOST_AFSZ_H

#include <QWidget>
#include <QLabel>
#include <QList>
#include "animwidget.h"
#include <QStateMachine>
using namespace std;



namespace Ui {
class Form_tek_sost_AFSZ;
}

class Form_tek_sost_AFSZ : public QWidget
{
    Q_OBJECT

public:
    explicit Form_tek_sost_AFSZ(QWidget *parent = 0);
    ~Form_tek_sost_AFSZ();

signals:
    /* signal for triggering state machine changes */
    void clicked();

protected:
    /* here we will be catching clicks */
    virtual void mouseReleaseEvent(QMouseEvent*);



private slots:
    //void on_dial_valueChanged(int value);

    //void on_dial_sliderMoved(int position);

private:

    QStateMachine machine_;


    AnimWidget *aw;
    static const int NUM= 33;

    Ui::Form_tek_sost_AFSZ *ui;

    QList< QLabel* > list;

    //map <double,int> angVsN;

    void drawCircleText();


    //void keyPressEvent(QKeyEvent * ev);

    int lastPos;
    int lh,lw;

    QState* st1;
    QState* st2;

};

#endif // FORM_TEK_SOST_AFSZ_H
