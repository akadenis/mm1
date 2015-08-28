#include "animwidget.h"

#include <QState>
#include <QVariant>
#include <QPropertyAnimation>
#include <math.h>
#include <map>
#include "dataTableModel.h"



AnimWidget::AnimWidget() {
    photo_ = new QLabel("", this);
    photo_->setGeometry( 0,  0, 40, 40);
    photo_->setScaledContents(true);
    photo_->setText("1341412413");
    /* creating 2 states */
    QState* st1 = new QState();
    QState* st2 = new QState();

    /* defining photo's properties for each of them */
    st1->assignProperty(photo_, "geometry", QRect( 0,  0, 40, 40));
    st2->assignProperty(photo_, "geometry", QRect(50, 50, 200, 200));

    /* define transitions between states by clicking on main window*/
    st1->addTransition(this, SIGNAL(clicked()), st2);
    st2->addTransition(this, SIGNAL(clicked()), st1);

    /* adding states to state machine */
    machine_.addState(st1);
    machine_.addState(st2);
    machine_.setInitialState(st1);


    QPropertyAnimation* an1 = new QPropertyAnimation(photo_, "geometry");
    machine_.addDefaultAnimation(an1);

    an1->setEasingCurve(QEasingCurve::InOutCubic);
    an1->setDuration(500);

    /* starting machine */
    machine_.start();

    //--------------------------------------------
    lastPos = -1;
    DataTableModel* model = new DataTableModel;
    //ui->setupUi(this);
    //tbTekSostAfsz->setModel(model);
    //ui->tbTekSostAfsz->resizeColumnsToContents();

    //ui->widget->move(ui->widget->x() - ui->widget->width()  +50, ui->widget->x());

    dial = new QDial(this);
    dial->move(x()+width()/2,y()+height()/2);
    dial->setMinimum(0);
    dial->setMaximum(NUM-1);
    drawCircleText();

    connect(dial, SIGNAL(&QDial::valueChanged), this, SLOT(on_dial_valueChanged) );
    connect(dial, SIGNAL(&QDial::sliderMoved), this, SLOT(on_dial_sliderMoved) );


}

void AnimWidget::mouseReleaseEvent(QMouseEvent*) {
    emit clicked();
}


// рисуем по часовой стрелке: "Список алгоритмов АЗ ПЗ"
void AnimWidget::drawCircleText() {

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

    double r = dial->width()/2;
    double x[NUM],X = double(dial->x() +r -0);
    double y[NUM],Y = double(dial->y() +r-10);

    int i;
    double angle, phi;
    const int NN =6;
    int dy[NN] = {1 ,4, 7 , 11, 17, 25};
    int dx[NN] = {10, 20, 30, 50, 65, 80 };
    const double Mult =3;
    int w;
    for(angle=0, i=0; i<NUM && angle<360; i++, angle += 360/NUM) {
        list << new QLabel( this );
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


void AnimWidget::on_dial_valueChanged(int i) {
    //list[i]->setStyleSheet("QLabel { background-color : red; color : blue; }");
    list[i]->setStyleSheet("QLabel {"
                                  "background-color : lightgray;"
                                 "border-style: solid;"
                                 "border-width: 1px;"
                                 "border-color: gray; "
                                 "}");
}

void AnimWidget::on_dial_sliderMoved(int i) {
    lw = list[i]->width();
    lh = list[i]->height();
    list[i]->resize(lw*2, lh*2);
    list[i]->setFont(QFont("Times New Roman", 18,-1,true));
    list[i]->setStyleSheet("QLabel {"
                           "border-color: lightgray;"
                           "background-color : lightgray;"
                           "color : green; "
                           "}"); //background-color : lightgray;
    list[i]->raise();
    if(lastPos>=0) {
        list[lastPos]->resize(lw, lh);
        list[lastPos]->setStyleSheet("QLabel {"
                                 "border-style: solid;"
                             "border-width: 1px;"
                             "border-color: lightgray; "
                             "background-color : white; color : black;"
                             "}");
         list[lastPos]->setFont(QFont("Times New Roman", 9,-1,true));
    }
    lastPos = i;
}




