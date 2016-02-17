#include <QApplication>
#include <QDesktopWidget>
#include <unistd.h>
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <mutex>
#include <pthread.h>


#include "form3.h"
//#include "form.h"

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

//    f = new Form();
//    f->show();

    // оглавление пока спрячем
    mf->dlg->hide();

    QDesktopWidget desktop;
    QRect rect = desktop.availableGeometry(desktop.primaryScreen()); // прямоугольник с размерами экрана
    QPoint topLeft = rect.topLeft();
    mf->move(topLeft);

    //    QPoint center = rect.center(); //координаты центра экрана
    //    center.setX(center.x() - (mf.dlg->width()/2));  // учитываем половину ширины окна
    //    center.setY(center.y() - (mf.dlg->height()/2));  // .. половину высоты

    QPoint pos = mf->mapToGlobal( QPoint(0,0) );
    pos.setX(pos.x()+50);
    pos.setY(pos.y()+50);
    mf->dlg->move(pos);
#endif

//    Form2 f;
//    f.show();

//    FormScroll fs;
//    fs.show();




    extern void ethRead();
#if 1
    std::thread t1 (ethRead);
    //t1.setPriority(QThread::HighPriority);

//    sched_param sch;
//    int policy;
//    pthread_getschedparam(t1.native_handle(), &policy, &sch);
//    sch.sched_priority = 20;
//    if(pthread_setschedparam(t1.native_handle(), SCHED_FIFO, &sch)) {
//      //std::cout << "Failed to setschedparam: " << std::strerror(errno) << '\n';
//    }

    t1.detach();
#endif
//    Form_tek_sost_AFSZ f_tekSost;
  //  f_tekSost.show();



    return a.exec();
}
