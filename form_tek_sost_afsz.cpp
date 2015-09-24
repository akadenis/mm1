#include "form_tek_sost_afsz.h"
#include "ui_form_tek_sost_afsz.h"
#include <math.h>
#include <map>
#include "dataTableModel.h"
#include <QPropertyAnimation>

Form_tek_sost_AFSZ::Form_tek_sost_AFSZ(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_tek_sost_AFSZ)
{
    lastPos = -1;


    DataTableModel* model = new DataTableModel;

    ui->setupUi(this);

    ui->tbTekSostAfsz->setModel(model);
    //ui->tbTekSostAfsz->resizeColumnsToContents();

    aw = new AnimWidget(this);
    aw->resize(width(),height());
    //aw->resize(500,500);
    aw->raise();
    aw->move(x(),y());
    aw->show();

    //ui->widget->move(ui->widget->x() - ui->widget->width()  +50, ui->widget->x());

    //ui->dial->setMinimum(0);
    //ui->dial->setMaximum(NUM-1);
    //drawCircleText();

    st1 = new QState();
    st2 = new QState();

    st1->assignProperty(aw, "geometry", QRect( 100,  100, 600, 600));
    //st2->assignProperty(aw, "geometry", QRect(50, 50, 200, 200));
    st2->assignProperty(aw, "geometry", QRect(0, 0, 700, 700));

    /* define transitions between states by clicking on main window*/
    st1->addTransition(aw, SIGNAL(clicked()), st2);
    st2->addTransition(aw, SIGNAL(clicked()), st1);

    /* adding states to state machine */
    machine_.addState(st1);
    machine_.addState(st2);
    machine_.setInitialState(st1);


    //QPropertyAnimation* an1 = new QPropertyAnimation(photo_, "geometry");
    QPropertyAnimation* an1 = new QPropertyAnimation(aw, "geometry");
    machine_.addDefaultAnimation(an1);

    an1->setEasingCurve(QEasingCurve::InOutCubic);
    an1->setDuration(1500);


}

void Form_tek_sost_AFSZ::mouseReleaseEvent(QMouseEvent*) {
    emit clicked();

    machine_.setInitialState(st1);

    /* starting machine */
    machine_.start();

   // if(aw->x() == )
     //   aw->move(x(),y());



}

Form_tek_sost_AFSZ::~Form_tek_sost_AFSZ()
{
    delete ui;
}

#if 0 //MYTESTBOX
#include <QMessageBox>
#include <QKeyEvent>
#include <QInputDialog>

bool testMode=false; // режим для проверки отсветки слайдов без аппаратуры: буфер данных не обновляется, просто
               // по адресу <adr> записывает слово <val>  в массив array соотв. класса наследника - только для проверки с


void Form_tek_sost_AFSZ::keyPressEvent(QKeyEvent * ev) {
    //if(!testEnabled) return;
    bool ok;
    if(ev->key() == Qt::Key_F12) {
        if(testMode == false) {
            /*QString text = QInputDialog::getText(this,
                "",//tr("Ручная правка данных"),
                "",//tr("Чтение из аппаратуры выключено. Введите через запятую: адрес, значение"),
                QLineEdit::Normal, 0, &ok);
            if (ok && !text.isEmpty()) {
                QStringList slist = text.split(",");
                int adr=slist[0].toInt(&ok);  if(!ok) return;
                int val=slist[1].toInt(&ok);  if(!ok) return;
                //dic->setData(adr,val);
            }*/
            //dic->testMode = true;
        }
        else {
            QMessageBox mb;
            //mb.setText(tr("Ручная правка данных отключена"));
            //mb.setInformativeText( tr("Чтение из аппаратуры восстановлено") );
            //mb.exec();


            testMode=false;
        }
    }
    if(ev->key() == Qt::Key_F11) {
        QString text = QInputDialog::getText(this,
            "",//tr("Ручная правка данных"),
            "",//tr("Чтение из аппаратуры выключено. Введите через запятую: адрес, значение"),
            QLineEdit::Normal, 0, &ok);
        if (ok && !text.isEmpty()) {
            QStringList slist = text.split(",");
            int adr=slist[0].toInt(&ok);  if(!ok) return;
            int val=slist[1].toInt(&ok);  if(!ok) return;
            //array[adr] = val;
        }
        testMode = true;
    }
}
#endif

