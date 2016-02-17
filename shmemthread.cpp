#include "shmemthread.h"
#include <QDebug>

//const QString ShMemThread::key = "OurSharedMemory";

ShMemThread::ShMemThread(QString key, bool reader, QObject *parent) :
QThread(parent),
enable(true),
key(key),
sharedMemory(key) {
    if (!sharedMemory.create(size)) {
        qDebug() << sharedMemory.errorString();
        if (sharedMemory.error() == QSharedMemory::AlreadyExists) {
            if (!reader)
                sharedMemory.attach();
        } else {
            return;
        }
    }
    qDebug() << "Open shared Memory. Key " << sharedMemory.nativeKey();
}

void ShMemThread::setToArray(int start, int len, const uint8_t* from) {
    //@todo check for bad values of start and len
    if (reader)
        return;
    memcpy(my_array + start, from, len);
}

void ShMemThread::run() {

    while (enable) {
            readFromShMem();
        msleep(200); // sleep 200 мс
    }
    if (sharedMemory.isAttached()) sharedMemory.detach();

}

void ShMemThread::readFromShMem() {
    if (sharedMemory.attach(QSharedMemory::ReadOnly)) {
        sharedMemory.lock();
        memcpy(my_array, (uint8_t*) sharedMemory.constData(), qMin(sharedMemory.size(), MaxShMemSize));
        sharedMemory.unlock();
        sharedMemory.detach();
    }

}

ShMemThread::~ShMemThread() {
    while (isRunning()) {
        enable = false;
        wait();
    }
}
