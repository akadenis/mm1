#include <QString>
#include "constants.h"
#include "formula.h"

const ByteBit bb[52] = {
    {	436	,	4, 0, 0 }, // 0
    {	436	,	5, 0, 0	}, // 1
    {	436	,	6, 0, 0	}, // 2
    {	436	,	7, 0, 0	}, // 3
    {	437	,	0, 0, 0	}, // 4
    {	437	,	1, 0, 0	}, // 5
    {	437	,	2, 0, 0	}, // 6
    {	437	,	3, 0, 0	}, // 7
    {	437	,	4, 0, 0	}, // 8
    {	437	,	5, 0, 0	}, // 9
    {	437	,	6, 0, 0	}, // 10
    {	437	,	7, 0, 0	}, // 11
    {	438	,	0, 0, 250 }, // 12
    {	438	,	1, 0, 100 }, // 13
    {	438	,	2, 0, 0	}, // 14
    {	438	,	3, 0, 0	}, // 15
    {	438	,	4, 0, 0	}, // 16
    {	438	,	5, 0, 0	}, // 17
    {	438	,	6, 0, 0	}, // 18
    {	438	,	7, 0, 0	}, // 19
    {	439	,	0, 0, 100	}, // 20 Р ТРОП ПГ1
    {	439	,	1, 0, 100	}, // 21 Р ТРОП ПГ2
    {	439	,	2, 0, 100	}, // 22 Р ТРОП ПГ3
    {	439	,	3, 0, 100	}, // 23 Р ТРОП ПГ4
    {	439	,	4, 0, 10	}, // 24 Pзкп тпн1
    {	439	,	5, 0, 10	}, // 25 Pзкп тпн2
    {	439	,	6, -0.5, 1 }, // 26 Pгаз
    {	439	,	7, 0, 630}, // 27 Lкд
    {	440	,	0, 0, 10	}, // 28
    {	440	,	1, 0, 10	}, // 29
    {	440	,	2, 0, 10	}, // 30
    {	440	,	3, 0, 10	}, // 31
    {	440	,	4, 0, 16368	}, // 32
    {	440	,	5, 0, 16368	}, // 33
    {	440	,	6, 0, 16368	}, // 34
    {	440	,	7, 0, 16368	}, // 35
    {	441	,	0, 0, 400	}, // 36 Lпг1
    {	441	,	1, 0, 400	}, // 37 Lпг1
    {	441	,	2, 0, 400	}, // 38 Lпг1
    {	441	,	3, 0, 400	}, // 39 Lпг1
    {	441	,	4, 0, 0	}, // 40
    {	441	,	5, 0, 0	}, // 41
    {	441	,	6, 0, 0	}, // 42
    {	441	,	7, 0, 0	}, // 43
    {	442	,	0, 0, 0	}, // 44
    {	442	,	1, 0, 0	}, // 45
    {	442	,	2, 0, 0	}, // 46
    {	442	,	3, 0, 0	}, // 47
    {	442	,	4, 0, 0	}, // 48
    {	442	,	5, 0, 0	}, // 49
    {	442	,	6, 0, 0	}, // 50
    {	442	,	7, 0, 0	}  // 51
};

double Formula::get_U (short code3) {
    double res = ((double)code3 - 655) * 31.492 / 2621 ;
    return res;
}

double Formula::get_P (short code3, double sm, double diap ) {
    double res = ((double)code3 - 655) * diap/2621 + sm ;
    return res;
}

double Formula::get_T (short code1) {
    double res = ((double)code1 - 655) * 400 / 2621;
    return res;
}

double Formula::get_dT (short code1) {
    double res = ((double)code1) * 400 / 2621 - 400;
    return res;
}

double Formula::get_F (short code1) {
    double res = ((double)code1 - 655) * 10 / 2621 + 45;
    return res;
}

double Formula::get_R (short code1) {
    double res = ((double)code1 - 655) * 39.1 / 2621 + 100;
    return res;
}

double Formula::get_I (short code1) {
    double res = ((double)code1 - 655) * 16 / 2621 + 4;
    return res;
}

D2 Formula::T(short index) {
    short v1 = w(p157, index);
    short v2 = w(p158, index);
    D2 r;
    r.d1 = get_T(v1);
    r.d2 = get_T(v2);
    return r;
}

D2 Formula::dT(short index) {
    short v1 = w(p157, index);
    short v2 = w(p158, index);
    D2 r;
    r.d1 = get_dT(v1);
    r.d2 = get_dT(v2);
    return r;
}


//    D2 P(short index, int sm, int diap) {
//        short v1 = w(p157, index);
//        short v2 = w(p158, index);
//        D2 r;
//        r.d1 = get_P(v1, sm, diap);
//        r.d2 = get_P(v2,  sm, diap);
//        return r;
//    }

