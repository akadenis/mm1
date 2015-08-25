#ifndef FORM_TEK_SOST_AFSZ_H
#define FORM_TEK_SOST_AFSZ_H

#include <QWidget>
#include <QLabel>
#include <QList>

using namespace std;



namespace Ui {
class Form_tek_sost_AFSZ;
}

class Form_tek_sost_AFSZ : public QWidget
{
    Q_OBJECT

public:
    explicit Form_tek_sost_AFSZ(QWidget *parent = 0);
    ~Form_tek_sost_AFSZ();


private slots:
    void on_dial_valueChanged(int value);

    void on_dial_sliderMoved(int position);

private:

    static const int NUM= 33;

    Ui::Form_tek_sost_AFSZ *ui;

    QList< QLabel* > list;

    //map <double,int> angVsN;

    void drawCircleText();

    int lastPos;

};

#endif // FORM_TEK_SOST_AFSZ_H
