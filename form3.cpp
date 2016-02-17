#include <QLabel>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QInputDialog>
#include <QtGlobal>
#include "form3.h"
#include "ui_form3.h"
#include "contentsdlg.h"
#include "constants.h"
#include "ethrecv.h"
//#include "dlgppn.h"
#include "referenceppn.h"
#include <QDesktopWidget>

extern int ethPackSend();
extern int ethPackBuild();

//static QString lc(int v) {
//    QString res;
////    if(v)
////        res = QString(" <html><head/><body><span style=\"color:#112233;\">%1</span></body></html>").arg(s);
////    else
////        res = QString(" <html><head/><body><span style=\"color:#000000;\">%1</span></body></html>").arg(s);
//    return res;
//}

//ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//ui->tableWidget->setColumnWidth(id_colum, width_colum);
//ui->tableWidget->setColumnHidden(id_colum, true/false);



Form3::Form3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3)
{
    ethPackBuild();

    ix=0;
    hideFrameNumbersTimerEnabled =hide2DigitTimerEnabled = false;
    lastMousePosX=lastMousePosY=0;
    dig[0] = dig[1] = 0; digCnt = 0;
    ui->setupUi(this);
    move(100,100);
    lbFrameNum = new QLabel(this);
    lbFrameNum->setGeometry(240,130,291,311);
    QFont font = lbFrameNum->font(); //создание объекта класса QFont копированием свойсв QFont у QLabel
    font.setPointSize(200); //установка высоты шрифта 200
    lbFrameNum->setFont(font);
    lbFrameNum->hide();

    dlg = new ContentsDlg(this);
    setWindowFlags(Qt::FramelessWindowHint);

    mdlDataBus = new DataTableModel();
    ethTestTV = new EthTestTV();
    chanDataMdl = new ChannelDataModel();

    ui->tableView->installEventFilter(this);
    ui->dial->installEventFilter(this);
    ui->tv1->installEventFilter(this);
    ui->listWidget->installEventFilter(this);
    ui->listWidget_2->installEventFilter(this);
    ui->listWidget_3->installEventFilter(this);


    ui->tableView->setModel(mdlDataBus);
    ui->tableView->show();

    ui->tv1->setModel(ethTestTV);
    ui->tv1->show();

    timerId = startTimer(1000);

    // заполняем таблицу вх. сигналов на слайде 2
        QFont f;
    f.setBold(true);
    f.setFamily("Tahoma");
    f.setItalic(true);
    f.setPointSize(15);


    ref = new Ref(this);
    ref->hide();
//    QDesktopWidget desktop;
//    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
//    QPoint topLeft = rect.topLeft();
//    ref->move(topLeft);

    ppnRef = new referencePpn(this);
    ppnRef->hide();
//    ppnRef->move(topLeft);
}

Form3::~Form3()
{
    killTimer(timerId);
    for(int i=0; i<lbTblMAX; i++)
        delete lbTbl[i];
    delete ui;
}

bool Form3::eventFilter(QObject *target, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = (QKeyEvent *)event;
        int key = keyEvent->key();
        if (key == Qt::Key_Left || key == Qt::Key_Right ) {
            //focusNextPrevChild(true);
            keyPressEvent((QKeyEvent*)event);
            return true;
        }
        else {
            int ix = ui->stackedWidget->currentIndex();
            if(ix==19) {
                if(key == Qt::Key_Down)
                    ui->dial->setValue( ui->dial->value()>0?ui->dial->value() - 1:0);
                if(key == Qt::Key_Up)
                    ui->dial->setValue( ui->dial->value() < 12? ui->dial->value() + 1 : 12);
                return true;
            }
        }

    }
    return QWidget::eventFilter(target, event);
}

bool testMode; // режим для проверки отсветки слайдов без аппаратуры: буфер данных не обновляется, просто
              // по адресу <adr> записывает слово <val>  в массив array соотв. класса наследника - только для проверки с


// соглашения по названиям переменных: fr1 = фрейм 1, in1 = вход 1, val3 = значение входа 3
void Form3::inputs() {
}


// TODO
// управление переходами со слайда на слайд с пом. шара (мыши).
//void Form3::mouseMoveEvent(QMouseEvent * event) {
//    int d = event->x() - lastMousePosX;
//    QStackedWidget *sw = ui->stackedWidget;
//    if(d > 10) {
//        sw->setCurrentIndex(( sw->currentIndex() <sw->count()-1 )? sw->currentIndex() + 1 : 0);
//         lastMousePosX = event->x();
//    }
//    else if(d < -10) {
//        sw->setCurrentIndex((sw->currentIndex() > 0 )? sw->currentIndex()-1 : sw->count()-1);
//         lastMousePosX = event->x();
//    }
//    //lastMousePosX = event->x();
//    //lastMousePosY = event->y();
//}

