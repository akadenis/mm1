#include "ref.h"
#include "ui_ref.h"
#include "form3.h"
extern Form3 *mf;

Ref::Ref(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ref)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    //setModal(true);
    setWindowModality(Qt::WindowModal);
    digCnt=0;
}

Ref::~Ref()
{
    delete ui;
}

int m[10] = { 19, 0, 1, 12, 13, 14, 15, 16, 17, 18 };

void Ref::keyPressEvent(QKeyEvent * ev) {

    int d = ev->key();
    d-= Qt::Key_0;
    if(d >= 0 && d <= 9) { // номер группы слайдов
        mf->setPage(m[d]);
        hide();
        mf->show();
        mf->setFocus();
    }
    else {
        hide();
        mf->show();
        mf->setFocus();
    }
}
