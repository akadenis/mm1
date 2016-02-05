#ifndef F2_H
#define F2_H

#include <QWidget>

namespace Ui {
class f2;
}

class f2 : public QWidget
{
    Q_OBJECT

public:
    explicit f2(QWidget *parent = 0);
    ~f2();

private:
    Ui::f2 *ui;
};

#endif // F2_H
