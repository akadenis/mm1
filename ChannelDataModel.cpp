#include "ChannelDataModel.h"

#include "ChannelDataModel.h"
#include <QColor>
#include <string.h>
#include "ethrecv.h"

extern unsigned ethErrData[ETH_SRC_NUM];
extern unsigned char errCnt[ETH_SRC_NUM];
extern char ethName[ETH_SRC_NUM][20];
static const int rowsN = ETH_SRC_NUM;


ChannelDataModel::ChannelDataModel() : QAbstractTableModel() {
//    memcpy(dic_out->getArray(), dic->getArray(), dic->getDataLength() * sizeof (uint16_t));
    pkN = 0;
    startTimer(300);
}

int ChannelDataModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return rowsN;//dic->getDataLength();
    //    else return 0;
}

int ChannelDataModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return 5;
    //    else return 0;
}

void ChannelDataModel::timerEvent(QTimerEvent*) {
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

QVariant ChannelDataModel::data(const QModelIndex &index, int role) const {
    //if(pkN>15 || pkN<0) return QString("-");
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
                answ = QString::number(errCnt[r], 2);
                break;
//            case 3:
//                answ = QString::number(valData[pkN][r], 16);
//                break;
//            case 4:
//                //answ = QString(tabnames[index.row()]);
//                answ = QString("");
//                break;

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

QVariant ChannelDataModel::headerData(int section, Qt::Orientation orientation, int role) const {
//    if (role == Qt::DisplayRole) {
//        if (orientation == Qt::Horizontal) {
//            switch (section) {
//                case 0: return QVariant(QString::fromUtf8("Наименование параметра"));
//                case 1: return QVariant(QString::fromUtf8("№кан"));
//                case 2: return QVariant(QString::fromUtf8("Значение"));
//                case 3: return QVariant(QString::fromUtf8("hex"));
//                case 4: return QVariant(QString::fromUtf8("Название"));
//                default: return QVariant();
//            }
//        }
//    } else
//    if (role == Qt::BackgroundColorRole) {
//        QVariant v;
//        if (section % 2)
//            v = QColor(Qt::gray);
//        else
//            v = QColor(Qt::lightGray);
//        return v;
//    }
   return QVariant();
}


