#include "contentsdlg.h"
#include "ui_contentsdlg.h"

ContentsDlg::ContentsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContentsDlg)
{
    ui->setupUi(this);
}

ContentsDlg::~ContentsDlg()
{
    delete ui;
}
