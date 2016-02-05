#include "form.h"
#include "ui_form.h"
#include <QRect>
#include <QPainter>


Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
}

void Form::i1() {
    // прямоугольник в прямоугольнике
    QRect rect(10,10,130,40);

    QPainter painter(this);
    painter.fillRect(rect, Qt::yellow);
    QRect rect1(rect.adjusted(3,3,-3,-3));
    painter.fillRect(rect1, Qt::red);

    QRect rect2(rect.adjusted(rect.width(),0,rect.width()+30,0));
    painter.fillRect(rect2, Qt::yellow);
    QRect rect3(rect2.adjusted(3,3,-3,-3));
    painter.fillRect(rect3, Qt::red);

}
void Form::paintEvent(QPaintEvent* e) {
    i1();
}
