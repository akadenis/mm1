#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    void i1();
void paintEvent(QPaintEvent*);

private:
    Ui::Form *ui;
};

#endif // FORM_H
