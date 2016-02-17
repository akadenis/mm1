#include <QApplication>
#include <QDesktopWidget>
#include <unistd.h>
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <mutex>
#include <pthread.h>


#include "form3.h"
#include "ethrecv.h"
unsigned char valData[ETH_SRC_NUM][ETH_DATA_MAX];

Form3 *mf;
//Form *f;

int main(int argc, char *argv[]) {



    QApplication a(argc, argv);

    // что-то не работает, блин
    execl("xset","-dpms");
    execl("xset","s","off");
    execl("~/screen_setup", "");


#if 1

    mf = new Form3();
    mf->show();

    // оглавление пока спрячем
    mf->dlg->hide();

    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint topLeft = rect.topLeft();
    mf->move(topLeft);

    QPoint pos = mf->mapToGlobal( QPoint(0,0) );
    pos.setX(pos.x()+50);
    pos.setY(pos.y()+50);
    mf->dlg->move(pos);
#endif


    extern void ethRead();
#if 1
    std::thread t1 (ethRead);

    t1.detach();
#endif



    return a.exec();
}
