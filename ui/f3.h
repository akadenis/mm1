#ifndef F3_H
#define F3_H

#include <QWidget>

namespace Ui {
class f3;
}

class f3 : public QWidget
{
    Q_OBJECT

public:
    explicit f3(QWidget *parent = 0);
    ~f3();

private:
    Ui::f3 *ui;
};

#endif // F3_H
