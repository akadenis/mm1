#include "dlgppn.h"
#include "ui_dlgppn.h"

dlgPpn::dlgPpn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgPpn)
{
    ui->setupUi(this);
}

dlgPpn::~dlgPpn()
{
    delete ui;
}
