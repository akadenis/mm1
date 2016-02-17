#include "dlgppn.h"
#include "ui_dlgppn.h"
#include "form3.h"

extern Form3 *mf;

dlgPpn::dlgPpn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgPpn)
{
    ui->setupUi(this);
    digCnt=0;
}



dlgPpn::~dlgPpn()
{
    delete ui;
}



void dlgPpn::keyPressEvent(QKeyEvent * ev) {

    if(ev->key() >= Qt::Key_0 && ev->key() <= Qt::Key_9) { // двузначный номер слайда
        dig[digCnt] = ev->key();
        if (digCnt==0) {
//            QTimer::singleShot(2000,Qt::CoarseTimer , this, SLOT(onHideFrameNumbers()));
//            hideFrameNumbersTimerEnabled = true;
//            hide2DigitTimerEnabled = false;
            digCnt++;
            ui->lb_chN->setText(QString::number(dig[0]-Qt::Key_0));
            //lbFrameNum->setVisible(true);
        }
        else {
//            hideFrameNumbersTimerEnabled = false;
//            hide2DigitTimerEnabled = true;


              mf->setPpnPage( ((dig[0]-Qt::Key_0) * 10) + (dig[1]-Qt::Key_0) );
//
              ui->lb_chN->setText( QString::number((dig[0]-Qt::Key_0) *10)
                               + QString::number( dig[1]-Qt::Key_0) );
//            QTimer::singleShot(1000,Qt::CoarseTimer , this, SLOT(onHide2Digit()));
              digCnt=0;
              hide();
        }
    }
}
