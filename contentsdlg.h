#ifndef CONTENTSDLG_H
#define CONTENTSDLG_H

#include <QDialog>

namespace Ui {
class ContentsDlg;
}

class ContentsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ContentsDlg(QWidget *parent = 0);
    ~ContentsDlg();

private:
    Ui::ContentsDlg *ui;
};

#endif // CONTENTSDLG_H
