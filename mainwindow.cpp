#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


#if 0 //MYTESTBOX
#include <QMessageBox>
#include <QKeyEvent>
#include <QInputDialog>

bool testMode=false; // режим для проверки отсветки слайдов без аппаратуры: буфер данных не обновляется, просто
               // по адресу <adr> записывает слово <val>  в массив array соотв. класса наследника - только для проверки с


void MainWindow::keyPressEvent(QKeyEvent * ev) {
    //if(!testEnabled) return;
    bool ok;
    if(ev->key() == Qt::Key_F12) {
        if(testMode == false) {
            QString text = QInputDialog::getText(this,
                "",//tr("Ручная правка данных"),
                "",//tr("Чтение из аппаратуры выключено. Введите через запятую: адрес, значение"),
                QLineEdit::Normal, 0, &ok);
            if (ok && !text.isEmpty()) {
                QStringList slist = text.split(",");
                int adr=slist[0].toInt(&ok);  if(!ok) return;
                int val=slist[1].toInt(&ok);  if(!ok) return;
                //dic->setData(adr,val);
            }
            //dic->testMode = true;
        }
        else {
            QMessageBox mb;
            //mb.setText(tr("Ручная правка данных отключена"));
            //mb.setInformativeText( tr("Чтение из аппаратуры восстановлено") );
            mb.exec();
            testMode=false;
        }
    }
    if(ev->key() == Qt::Key_F11) {
        QString text = QInputDialog::getText(this,
            "",//tr("Ручная правка данных"),
            "",//tr("Чтение из аппаратуры выключено. Введите через запятую: адрес, значение"),
            QLineEdit::Normal, 0, &ok);
        if (ok && !text.isEmpty()) {
            QStringList slist = text.split(",");
            int adr=slist[0].toInt(&ok);  if(!ok) return;
            int val=slist[1].toInt(&ok);  if(!ok) return;
            //array[adr] = val;
        }
        testMode = true;
    }
}
#endif
