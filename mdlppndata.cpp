#include <QColor>
#include <string.h>
#include "mdlppndata.h"
#include "ppn.h"

MdlPpnData::MdlPpnData() : QAbstractTableModel() {
//    memcpy(dic_out->getArray(), dic->getArray(), dic->getDataLength() * sizeof (uint16_t));
    startTimer(300);

}

int MdlPpnData::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return Rows;//dic->getDataLength();
    //    else return 0;
}

int MdlPpnData::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;
    else
        return 5;
    //    else return 0;
}

void MdlPpnData::timerEvent(QTimerEvent*) {
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

    emit dataChanged(this->index(0, 1), this->index(Rows, 3));
}

QVariant MdlPpnData::data(const QModelIndex &index, int role) const {
    //if(pkN>15 || pkN<0) return QString("-");
    if (role == Qt::DisplayRole) {
        QString answ;
        if(index.row() > Rows) {
            answ = "0";
            return answ;
        }
        int r = index.row();
        //int c = index.column();
        //answ = signal_strings[r][c];

        switch (index.column()) {
            case 0:
                answ = signal_strings[r];
                       // QString::number(r);
                break;
            case 1:
                if(r<4)
                    answ = ppnCol2[r];
                else answ = QString("0");
                break;
//            case 2:
//                answ = QString("");//::number();
//                break;
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
    if (role == Qt::ForegroundRole) {
        if (index.column() == 1)   {
            //QVariant value = index.data(); // the data is in DisplayRole
            int v =1;
            if(v > 0)
                return QColor(Qt::blue); //QVariant::fromValue(QColor(Qt::blue));
        }

    }

    return QVariant();
}

QVariant MdlPpnData::headerData(int section, Qt::Orientation orientation, int role) const {
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



