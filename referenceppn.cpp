#include "referenceppn.h"
#include "ui_referenceppn.h"
#include "form3.h"

extern Form3 *mf;

referencePpn::referencePpn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::referencePpn)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    //setModal(true);
    setWindowModality(Qt::WindowModal);
    digCnt=0;
}

referencePpn::~referencePpn()
{
    delete ui;
}


void referencePpn::keyPressEvent(QKeyEvent * ev) {

    int ix, pg, d = ev->key();
    //if(d==Qt::Key_Escape || d==Qt::Key_Enter)
    d-= Qt::Key_0;
    if(d >= 0 && d <= 9) { // двузначный номер слайда
        if (digCnt==0) {
            if(d>=0 && d<=4 ) // первая цифра (ст.разряд)
            dig[digCnt] = d;
           digCnt++;
            ui->lb_chN->setText(QString::number(d));
        }
        else {
            dig[digCnt] = d;
              ui->lb_chN->setText( QString::number(dig[0] *10)
                               + QString::number(dig[1]));
              digCnt=0;
              ix = dig[0] * 10 + dig[1];
              if(ix!=2 && ix!=3 && ix!=6 && ix!=7 && ix!=9 && ix!=10 && ix!=14 &&ix!=15 ) {
                  if(ix<12)
                      pg=0;
                  else if(ix<24)
                      pg=1;
                  else if(ix<36)
                      pg=2;
                  else if(ix<40)
                      pg=3;
                  else if(ix<44)
                      pg=4;
                  else if(ix<48)
                      pg=5;
                  mf->setPpnPage(pg);
              }
              hide();
              mf->show();
              mf->setFocus();
        }
    }
    else {
        hide();
        mf->show();
        mf->setFocus();
    }
}
