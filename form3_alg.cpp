/* вспомогательные функции для отрисовки слайдов алгоритмов */
#include "form3.h"
#include "ui_form3.h"
#include <QRect>
#include <QPainter>
#include "formula.h"
extern unsigned char valData[ETH_SRC_NUM][1600];

QString str_sch1_in [] = { "p_peak"};

// вх.дискр сигнал, для схем алгоритмов
void Form3::i1(int x, int y, int w=30, int h=40) {
    QPainter painter(this);
    QRect r1_outborder(x,y,w,h);
    painter.drawRect(r1_outborder);
    QRect r1_outter(r1_outborder.adjusted(1,1,0,0));
    painter.fillRect(r1_outter, Qt::yellow);
    QRect r1_inborder(r1_outter.adjusted(2,2,-3,-3));
    painter.drawRect(r1_inborder);
    QRect r1_inner(r1_inborder.adjusted(1,1,0,0));
    painter.fillRect(r1_inner, Qt::red);

    int x1;
    QRect r2_outborder(x1=r1_outborder.x()+r1_outborder.width(),y,200,h);
    painter.drawRect(r2_outborder);
    QRect r2_outter(r2_outborder.adjusted(1,1,0,0));
    painter.fillRect(r2_outter, Qt::red);
    QRect r2_inborder(r2_outter.adjusted(2,2,-3,-3));
    painter.drawRect(r2_inborder);
    QRect r2_inner(r2_inborder.adjusted(1,1,0,0));
    painter.fillRect(r2_inner, Qt::gray);
    painter.drawText(QPoint(x1+5,y+h/2+5), "название");

    int x2;
    QRect r3_outborder(x2=r2_outborder.x()+r2_outborder.width(),y,20,h);
    painter.drawRect(r3_outborder);
    QRect r3_outter(r3_outborder.adjusted(1,1,0,0));
    painter.fillRect(r3_outter, Qt::red);

    // три коротких линии
    for(int i=0;i<3;i++)
        painter.drawLine(x2+20, y+5 + w*i/3,x2+20+5,y+5 + w*i/3);
}
// вх.аналоговый сигнал, для схем алгоритмов. Занимает две строки
void Form3::an1(int x, int y, int w, int h) {
    QPainter painter(this);
    QRect r1_outborder(x,y,w,h);
    painter.drawRect(r1_outborder);
    QRect r1_outter(r1_outborder.adjusted(1,1,0,0));
    painter.fillRect(r1_outter, Qt::yellow);
    QRect r1_inborder(r1_outter.adjusted(2,2,-3,-3));
    painter.drawRect(r1_inborder);
    QRect r1_inner(r1_inborder.adjusted(1,1,0,0));
    painter.fillRect(r1_inner, Qt::red);

    QRect r2_outborder(r1_outborder.x()+r1_outborder.width(),y,100,h);
    painter.drawRect(r2_outborder);
    QRect r2_outter(r2_outborder.adjusted(1,1,0,0));
    painter.fillRect(r2_outter, Qt::red);
    QRect r2_inborder(r2_outter.adjusted(2,2,-3,-3));
    painter.drawRect(r2_inborder);
    QRect r2_inner(r2_inborder.adjusted(1,1,0,0));
    painter.fillRect(r2_inner, Qt::gray);

    QRect r3_outborder(r2_outborder.x()+r2_outborder.width(),y,20,h);
    painter.drawRect(r3_outborder);
    QRect r3_outter(r3_outborder.adjusted(1,1,0,0));
    painter.fillRect(r3_outter, Qt::red);
}

void Form3::paintEvent(QPaintEvent* e) {
    int ix = ui->stackedWidget->currentIndex();

    if( ix==13 ) {
        switch(discrSlideCurr) {
        case 0: // вх 151,152
            paintEvent1(in151);
            break;
        case 1:
            paintEvent1(out155az);
            break;
        case 2:
            paintEvent1(out155pz);
            break;
        case 3:
            paintEvent1(pca);
            break;
        }
    }
    else if( ix==3 ) {
        int x=0,y=0,w=120,h=49;
        i1(x,y);
        //an1();
    }


}

