#ifndef REF_H
#define REF_H

#include <QWidget>

namespace Ui {
class Ref;
}

class Ref : public QWidget
{
    Q_OBJECT

public:
    explicit Ref(QWidget *parent = 0);
    ~Ref();

private:
    Ui::Ref *ui;
};

#endif // REF_H
