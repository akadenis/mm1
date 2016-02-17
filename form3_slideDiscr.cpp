#include "form3.h"
#include "ui_form.h"
#include <QRect>
#include <QPainter>
#include "formula.h"
enum DevType { in151, out155az, out155pz, pca };
extern unsigned char valData[ETH_SRC_NUM][1600];
extern QString strDiscr_pvk151_1[24];
extern QString strDiscr_pvk151_2[24];
extern QString strDiscr_columns[7];
// перевод порядкового номера 0...6 в порядок следования групп сигналов в таблице сигналов 151-152
extern int cnv_in[7];
extern QString strOutDiscr_columns[6];
extern QString strOutDiscr_pvk155_1az[];
extern QString strOutDiscr_pvk155_2az[];
extern QString strOutDiscr_pvk155_1pz[];
extern QString strOutDiscr_pvk155_2pz[];
extern int cnv_out[6];
extern QString str_pca_az[];
extern QString str_pca_pz[];

// для отрисовки вертикального текста
void Form3::drawVTxt(QPainter *painter, const QPoint& p, const QString& str) {

    QTransform old = painter->transform();
    painter->translate(p);
    painter->rotate(270);
    painter->drawText(0, 0, str);
    //painter.rotate(-270);
    painter->setTransform(old);
}

void Form3::paintEvent1(DevType type) {
    int i,j;
    int x=0;
    QPainter p(this);
    QFont oldfont, font = p.font();
    oldfont = font;
    font.setPixelSize(28);
    p.setFont(font);
    if(type == in151)
        p.drawText(QPoint(175, 28), "Входные дискретные сигналы");
    else if(type==pca)
        p.drawText(QPoint(175, 28), "Выходные частотные сигналы");
    else
        p.drawText(QPoint(175, 28), "Выходные дискретные сигналы");
    p.setFont(oldfont);

    font = p.font();
    oldfont = font;
    font.setPixelSize(14);
    p.setFont(font);

    if(type==out155az) {
        p.drawText(QPoint(145, 70), "ПВК-151Р 1");
        p.drawText(QPoint(545, 70), "ПВК-151Р 2");
    }
    else if(type==pca) {
        p.drawText(QPoint(145, 70), "ПЧА-08Р АЗ");
        p.drawText(QPoint(545, 70), "ПЧА-08Р ПЗ");
    }
    else if(type==out155az)
        p.drawText(QPoint(145, 70), "ПВК-155Р АЗ");
    else if(type==out155pz)
            p.drawText(QPoint(145, 70), "ПВК-155Р ПЗ");

    p.setFont(oldfont);

    // гориз.линия сверху
    p.drawLine(0, 35, 799, 35);

    // вертикальные линии
    p.drawLine(400, 35, 400, 599);
    p.drawLine(799, 120, 799, 120+20*24);

    // горизонтальные линии, текст и прямоугольники (по 6 шт в строке)
    QRect rect(300, 120+2, 10, 15);
    for(i=0;i<24;i++) {
        //i1(x,y+ i*h + 1,w,h);
        p.drawLine(0, 120+20*i, 400, 120+20*i);
        if(type == in151)
            p.drawText(QPoint(5, 120+20*i + 15), strDiscr_pvk151_1[i]);
        else if(type == out155az)
            p.drawText(QPoint(5, 120+20*i + 15), strOutDiscr_pvk155_1az[i]);
        else if(type == out155pz)
            p.drawText(QPoint(5, 120+20*i + 15), strOutDiscr_pvk155_1pz[i]);
        else if(type == pca) {}
            //p.drawText(QPoint(5, 120+20*i + 15), strOutDiscr_pvk155_1pz[i]);

        rect.moveTop(120+2 + i*20);
        x = rect.x();
        for(j=0;j<7;j++) {
            rect.moveLeft(x + j*15);
            //p.fillRect(rect, j%2?Qt::red:Qt::green);
            if(type == in151)
                for(j=0;j<7;j++) {
                    rect.moveLeft(x + j*15);
                    p.fillRect(rect, valData[p151_1][cnv_in[j*24 + i]]? Qt::red : Qt::green);
                }
            else if(type == out155az)
                for(j=0;j<6;j++) {
                    rect.moveLeft(x + j*15);
                    p.fillRect(rect, valData[p155az1][cnv_out[j*24 + i]]? Qt::red : Qt::green);
                }
            else if(type == out155pz)
                for(j=0;j<6;j++) {
                    rect.moveLeft(x + j*15);
                    p.fillRect(rect, valData[p155pz1][cnv_out[j*24 + i]]? Qt::red : Qt::green);
                }
            else if(type == pca)
                for(j=0;j<6;j++) {
                    rect.moveLeft(x + j*15);
                    p.fillRect(rect, valData[p08az][cnv_out[j*24 + i]]? Qt::red : Qt::green);
                }
        }
        rect.moveLeft(x);
    }

    // табл.слева (для ПВК 151_1)
    // горизонтальные линии, текст и прямоугольники (дискр.значения) (по 7|6 шт в строке)
    rect.moveLeft(700);
    for(i=0;i<24;i++) {
        //i1(x,y+ i*h + 1,w,h);
        p.drawLine(400, 120+20*i, 799, 120+20*i);
        p.drawText(QPoint(5 + 400, 120+20*i + 15), strDiscr_pvk151_2[i]);
        rect.moveTop(120+2 + i*20);
        x = rect.x();

        if(type == in151)
            for(j=0;j<7;j++) {
                rect.moveLeft(x + j*15);
                p.fillRect(rect, valData[p151_2][cnv_in[j*24 + i]]? Qt::red : Qt::green);
            }
        else if(type == out155az)
            for(j=0;j<6;j++) {
                rect.moveLeft(x + j*15);
                p.fillRect(rect, valData[p155pz1][cnv_out[j*24 + i]]? Qt::red : Qt::green);
            }
        else if(type == out155pz)
            for(j=0;j<6;j++) {
                rect.moveLeft(x + j*15);
                p.fillRect(rect, valData[p155pz1][cnv_out[j*24 + i]]? Qt::red : Qt::green);
            }
        else if(type == pca)
            for(j=0;j<6;j++) {
                rect.moveLeft(x + j*15);
                p.fillRect(rect, valData[p08pz][cnv_out[j*24 + i]]? Qt::red : Qt::green);
            }



        rect.moveLeft(x);
    }

    // подписи к колонкам с прямоугольниками
    if(type==in151)
        for(i=0; i<7; i++) {
            drawVTxt(&p, QPoint(310 + 15*i, 118), strDiscr_columns[i]);
            drawVTxt(&p, QPoint(710 + 15*i, 118), strDiscr_columns[i]);
        }
    else if(type==out155az)
        for(i=0; i<6; i++) {
            drawVTxt(&p, QPoint(307 + 15*i, 118), strOutDiscr_columns[i]);
            drawVTxt(&p, QPoint(707 + 15*i, 118), strOutDiscr_columns[i]);
        }
    else if(type==out155pz)
        for(i=0; i<6; i++) {
            drawVTxt(&p, QPoint(307 + 15*i, 118), strOutDiscr_columns[i]);
            drawVTxt(&p, QPoint(707 + 15*i, 118), strOutDiscr_columns[i]);
        }
//    else if(type==out155pz)
//        strOutDiscr_columns
//        for(i=0; i<7; i++) {
//            drawVTxt(&p, QPoint(310 + 15*i, 118), strOutDiscr_columns[i]);
//            drawVTxt(&p, QPoint(710 + 15*i, 118), strOutDiscr_columns[i]);
//        }
}