void Form3::onHideFrameNumbers () {
    if(hideFrameNumbersTimerEnabled) {
        ui->stackedWidget->setCurrentIndex( dig[0]-Qt::Key_0 );
        lbFrameNum->hide();
        digCnt = 0;
        hideFrameNumbersTimerEnabled=false;
        hide2DigitTimerEnabled = false;
    }
}
void Form3::onHide2Digit() {
    if(hide2DigitTimerEnabled) {
        lbFrameNum->hide();
    }

}

static int discrSlideCurr = 0;

void Form3::keyPressEvent(QKeyEvent * ev) {
    QStackedWidget *sw = ui->stackedWidget;
    //if(!testEnabled) return;
    bool ok;
    ix = sw->currentIndex();
    int key = ev->key();
    if(key == Qt::Key_F12) {
        if(testMode == true) {
            QMessageBox mb;
            //mb.setText(tr("Ручная правка данных отключена"));
            //mb.setInformativeText( tr("Чтение из аппаратуры восстановлено") );
            mb.exec();
            testMode=false;
        }
    }
    else if(key == Qt::Key_F11) {
        QString text = QInputDialog::getText(this,
            "",//tr("Ручная правка данных"),
            "",//tr("Чтение из аппаратуры выключено. Введите через запятую: адрес, значение"),
            QLineEdit::Normal, 0, &ok);
        if (ok && !text.isEmpty()) {
            QStringList slist = text.split(",");
            int dev=slist[0].toInt(&ok);  if(!ok) return;
            int adr=slist[1].toInt(&ok);  if(!ok) return;
            int val=slist[2].toInt(&ok);  if(!ok) return;
            valData[dev][adr] = val;
        }
        testMode = true;
    }
    else if(key == Qt::Key_Backspace) {
        ref->show();
        ref->setFocus();
    }

    else if(key == Qt::Key_Slash) { // меню ППН
        if(ix==12) { // только для
            ppnRef->show();
            ppnRef->setFocus();
        }
    }

    else
    if(key == Qt::Key_Right) { // след.страница
        // если были на слайде алгоритма, переходим сразу на 14й слайд (параметры ИК)
        if((ix>=1 && ix<=11))
            sw->setCurrentIndex(12);
        else
            sw->setCurrentIndex( (ix<(sw->count()-1))? ix+1 : 0);
    }
    else if(key == Qt::Key_Left) {// предыд.страница
        // если были на слайде алгоритма, переходим на 1й слайд
        if(ix>=1 && ix<=11)
            sw->setCurrentIndex(0);
        else if(ix==12) // если были на таблице ИК, на первый слайд с алгоритмами
            sw->setCurrentIndex(1);
        else
            sw->setCurrentIndex(ix > 0? ix-1 : sw->count()-1);


    }
    else if(key == Qt::Key_Down) { // след.слайд в группе слайдов
        if(ix==12) { // если мы на таблице ППН
            ui->sw2->setCurrentIndex(( ui->sw2->currentIndex() <ui->sw2->count()-1 )? ui->sw2->currentIndex() + 1 : 0);
        }
        else if(ix>=1 && ix<=11) { // если на алгоритмах защит
            sw->setCurrentIndex( (ix<11)? ix+1 : 1);
        }
        else if(ix==13) { // слайд дискр сигналов
            discrSlideCurr<3?discrSlideCurr++:discrSlideCurr=0;
//            switch(discrSlideCurr) {
//            case 0: // вх 151,152
//                paintEvent1(in151);
//                break;
//            case 1:
//                paintEvent1(out155az);
//                break;
//            case 2:
//                paintEvent1(out155pz);
//                break;
//            case 3:
//                paintEvent1(pca);
//                break;
//            }
            update();

        }

    }
    else if(key == Qt::Key_Up) { // предыд.страница
        if(ix==12) { // если мы на таблице ППН
            ui->sw2->setCurrentIndex((ui->sw2->currentIndex() > 0 )? ui->sw2->currentIndex()-1 : ui->sw2->count()-1);
        }
        else if(ix>=1 && ix<=11) { // если на алгоритмах защит
            sw->setCurrentIndex( (ix>1)? ix-1 : 11);
        }
        else if(ix==13) { // слайд дискр сигналов
            discrSlideCurr>0?discrSlideCurr--:discrSlideCurr=3;
            update();
        }

    }
    // слайд дискретных сигналов
   // (ix==14)? discrSlide = true : discrSlide = false;

//    else if(key >= Qt::Key_0 && key <= Qt::Key_9) { // двузначный номер слайда
//        sw->setCurrentIndex(ev->key()-Qt::Key_0);
//    }
#if 0
    else if(key >= Qt::Key_0 && ev->key() <= Qt::Key_9) { // двузначный номер слайда
        dig[digCnt] = ev->key();
        if (digCnt==0) {
            QTimer::singleShot(2000,Qt::CoarseTimer , this, SLOT(onHideFrameNumbers()));
            hideFrameNumbersTimerEnabled = true;
            hide2DigitTimerEnabled = false;
            digCnt++;
            lbFrameNum->setText(QString::number(dig[0]-Qt::Key_0));
            lbFrameNum->setVisible(true);
        }
        else {
            hideFrameNumbersTimerEnabled = false;
            hide2DigitTimerEnabled = true;
            sw->setCurrentIndex( ((dig[0]-Qt::Key_0) * 10) + (dig[1]-Qt::Key_0) );
            lbFrameNum->setText( QString::number((dig[0]-Qt::Key_0) *10)
                               + QString::number( dig[1]-Qt::Key_0) );
            QTimer::singleShot(1000,Qt::CoarseTimer , this, SLOT(onHide2Digit()));
            digCnt=0;
        }

    }
#endif
}

