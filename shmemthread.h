#ifndef SHMEMTHREAD
#define SHMEMTHREAD

#include <QThread>
#include <QSharedMemory>
#include <stdint.h>


class ShMemThread : public QThread {
    Q_OBJECT
public:
    const int MaxShMemSize = 2000;
    explicit ShMemThread(QString key, bool reader = false, QObject *parent = 0);
    void run();
    ~ShMemThread();
    void readFromShMem();
    void setToArray(int start, int len, const uint8_t* from);

    uint8_t * getMy_array() const {
        return (const_cast<uint8_t * const> (my_array) );
    }

signals:

public slots:

private:
    bool enable;
    bool reader;
    static const int size = 3098;
    QString key;
    uint8_t my_array[size];
    QSharedMemory sharedMemory;
};

#endif // ShMemThread_H
