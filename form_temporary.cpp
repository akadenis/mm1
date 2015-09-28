#include "form_temporary.h"
#include "ui_form_temporary.h"

form_temporary::form_temporary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::form_temporary)
{
    ui->setupUi(this);
}

form_temporary::~form_temporary()
{
    delete ui;
}
