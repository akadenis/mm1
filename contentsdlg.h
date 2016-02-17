#ifndef CONTENTSDLG_H
#define CONTENTSDLG_H

#include <QDialog>
#include <QWidget>

namespace Ui {
class ContentsDlg;
}

class ContentsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ContentsDlg(QWidget *parent = 0);
    ~ContentsDlg();
    void keyPressEvent(QKeyEvent * ev);
    int digCnt, dig[2];
private:
    Ui::ContentsDlg *ui;

};

#endif // CONTENTSDLG_H
