#include <QApplication>
#include "mainform.h"
#include "mainwindow.h"
#include "form_tek_sost_afsz.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();


    MainForm mf;
    mf.show();


//    Form_tek_sost_AFSZ f_tekSost;
  //  f_tekSost.show();



    return a.exec();
}
