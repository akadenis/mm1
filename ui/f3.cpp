#include "f3.h"
#include "ui_f3.h"

f3::f3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::f3)
{
    ui->setupUi(this);
}

f3::~f3()
{
    delete ui;
}
