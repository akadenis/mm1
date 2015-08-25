#include "form_tek_sost_afsz.h"
#include "ui_form_tek_sost_afsz.h"
#include <math.h>
#include <map>



Form_tek_sost_AFSZ::Form_tek_sost_AFSZ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_tek_sost_AFSZ)
{
    lastPos = -1;
    ui->setupUi(this);
    ui->dial->setMinimum(0);
    ui->dial->setMaximum(NUM-1);
    drawCircleText();



}

Form_tek_sost_AFSZ::~Form_tek_sost_AFSZ()
{
    delete ui;
}

// рисуем по часовой стрелке: "Список алгоритмов АЗ ПЗ"
void Form_tek_sost_AFSZ::drawCircleText() {

#if 1
    QString s[NUM] = {
            "Р РЕАК ≤149,9кгс/см2 & N ≥ 75 %",
            "ОТКЛ 1/4 ГЦН & N ≥ 75 %",
            "ОТКЛ 3/4 ГЦН & N ≥ 5 %",
            "L ПВ ПГ 1 ≤ - 65 см",
            "L ПВ ПГ 2 ≤ - 65 см",
            "L ПВ ПГ 3 ≤ - 65 см",
            "L ПВ ПГ 4 ≤ - 65 см",
            "L КД ≤ 460 см",
            "Р РЕАК ≥178,5кгс/см2",
            "Р ГА306/1 ≥ 0,306 кгс/см2",
            "ПОТЕРЯ ПИТАНИЯ СУЗ",
            "ИЗМ Р-Р ГЦН 1",
            "ИЗМ Р-Р ГЦН 2",
            "ИЗМ Р-Р ГЦН 3",
            "ИЗМ Р-Р ГЦН 4",
            "Р ПГ1≤49,97кгс/см2 & Т НАС1≥75°C",
            "Р ПГ2≤49,97кгс/см2 & Т НАС2≥75°C",
            "Р ПГ3≤49,97кгс/см2 & Т НАС3≥75°C",
            "Р ПГ4≤49,97кгс/см2 & Т НАС4≥75°C",
            "Р ТРОП ПГ ≥ 79,95 кгс/см2",
            "Т ГРЧ ГЦТ ≥ + 8 °С0",
            "F 3/4 ГЦН ≤ 46 Гц",
            "Т НАС - Т МАХ ГРЧ 1 ≤ 10 °С",
            "Т НАС - Т МАХ ГРЧ 2 ≤ 10 °С",
            "Т НАС - Т МАХ ГРЧ 3 ≤ 10 °С",
            "Т НАС - Т МАХ ГРЧ 4 ≤ 10 °С",
            "ОТКЛ ТПН 1, ТПН 2 & N ≥ 40 %",
            "Т ДР, ДП, ИД ≤ Т ЗАДАН. (10 с)",
            "N ДР, ДП, ИД ≥ УСТ.",
            "СЕЙСМИЧ. ВОЗД. ≥ 4 БАЛЛОВ",
            "Р РЕАК ≤ 140,0 кгс/см2",
            "QL ≥ 448 Вт/см",
            "DNBR ≤ 1,35"
    };
#else
    QString s[NUM] = {
                    "1_111111", "1_222222", "1_333333", "1_444444", "1_555555", "1_666666", "1_777777", "1_888888", "1_999999",
                    "2_111111", "2_222222", "2_333333", "2_444444", "2_555555", "2_666666", "2_777777", "2_888888", "2_999099",
                    "3_111111", "3_222222", "3_333333", "3_444444", "3_555555", "3_666666", "3_777777", "3_888888", "3_999999",
                    "4_111111", "4_222222", "4_333333", "4_444444", "4_555555", "4_666666", "4_777777", "4_888888", "4_999999"
                   } ;

#endif

    double r = ui->dial->width()/2;
    double x[NUM],X = double(ui->dial->x() +r -0);
    double y[NUM],Y = double(ui->dial->y() +r-10);

    int i;
    double angle, phi;
    const int NN =6;
    int dy[NN] = {1 ,4, 7 , 11, 17, 25};
    int dx[NN] = {10, 20, 30, 50, 65, 80 };
    const double Mult =3;
    int w;
    for(angle=0, i=0; i<NUM && angle<360; i++, angle += 360/NUM) {
        list << new QLabel( this);
        list[i]->setFont(QFont("Times New Roman", 9,-1,true));
        list[i]->setStyleSheet("QLabel {"
                                     "border-style: solid;"
                                     "border-width: 1px;"
                                     "border-color: gray; "
                                     "}");
        list[i]->setText( s[i] );
        phi = angle / 180 * M_PI;
        w = list[i]->width();
        x[i] = X + r*1.6 * sin(phi) - ( w *(i>=NUM/2?1:0) );
        y[i] = Y + r*1.6 * cos(phi);
        //lines[i] = new QLine(x,y,)

    }

    for(i=0; i< NN; i++) {
        y[NN-1 - i] += dy[i]*Mult;
        //x[NN - 1 - i] += dx[i];

        y[NUM/2-1 - (NN-1) + i] -= dy[i]*Mult;
        //x[NUM/2-1 - (NN-1) + i] += dx[i];

        y[NUM/2 + (NN-1) - i] -= dy[i]*Mult;
        x[NUM/2 + (NN-1) - i] -= dx[i];

        y[NUM -1 - (NN-1) + i] += dy[i]*Mult;
        //x[NUM-(NN-1) + i] -= dx[i];
    }

    for(i=0; i< NUM; i++) {
        list[i]->move(int(x[i]),int(y[i]));
        list[i]->show();
    }

}


void Form_tek_sost_AFSZ::on_dial_valueChanged(int i) {
    //list[i]->setStyleSheet("QLabel { background-color : red; color : blue; }");
    list[i]->setStyleSheet("QLabel {"
                                  "background-color : red;"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: gray; "
                                 "}");
}

void Form_tek_sost_AFSZ::on_dial_sliderMoved(int i) {
    list[i]->resize(list[i]->width()*3, list[i]->height()*2);
    list[i]->setFont(QFont("Times New Roman", 22,-1,true));
    list[i]->setStyleSheet("QLabel {  background-color : lightgray; color : green; }");
    list[i]->raise();
        if(lastPos>=0) {
            list[lastPos]->resize(list[i]->width()/3, list[i]->height()/2);
            list[lastPos]->setStyleSheet("QLabel {"
                                     "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: gray; "
                                 "background-color : white; color : black;"
                                 "}");
             list[lastPos]->setFont(QFont("Times New Roman", 9,-1,true));
       }
    lastPos = i;
}
