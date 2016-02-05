#include "ref.h"
#include "ui_ref.h"

Ref::Ref(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ref)
{
    ui->setupUi(this);
}

Ref::~Ref()
{
    delete ui;
}
