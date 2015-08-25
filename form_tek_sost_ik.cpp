#include "form_tek_sost_ik.h"
#include "ui_form_tek_sost_ik.h"

form_tek_sost_ik::form_tek_sost_ik(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_tek_sost_ik)
{
    ui->setupUi(this);
}

form_tek_sost_ik::~form_tek_sost_ik()
{
    delete ui;
}
