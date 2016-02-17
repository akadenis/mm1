#include "dataTableModel.h"
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


char tabnames[5][200] {
"0: Нейтронная мощность реактора более 5% от номинальной,\
7: Период реактора менее 20 с",
"резерв",
"Потеря силового питания СУЗ,\
Падение одного органа регулирования СУЗ,\
Вывод комплекта в опробование"
};

extern unsigned char valData[ETH_SRC_NUM][1600];
const int ethBufBytes = 1600;
static const int rowsN = ethBufBytes/4;


DataTableModel::DataTableModel() : QAbstractTableModel() {
//    memcpy(dic_out->getArray(), dic->getArray(), dic->getDataLength() * sizeof (uint16_t));
    pkN = 0;
    startTimer(300);
}

int DataTableModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return rowsN;//dic->getDataLength();
    //    else return 0;
}

int DataTableModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return 5;
    //    else return 0;
}

void DataTableModel::timerEvent(QTimerEvent*) {
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

    emit dataChanged(this->index(0, 1), this->index(399, 3));
}

QVariant DataTableModel::data(const QModelIndex &index, int role) const {
    if(pkN>15 || pkN<0) return QString("-");
    if (role == Qt::DisplayRole) {
        QString answ;
        if(index.row() > rowsN) {
            answ = "0";
            return answ;
        }
        int r = index.row();
        switch (index.column()) {
            case 0:
                answ = QString::number(r+1);
                break;
            case 1:
                answ = QString::number(valData[pkN][r]);
                break;
            case 2:
                answ = QString::number(valData[pkN][r], 2);
                break;
            case 3:
                answ = QString::number(valData[pkN][r], 16);
                break;
            case 4:
                //answ = QString(tabnames[index.row()]);
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

QVariant DataTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return QVariant(QString::fromUtf8("Адрес"));
                case 1: return QVariant(QString::fromUtf8("Dec"));
                case 2: return QVariant(QString::fromUtf8("Bin"));
                case 3: return QVariant(QString::fromUtf8("hex"));
                case 4: return QVariant(QString::fromUtf8("Название"));
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

