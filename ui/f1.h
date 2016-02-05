#ifndef F1_H
#define F1_H

#include <QWidget>

namespace Ui {
class f1;
}

class f1 : public QWidget
{
    Q_OBJECT

public:
    explicit f1(QWidget *parent = 0);
    ~f1();

private:
    Ui::f1 *ui;
};

#endif // F1_H
