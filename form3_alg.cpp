/* вспомогательные функции для отрисовки слайдов алгоритмов */
#include "form3.h"
#include "ui_form3.h"
#include <QRect>
#include <QPainter>
#include "formula.h"
extern unsigned char valData[ETH_SRC_NUM][1600];

QString str_sch1_in [] = { "p_peak"};

// вх.дискр сигнал, для схем алгоритмов
void Form3::i1(SigType type, int x, int y, int w=30, int h=40) {
    int x1=x;
    QPainter painter(this);

    if(type==SigInD) {
        QRect r1_outborder(x,y,w,h);
        painter.drawRect(r1_outborder);
        QRect r1_outter(r1_outborder.adjusted(1,1,0,0));
        painter.fillRect(r1_outter, Qt::yellow);
        QRect r1_inborder(r1_outter.adjusted(2,2,-3,-3));
        painter.drawRect(r1_inborder);
        QRect r1_inner(r1_inborder.adjusted(1,1,0,0));
        painter.fillRect(r1_inner, Qt::red);
        x1=r1_outborder.x()+r1_outborder.width();

        // треугольники
        if(type==SigInA) {
            QPolygon polygon;
            polygon << QPoint(x1-25,y) << QPoint(x1-23, y-8)<< QPoint(x1-28, y-8);
            painter.drawPolygon(points, 3);
        }

    }
    return;
    //else if(type==SigInA) {
    QRect r2_outborder(x1,y,200,h);
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

    // для аналог входа
    if(type==SigInA) {
        y+=h;
        QRect r2_outborder(x1,y,200,h);
        painter.drawRect(r2_outborder);
        QRect r2_outter(r2_outborder.adjusted(1,1,0,0));
        painter.fillRect(r2_outter, Qt::red);
        painter.drawText(QPoint(x1+5,y+h/2+5), "название");
        QRect r3_outborder(x2=r2_outborder.x()+r2_outborder.width(),y,20,h);
        painter.drawRect(r3_outborder);
        QRect r3_outter(r3_outborder.adjusted(1,1,0,0));
        painter.fillRect(r3_outter, Qt::red);
    }


    // три коротких линии
    int sm = 12;
    painter.drawLine(x2+20, y + h/2 - sm, x2+20+10, y+ h/2 - sm );
    painter.drawLine(x2+20, y + h/2, x2+20+10, y+ h/2);
    painter.drawLine(x2+20, y + h/2 + sm, x2+20+10, y+ h/2 + sm);
    // 1,2,3 >=2
    int x3 = x2+20+10;
    // горизонтальные
    painter.drawLine(x3, y,  x3+60, y);
    painter.drawLine(x3, y+h/3,  x3+30, y+h/3);
    painter.drawLine(x3, y+h*2/3,  x3+30, y+h*2/3);
    painter.drawLine(x3, y+h,  x3+60, y+h);
    // вертикальные
    painter.drawLine(x3, y,  x3, y+h);
    painter.drawLine(x3+30, y,  x3+30, y+h);
    painter.drawLine(x3+60, y,  x3+60, y+h);
    // подкрашивание активного входа (1|2|3)
    painter.fillRect(x3+1, y+1, 29, h/3-1, Qt::red  );
    painter.fillRect(x3+1, y+h/3+1, 29, h/3-1, Qt::red );
    painter.fillRect(x3+1, y+h*2/3+1, 29, h/3, Qt::red );
    // цифры 1,2,3
    QFont oldfont, font = painter.font();
    oldfont = font;
    font.setPixelSize(10);
    painter.setFont(font);
    painter.drawText(x3+12,y+11, "1");
    painter.drawText(x3+12,y+h/3+11, "2");
    painter.drawText(x3+12,y+h*2/3+12, "3");
    painter.setFont(oldfont);






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
        i1(SigInA,x,y);
        //an1();
    }


}

