#ifndef __ANIM_WIDGET_H__
#define __ANIM_WIDGET_H__

#include <QLabel>
#include <QStateMachine>
#include <QWidget>
#include <QDial>

class AnimWidget : public QFrame {
Q_OBJECT
public:


    static const int NUM= 33;

    AnimWidget(QWidget* parent = 0);

signals:
    /* signal for triggering state machine changes */
//    void clicked();

protected:
    /* here we will be catching clicks */
//    virtual void mouseReleaseEvent(QMouseEvent*);


public slots:
   void on_dial_valueChanged(int value);
   void on_dial_sliderMoved(int value);

private:

    QLabel* photo_;
    QDial *dial;


    QList< QLabel* > list;

    //map <double,int> angVsN;

    void drawCircleText();


    //void keyPressEvent(QKeyEvent * ev);

    int lastPos;
    int lh,lw;


};

#endif // __ANIM_WIDGET_H__
