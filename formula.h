#ifndef FORMULA_H
#define FORMULA_H

#include <QString>
#include "ethrecv.h"

//157/158 смещения для групп в пакете в байтах
const int G3 = 104; // группа 3
const int G1 = 0; // группа 1

enum Pvk { p153az=0, p153pz=1,
           p151_1=2, p151_2=3,
           p157=4, p158=5,
           p155az1, p155az2, p155pz1, p155pz2,
           p08az, p08pz,
           pkc };

extern unsigned char valData[ETH_SRC_NUM][ETH_DATA_MAX]; // в main.cpp

struct D2 { double d1; double d2;};


struct ByteBit { int byte; int bit; double sm; double diap; }; // байт, бит, еще смещение и диапазон для P

// 0, 1:  номер байта и бита для битов имитации
// 2, 3: смещение и предельное значение для значения вычисления параметра и уставок.
// Там где нули ( и не только там:) значит неважно, и данные берутся не отсюда

enum ParType { tT, tP, tU, tI, tR, tF };

class Formula {
public:
    int im_pkc(int ix);
    double get_U (short int code3);
    double get_P (short int code3, double sm, double diap );
    double get_T (short int code1);
    double get_dT (short int code1);
    //struct D2 { double d1; double d2;};
    double get_F (short int code1);
    double get_R (short int code1);
    double get_I (short int code1);

    D2 T(short int index);
    D2 dT(short int index);
    D2 P(short int index, double sm, double diap);
    D2 U(short int index);
    D2 I(short int index);
    D2 R(short int index);
    D2 F(short int index);

    //возвращает значение бита (1|0) с номером (bit) в байте с номером (byte) из массива
    int b(int pvk, int byte, int bit);
    int b_153az(int byte, int bit);
    int s_153az(int byte, int bit, int sign=0);
    int b_153pz(int byte, int bit);
    int s_153pz(int byte, int bit, int sign=0);

    QString ws16(int pvk,int n);

    // вх: 1)номер блока, 2) номер канала (т.е. смещение от начала - в 16-битн.словах!!!). Используется для 157-158
    // возвр.слово 16-бит
    unsigned  w(Pvk pvk,int n);

    // возвращает строку из двух значений через слэш с  указ. точностью после зпт
    QString vs(D2 d, int prec);

    // цвет в зависим. от битов имитации
    QString vi(ParType type, int ix , int prec);

    // как vs, но для уставок (одно значение)
    QString us(double d, int prec);

    // знак уставки
    QString z(int v);
};

#endif // FORMULA_H