const int RegimyAFSZ_N=11;
extern unsigned char lastCnt[ETH_SRC_NUM_MAX];
extern unsigned char ethErrFlag[ETH_SRC_NUM_MAX];
unsigned char timedCnt[ETH_SRC_NUM_MAX];
void Form3::timerEvent(QTimerEvent *event) {
    // отображение алгоритмов (слайды 3...)
    //inputs();
    int ix = ui->stackedWidget->currentIndex();
    if(ix==12) {
        ppn();
        ppn1();
        ustav();
    }
    if(ix==18)
        fail_E();
    // технологич.слайд: отобразить кол-во ошибок из блоков 151-2 и 152-1
//    extern int errCnt[ETH_SRC_NUM];
//    ui->lcd151_2->display(errCnt[1]);
//    ui->lcd152_1->display(errCnt[0]);

    // слайд2 таблицы входных сигналов
    // режим АФСЗ
    QString RegimyAFSZ[RegimyAFSZ_N] {"ВЫКЛ.","ПРОВ.ЗАЩИТ","ПОВЕРКА ИК","ПОВЕРКА ПС","УСТ.ВХ.ПАРАМ"};
    //QString smthstr[] {  "АЗ/ПЗ", "ручной/автоматизированный", "вверх", "вниз", "пуск", "стоп","сброс"};


    // 2й слайд: режим АФСЗ
    int mode = valData[pkc][0];
    if (mode<RegimyAFSZ_N)
        ui->lbRegimAfsz->setText(RegimyAFSZ[mode]);

    ethPackSend();
    //commonSlide();

    // проверка ошибок ethernet
    for(int i =0;i<ETH_SRC_NUM;i++) {
        if(timedCnt[i] == lastCnt[i])
            ethErrFlag[i]=1;
        timedCnt[i] = lastCnt[i];
    }

}

char ethName   [ETH_SRC_NUM_MAX][20] {
    "153/154 АЗ", "153/154 ПЗ",
    "151/152№1", "151/152№2",
    "157№1/2", "158№1/2",
    "155/6 АЗ №1", "155/6 АЗ №2", "155/6 ПЗ №1", "155/6 ПЗ №2",
    "ПЧА-08/9 АЗ", "ПЧА-08/9 ПЗ",
    "ПКЦ-184/5/6"};

//extern QString getDevNam(int n);
void Form3::on_dial_valueChanged(int value) {
    mdlDataBus->pkN = ui->dial->value();
    ui->lcdNumber->display(mdlDataBus->pkN);
    ui->lbCurDevName->setText(ethName[mdlDataBus->pkN]);

}

void Form3::setPage(int n) {
    ui->stackedWidget->setCurrentIndex(n);
}
void Form3::setPpnPage(int n) {
    ui->stackedWidget->setCurrentIndex(12);
    ui->sw2->setCurrentIndex(n);
}

// номер слайда (0..3) для дискр сигналов
int dSlideN=0;

void Form3::paintEvent(QPaintEvent* e) {
    int ix = ui->stackedWidget->currentIndex();

    if( ix==13 ) {
        switch(discrSlideCurr) {
        case 0: // вх 151,152
            paintEvent1(in151);
            break;
        case 1:
            paintEvent1(out155az);
            break;
        case 2:
            paintEvent1(out155pz);
            break;
        case 3:
            paintEvent1(pca);
            break;
        }
    }


}
