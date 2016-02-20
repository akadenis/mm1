#ifndef FORM3_H
#define FORM3_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "dataTableModel.h"
#include "ethtesttv.h"
#include "ChannelDataModel.h"
#include "contentsdlg.h"
#include <QString>
#include <QTimer>
#include <QLabel>
#include "formula.h"
//#include "dlgppn.h"
#include "ref.h"
#include "referenceppn.h"

#define PpnPages 6;
#define PPnLabelPerPageMax 50


// функции для изменения текста в метках и

//void val(QLineEdit *ed, int adr) {
    //ed->setText(QString::number(dicAa->tWord(adr), 'f', 1) + QString::fromUtf8(" c"));
    //ed->setText(QString::number(array[adr], 'f', 1) + QString::fromUtf8(" c"));
//}
//void val(QLabel *ed, int adr) {
    //ed->setText(QString::number(array[adr], 'f', 1) + QString::fromUtf8(" c"));
//}



namespace Ui {
class Form3;
}

class Form3 : public QWidget, public Formula
{
    Q_OBJECT

private:
    int lastMousePosX, lastMousePosY;
    int dig[4], digCnt;
    static const int lbTblMAX = 24;
    QLabel *lbTbl[lbTblMAX]; // для таблицы

public:

    QLabel *lbFrameNum;
    ContentsDlg *dlg;

    explicit Form3(QWidget *parent = 0);
    ~Form3();
    bool eventFilter(QObject *target, QEvent *event);

    DataTableModel *mdlDataBus;
    EthTestTV *ethTestTV;
    ChannelDataModel *chanDataMdl;
    // для желтой рамки
    void imit(QFrame *lb);

    // вспомогательные функции для отрисовки лэйблов и линий
    void ln(QFrame *lb, int redFlag, int yellowFlag);

    void ln2(QFrame *lb1, QFrame *lb2, int redFlag, int yellowFlag);

    void ln3(QFrame *lb1, QFrame *lb2,QFrame *lb3, int redFlag, int yellowFlag);

    void lb(QLabel *lb, int flag);

    void cl(QLabel *lb, int b1, int b2);

    void lb(QLabel *lb, QColor color);

    void red(QLabel *lb);

    void black(QLabel *lb);

    void pbColor(QPushButton *pb, bool color);

    void pbColor(QPushButton *pb, QColor color);

    void l1(QLabel *lb, int b);
    void l2(QLabel *lb, int b);
    // закрашенный треугольник (0-зеленый, 1-красный)
    void triangle(QPainter *painter, int up, int x, int y, int color=0 );

    //extern unsigned char *ar;
    //unsigned char ar[1536*3];

    void setPage (int n); // выбрать страницу,  с ППН или алг, или главн
    void setPpnPage (int n); // выбрать страницу ППН

    // обобщенный слайд
    void commonSlide();

    // визуализация входов алгоритмов
    void inputs();

    // таблица ППН, отрисовка выходов за границу измерений (стрелок вверх-вниз)
    void ppn();

    // таблица ППН, тек.значения (и цвет)
    void ppn1();

    // реальн.знач.уставок
    void ustav();

    void fail_E();

    // для отрисовки вертикального текста
    void drawVTxt(QPainter *painter, const QPoint& p, const QString& str);

    enum SigType {SigInD, SigInA};

    // отрисовка вх.дискр сигналов для схем алгоритмов (??)
    void i1(SigType, int x, int y, int w, int h);
    //void an1(int x, int y, int w, int h);
    enum DevType { in151, out155az, out155pz, pca };
    // отрисовка слайдов дискр сигналов
    void paintEvent1(DevType type);

    void paintEvent(QPaintEvent* e);

    int timerId;

  protected:
      void timerEvent(QTimerEvent *event);

private slots:
      void on_dial_valueChanged(int value);
      void onHideFrameNumbers();
      void onHide2Digit();
      //void on_verticalScrollBar_rangeChanged(int min, int max);

private:
    void keyPressEvent(QKeyEvent * ev);
    //void mouseMoveEvent(QMouseEvent * ev);
    QTimer *timer, *tmFrameNumber;
    bool hideFrameNumbersTimerEnabled, hide2DigitTimerEnabled;

    void timerBell();
    Ref *ref;
    referencePpn *ppnRef;
    int ix; // индекс (номер) текущего слайда
    int discrSlideCurr; // номер текущего экрана (0..3) на слайде ИК

public:
    Ui::Form3 *ui;

};

#endif // FORM3_H