D2 Formula::P(short index, double sm, double diap) {
    short v1 = w(p157, index);
    short v2 = w(p158, index);
    D2 r;
    r.d1 = get_P(v1, sm, diap);
    r.d2 = get_P(v2,  sm, diap);
    return r;
}


D2 Formula::U(short index) {
    short v1 = w(p157, index);
    short v2 = w(p158, index);
    D2 r;
    r.d1 = get_U(v1);
    r.d2 = get_U(v2);
    return r;
}
D2 Formula::I(short index) {
    short v1 = w(p157, index);
    short v2 = w(p158, index);
    D2 r;
    r.d1 = get_I(v1);
    r.d2 = get_I(v2);
    return r;
}

D2 Formula::R(short index) {
    short v1 = w(p157, index);
    short v2 = w(p158, index);
    D2 r;
    r.d1 = get_R(v1);
    r.d2 = get_R(v2);
    return r;
}
D2 Formula::F(short index) {
    short v1 = w(p157, index);
    short v2 = w(p158, index);
    D2 r;
    r.d1 = get_F(v1);
    r.d2 = get_F(v2);
    return r;
}

//возвращает значение бита (1|0) с номером (bit) в байте с номером (byte) из массива
int Formula::b(int pvk, int byte, int bit) {
    byte--;
    return (valData[pvk][byte]>>bit) & 1;
}
int Formula::b_153az(int byte, int bit) {
    return b(p153az,byte,bit);
}

int Formula::s_153az(int byte, int bit, int sign) {
    int res = sign? b(p153az,byte,bit)?0:1 : b(p153az,byte,bit)?1:0;
    return res;
}

int Formula::b_153pz(int byte, int bit) {
    return b(p153pz,byte,bit);
}
int Formula::s_153pz(int byte, int bit, int sign) {
    int res = sign? b(p153pz,byte,bit)?0:1: b(p153pz,byte,bit)?1:0;
    return res;
}

QString Formula::ws16(int pvk,int n) {
    short w = *(( short*)(&valData[pvk][n]));
    return QString(w);
}

// вх: 1)номер блока, 2) номер канала (т.е. смещение от начала - в 16-битн.словах!!!). Используется для 157-158
// возвр.слово 16-бит
unsigned  Formula::w(Pvk pvk,int n) { // номер блока и номер канала - для 157/158
    unsigned short *w = (unsigned short*)valData[pvk];
    return w[n];
}

// возвращает строку из двух значений через слэш с  указ. точностью после зпт
QString Formula::vs(D2 d, int prec) {
    QString s= QString::number(d.d1,'f',prec);  //000.0
    s+= "/";
    s+= QString::number(d.d2,'f',prec);  //000.0";
    return s;
}

// вх: номер канала
// возвращает значение бита имитации ПКЦ, соотв. каналу
int Formula::im_pkc(int ix) {
    if(ix>=G3)
        ix-=G3; // на всякий случай

    int byte = 71+ix/8;
    int bit = ix % 8;
    byte--;
    int res= (valData[pkc][byte]>>bit) & 1;
    return res;
}

// цвет в зависим. от битов имитации
QString Formula::vi(ParType type, int ix , int prec) {
    D2 d;
    switch (type) {
    case tT:
        d = T(ix);
        break;
    case tP:
        d = P(ix, bb[ix-G3].sm,bb[ix-G3].diap );
        break;
    case tU:
        d = U(ix);
        break;
    case tI:
        d = I(ix);
        break;
    case tR:
        d = R(ix);
        break;
    case tF:
        d = F(ix);
        break;
    }
    if(ix>=G3)
        ix-=G3;

    QString res, s= QString::number(d.d1,'f',prec);  //000.0
    s+= "/";
    s+= QString::number(d.d2,'f',prec);  //000.0";
    int im;
    int byte  = bb[ix].byte;
    int bit =  bb[ix].bit;
    if(type == tU || type==tI || type == tR)
        im = im_pkc(ix);
    else  // само значение параметра
        im = b(p157, byte, bit);

    if(im)
        res = QString(" <html><head/><body><p><span style=\" color:#ff0000;\">%1</span></p></body></html>").arg(s);
    else
        res = QString(" <html><head/><body><span style=\"color:#000000;\">%1</span></body></html>").arg(s);
    return res;
}

// как vs, но для уставок (одно значение)
QString Formula::us(double d, int prec) {
    QString s= QString::number(d,'f',prec);  //000.0
    return s;
}

// знак уставки
QString Formula::z(int v) {
    if(v==0)
        return "≤";
    else return "≥";


}
