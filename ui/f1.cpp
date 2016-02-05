#include "f1.h"
#include "ui_f1.h"

f1::f1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::f1)
{
    ui->setupUi(this);
}

f1::~f1()
{
    delete ui;
}
