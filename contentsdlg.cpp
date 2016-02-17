#include <QDialogButtonBox>
#include <QGridLayout>
#include <QPushButton>
#include "contentsdlg.h"
#include "ui_contentsdlg.h"
#include <QKeyEvent>
#include <QMouseEvent>


QString ep_algorithm_strings[] {
"1. (АЗ) Р РЕАК ≤149,9кгс/см2 & N ≥ 75 %",
"2. (АЗ) ОТКЛ 1/4 ГЦН & N ≥ 75 %",
"2. (АЗ) ОТКЛ 3/4 ГЦН & N ≥ 5 %",
"3. (АЗ) L ПВ ПГ 1 ≤ - 65 см",
"3. (АЗ) L ПВ ПГ 2 ≤ - 65 см",
"3. (АЗ) L ПВ ПГ 3 ≤ - 65 см",
"3. (АЗ) L ПВ ПГ 4 ≤ - 65 см",
"3. (АЗ) L КД ≤ 460 см",
"4. (АЗ) Р РЕАК ≥178,5кгс/см2",
"5. (АЗ) Р ГА306/1 ≥ 0,306 кгс/см2",
"6. (АЗ) ПОТЕРЯ ПИТАНИЯ СУЗ",
"(АЗ) ИЗМ Р-Р ГЦН 1",
"(АЗ) ИЗМ Р-Р ГЦН 2",
"(АЗ) ИЗМ Р-Р ГЦН 3",
"(АЗ) ИЗМ Р-Р ГЦН 4",
"(АЗ) Р ПГ1≤49,97кгс/см2 & Т НАС1≥75°C",
"(АЗ) Р ПГ2≤49,97кгс/см2 & Т НАС2≥75°C",
"(АЗ) Р ПГ3≤49,97кгс/см2 & Т НАС3≥75°C",
"(АЗ) Р ПГ4≤49,97кгс/см2 & Т НАС4≥75°C",
"(АЗ) Р ТРОП ПГ ≥ 79,95 кгс/см2",
"(АЗ) Т ГРЧ ГЦТ ≥ + 8 °С",
"(АЗ) F 3/4 ГЦН ≤ 46 Гц",
"(АЗ) Т НАС - Т МАХ ГРЧ 1 ≤ 10 °С",
"(АЗ) Т НАС - Т МАХ ГРЧ 2 ≤ 10 °С",
"(АЗ) Т НАС - Т МАХ ГРЧ 3 ≤ 10 °С",
"(АЗ) Т НАС - Т МАХ ГРЧ 4 ≤ 10 °С",
"(АЗ) ОТКЛ ТПН 1, ТПН 2 & N ≥ 40 %",
"(АЗ) Т ДР, ДП, ИД ≤ Т ЗАДАН. (10 с)",
"(АЗ) N ДР, ДП, ИД ≥ УСТ.",
"(АЗ) СЕЙСМИЧ. ВОЗД. ≥ 4 БАЛЛОВ",
"(АЗ) Р РЕАК ≤ 140,0 кгс/см2",
"(АЗ) QL ≥ 448 Вт/см",
"(АЗ) DNBR ≤ 1,35" };


ContentsDlg::ContentsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ContentsDlg)
{
    digCnt=0; dig[0] = dig[1] = 0;
    ui->setupUi(this);
    hide();
    setModal(true);

    QPalette pal;
    pal.setColor(QPalette::Window, Qt::white);
    pal.setColor(QPalette::WindowText, Qt::blue);
    setAutoFillBackground(true);
    setPalette(pal);

    setWindowFlags(Qt::FramelessWindowHint);

    QGridLayout *metagrid = new QGridLayout;
    setLayout(metagrid);
    setContentsMargins(10, 10, 10, 10);



    setMinimumHeight(100);

    const int sz = 32;
    QPushButton *bt[sz];
    QFont f;
        f.setBold(true);
        f.setFamily("Tahoma");
        f.setItalic(true);
        f.setPointSize(7);

    int bx,by,i;
    for(i=0, bx=0,by=0; i<sz; i++) {
        bt[i] = new QPushButton(ep_algorithm_strings[i]);
        //bt[i]->setStyleSheet(QString("font-size: %1px").arg(32));

        bt[i]->setFont(f);

        bt[i]->setFlat(true);
        //addButton(bt[i], QDialogButtonBox::ActionRole);
        metagrid->addWidget(bt[i], bx, by);
        if(bx<10) {
            bx++;
        }
        else{
            by++;
            bx=0;
        }
    }

    //setCenterButtons(true);

    //QList<QAbstractButton *> buttons = buttons();
    //while(buttons.size())
        //buttons.takeFirst()->setMinimumHeight(minimumHeight());
        //buttons.takeFirst()->setMinimumHeight(minimumHeight());


    //findButton->setDefault(true);
    resize(700,500);

    show();


}
ContentsDlg::~ContentsDlg()
{
    delete ui;
}

void ContentsDlg::keyPressEvent(QKeyEvent * ev) {

//    if(ev->key() == Qt::Key_Right) // след.страница
//        sw->setCurrentIndex(( sw->currentIndex() <sw->count()-1 )? sw->currentIndex() + 1 : 0);

//    else if(ev->key() == Qt::Key_Left) // предыд.страница
//        sw->setCurrentIndex((sw->currentIndex() > 0 )? sw->currentIndex()-1 : sw->count()-1);

//    if(ev->key() >= Qt::Key_0 && ev->key() <= Qt::Key_9) { // двузначный номер слайда
//        //sw->setCurrentIndex(ev->key()-Qt::Key_0);

//        //запускаем таймер на 2 сек
//        dig[digCnt] = ev->key();
//        if (digCnt==0)
//            digCnt++;
//        else
//            digCnt=0;
//        sw->setCurrentIndex((dig[1]-Qt::Key_0 * 10) + (dig[0]-Qt::Key_0) );

//    }
}
