#include "f4.h"
#include "ui_f4.h"

f4::f4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::f4)
{
    ui->setupUi(this);
}

f4::~f4()
{
    delete ui;
}
