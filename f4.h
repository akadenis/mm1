#ifndef F4_H
#define F4_H

#include <QWidget>

namespace Ui {
class f4;
}

class f4 : public QWidget
{
    Q_OBJECT

public:
    explicit f4(QWidget *parent = 0);
    ~f4();

private:
    Ui::f4 *ui;
};

#endif // F4_H
