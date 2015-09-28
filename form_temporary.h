#ifndef FORM_TEMPORARY_H
#define FORM_TEMPORARY_H

#include <QWidget>

namespace Ui {
class form_temporary;
}

class form_temporary : public QWidget
{
    Q_OBJECT

public:
    explicit form_temporary(QWidget *parent = 0);
    ~form_temporary();

private:
    Ui::form_temporary *ui;
};

#endif // FORM_TEMPORARY_H
