#include "referenceppn.h"
#include "ui_referenceppn.h"

referencePpn::referencePpn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::referencePpn)
{
    ui->setupUi(this);
}

referencePpn::~referencePpn()
{
    delete ui;
}
