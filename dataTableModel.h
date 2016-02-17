#ifndef DATATABLEMODEL_H
#define DATATABLEMODEL_H

#include <QAbstractTableModel>
#include <QVariant>

typedef unsigned short int uint16_t ;
typedef unsigned int uint32_t ;

class DataTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    //explicit DataBusTableModel(QObject *parent = 0);
    DataTableModel();
    int pkN;

signals:

public slots:


private:



    int dataLen;
    void timerEvent(QTimerEvent*);

//    Dic *dic;
    bool flag;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent= QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

};

#endif // DATATABLEMODEL_H
