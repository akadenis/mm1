#include <QLabel>
//#include <QButton>
#include "form3.h"

// для желтой рамки
void Form3::imit(QFrame *lb) {
    QPalette* palette = new QPalette();
    palette->setColor(QPalette::Foreground,Qt::yellow);
    lb->setPalette(*palette);
}

// вспомогательные функции для отрисовки лэйблов и линий
void Form3::ln(QFrame *lb, int redFlag, int yellowFlag) {
    QPalette pal;
    pal.setColor(QPalette::Window, Qt::white);
    if(redFlag)
        pal.setColor(QPalette::WindowText, Qt::red);
    else if(yellowFlag)
        pal.setColor(QPalette::WindowText, Qt::yellow);
    else
        pal.setColor(QPalette::WindowText, Qt::black);
    lb->setAutoFillBackground(true);
    lb->setPalette(pal);
}

void Form3::ln2(QFrame *lb1, QFrame *lb2, int redFlag, int yellowFlag) {
    ln(lb1, redFlag, yellowFlag);
    ln(lb2, redFlag, yellowFlag);
}

void Form3::ln3(QFrame *lb1, QFrame *lb2,QFrame *lb3, int redFlag, int yellowFlag) {
    ln(lb1, redFlag, yellowFlag);
    ln(lb2, redFlag, yellowFlag);
    ln(lb3, redFlag, yellowFlag);
}

void Form3::lb(QLabel *lb, int flag) {
    QPalette pal;
    //pal.setColor(QPalette::Window, Qt::white);
    pal.setColor(QPalette::WindowText, flag? Qt::red : Qt::black );
    //pal.setColor(QPalette::WindowText, flag?Qt::black :  Qt::red );
    //lb->setAutoFillBackground(true);
    lb->setPalette(pal);
}
void Form3::cl(QLabel *lb, int b1, int b2) {
//        QPalette pal;
//        //pal.setColor(QPalette::Window, Qt::white);
//        pal.setColor(QPalette::WindowText, flag? Qt::red : Qt::black );
//        //pal.setColor(QPalette::WindowText, flag?Qt::black :  Qt::red );
//        //lb->setAutoFillBackground(true);
//        lb->setPalette(pal);

    QString c;
    if(b1==1 && b2==1)
        c = "red";
    else if((b1==0 && b2==1) || (b2==0 && b1==1))
        c = "yellow";
    else if(b1==0 && b2==0)
        c = "green";
    lb->setStyleSheet(QString("QLabel { background-color : %1; }").arg(c));
}

void Form3::l1(QLabel *lb, int b) {
    QString c;
    if(b==0)
        c = "yellow";
    else
        c = "#efebe7";
    lb->setStyleSheet(QString("QLabel { background-color : %1; }").arg(c));
}

void Form3::l2(QLabel *lb, int b) {
    QString c;
    if(b==0)
        c = "red";
    else
        c = "green";
    lb->setStyleSheet(QString("QLabel { background-color : %1; }").arg(c));
}


void Form3::lb(QLabel *lb, QColor color) {
    QPalette pal;
    pal.setColor(QPalette::Window, Qt::white);
    pal.setColor(QPalette::WindowText, color);
    lb->setAutoFillBackground(true);
    lb->setPalette(pal);
}
void Form3::red(QLabel *lb) {
    QPalette pal;
    pal.setColor(QPalette::Window, Qt::white);
    pal.setColor(QPalette::WindowText, Qt::red);
    lb->setAutoFillBackground(true);
    lb->setPalette(pal);
}
void Form3::black(QLabel *lb) {
    QPalette pal;
    pal.setColor(QPalette::Window, Qt::white);
    pal.setColor(QPalette::WindowText, Qt::black);
    lb->setAutoFillBackground(true);
    lb->setPalette(pal);
}
//void Form3::pbColor(QPushButton *pb, bool color) {
//    QString clr, s;
//    if(color) clr = "red";
//    else clr = "black";
//    s = "QPushButton { border: 0px solid black; background-color : white; color : " + clr + "; }";
//    pb->setStyleSheet(s);
//}

//void Form3::pbColor(QPushButton *pb, QColor color) {
//    QString clr, s;
//    if(color==Qt::red) clr = "red";
//    else if(color==Qt::black) clr = "black";
//    else if(color==Qt::white) clr = "white";

//    pb->setStyleSheet(s);
//}

