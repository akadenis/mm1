#include "mdl1.h"
#include <QColor>
#include <string.h>
#include <qt4/QtCore/qabstractitemmodel.h>





Mdl1::Mdl1() : QAbstractTableModel() {
//    this->dic = dic;
//    dicData = dic->getArray();
    flag = false;
    //array = new uint16_t[dic->getDataLength()];
    array = new uint16_t[1000];

//    memcpy(dic_out->getArray(), dic->getArray(), dic->getDataLength() * sizeof (uint16_t));

//    startTimer(300);

}

int Mdl1::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return dataLen;//dic->getDataLength();
    //    else return 0;
}

int Mdl1::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return 4;
    //    else return 0;
}

/*void Mdl1::timerEvent(QTimerEvent*) {
    if(flag){
    for (int i = 0; i < dic->getDataLength(); i++) {
        if (array[i] != dic->getArray()[i])
            emit dataChanged(this->index(i, 1), this->index(i, 3));
    }
    memcpy(array, dic->getArray(), dic->getDataLength() * sizeof (uint16_t));
    }else {
        flag = true;
        memcpy(array, dic->getArray(), dic->getDataLength() * sizeof (uint16_t));
    }
   // emit dataChanged;
}*/

QVariant Mdl1::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        QString answ;
        switch (index.column()) {
            case 0:
                answ = QString::number(index.row());
                break;
            case 1:
                   answ = QString::number(valData[index.row()]);
                break;
            case 2:
                answ = QString::number(valData[index.row()], 2);
                break;
            case 3:
                answ = QString::number(valData[index.row()], 16);
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

QVariant Mdl1::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return QVariant(QString::fromUtf8("Address"));
                case 1: return QVariant(QString::fromUtf8("Decimal"));
                case 2: return QVariant(QString::fromUtf8("Binary"));
                case 3: return QVariant(QString::fromUtf8("Hexadecimal"));
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

