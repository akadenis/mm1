#ifndef _1_LIST
#define _1_LIST
#include <QList>
#include <QVector>
#include <QString>


// соединяются с:

enum EType {
    TIMER, M34, AND, OR, OUT
};

struct ValStr {
    int n;
    EType type;
};
struct SelAddon {
    int i;
    //ValStr valStr[10];
    QVector<ValStr> valStr;
};

#endif // 1_LIST

