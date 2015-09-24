#include <QTableView>
#include "mdl1.h"
#include "mainform.h"
#include "ui_mainform.h"
#include "str.h"
#include "1_list.h"

// №, name string, out_of_limits string, [123] exists, [>=2] exists
QVector <QString> elemBasic[] {
    {"N > 5%",  "N гцн 1", "123", "m2"}, // 1
    {"N > 75%", "N гцн 1", "123", "m2"}  // 2
};

SelAddon elemAddon[][50] {

    { 1, { {1, AND},   {1, OUT} }},
    { 2, { {2, AND},   {2, OUT} }},
    { 4, { {1, TIMER}, {1, M34}, {1,AND} }},
    { 4, { {2, TIMER}, {1, OR}, {2,AND}, {2,OUT} }},
    { 6, { {1, TIMER}, {1, M34}, {1,AND} }},
    { 6, { {2, TIMER}, {1, OR}, {2,AND}, {2, OUT} }}
};




MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);


    QTableView *tm = new QTableView(ui->stackedWidget);
    Mdl1* mdl = new Mdl1;
    tm->setModel(mdl);
    tm->resize(300,580);





}

MainForm::~MainForm()
{
    delete ui;
}
