#ifndef REF_H
#define REF_H
#include <QKeyEvent>
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

    int dig[2];
    int digCnt;

    void keyPressEvent(QKeyEvent * ev);

private:
    Ui::Ref *ui;
};

#endif // REF_H
