#include "f2.h"
#include "ui_f2.h"

f2::f2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::f2)
{
    ui->setupUi(this);
}

f2::~f2()
{
    delete ui;
}
