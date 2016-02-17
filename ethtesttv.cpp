#include "ethtesttv.h"
#include <QColor>
#include <string.h>
#include "ethrecv.h"

/* 1: Нейтронная мощность реактора более 40% от номинальной,\
2: Нейтронная мощность реактора более 75% от номинальной,\
3: Нейтронная мощность реактора больше уставки АЗ,\
4: Нейтронная мощность реактора больше уставки ПЗ-1,\
5: Нейтронная мощность реактора больше уставки ПЗ-2,\
6: Период реактора менее 10 с,\
*/


//extern unsigned ethErrData[ETH_SRC_NUM];
extern unsigned int errCnt[ETH_SRC_NUM_MAX];
extern unsigned char cntPk[ETH_SRC_NUM_MAX];
extern char ethName[ETH_SRC_NUM_MAX][20];

static const int rowsN = ETH_SRC_NUM_MAX;


EthTestTV::EthTestTV() : QAbstractTableModel() {
//    memcpy(dic_out->getArray(), dic->getArray(), dic->getDataLength() * sizeof (uint16_t));
    pkN = 0;
    startTimer(300);
}

int EthTestTV::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return rowsN;//dic->getDataLength();
    //    else return 0;
}

int EthTestTV::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return 5;
    //    else return 0;
}

void EthTestTV::timerEvent(QTimerEvent*) {
//    if(flag){
//    for (int i = 0; i < dic->getDataLength(); i++) {
//        if (array[i] != dic->getArray()[i])
//            emit dataChanged(this->index(i, 1), this->index(i, 3));
//    }
//    memcpy(array, dic->getArray(), dic->getDataLength() * sizeof (uint16_t));
//    }else {
//        flag = true;
//        memcpy(array, dic->getArray(), dic->getDataLength() * sizeof (uint16_t));
//    }
//   // emit dataChanged;

    emit dataChanged(this->index(0, 1), this->index(ETH_SRC_NUM, 3));
}

QVariant EthTestTV::data(const QModelIndex &index, int role) const {
    //if(pkN>ETH_SRC_NUM || pkN<0) return QString("-");
    if (role == Qt::DisplayRole) {
        QString answ;
        if(index.row() > rowsN) {
            answ = "0";
            return answ;
        }
        int r = index.row();
        switch (index.column()) {
            case 0:
                answ = QString::number(r);
                break;
            case 1:
                answ = QString(ethName[r]);
                break;
            case 2:
                answ = QString::number(errCnt[r], 10);
                break;
            case 3:
                answ = QString::number(cntPk[r], 10);
                break;
            case 4:
                answ = QString::number(cntPk[r], 10);


                answ = QString("");
                break;

        }
        return answ;
    } else if (role == Qt::BackgroundColorRole) {
        QVariant v;
        if (index.row() % 2) {
            v = QColor(Qt::gray);
        } else
            v = QColor(Qt::lightGray);
        return v;
    }
    return QVariant();
}

QVariant EthTestTV::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return QVariant(QString::fromUtf8("№"));
                case 1: return QVariant(QString::fromUtf8("Название"));
                case 2: return QVariant(QString::fromUtf8("Ошибки"));
                case 3: return QVariant(QString::fromUtf8("№ пакета"));
//                case 4: return QVariant(QString::fromUtf8("Название"));
                default: return QVariant();
            }
        }
    } else if (role == Qt::BackgroundColorRole) {
        QVariant v;
        if (section % 2)
            v = QColor(Qt::gray);
        else
            v = QColor(Qt::lightGray);
        return v;
    }
    return QVariant();
}

