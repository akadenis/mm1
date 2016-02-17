#include "form3.h"
#include "constants.h"
#include "ui_form3.h"

QString diap2Str( QString c1, QString c2, QString s) {
    return QString("<html><head/><body><p><span style=\"font-size:12pt;color:#%1;\">↓</span><span style=\"font-size:8pt;color:#000000;\">%2</span><span style=\"font-size:12pt;color:#%3;\">↑</span></p></body></html>").arg(c1).arg(s).arg(c2);
}

QString set2D(int c1, int c2, QString s="") {
    QString s1,s2;
        if(c1==0)
            s1="008000"; // зеленый цвет
        else
            s1="ff0000"; // красный цвет
        if(c2==0)
            s2="008000"; // зеленый цвет
        else
            s2="ff0000"; // красный цвет
    return diap2Str(s1,s2,s);
}


// слайд с таблицей ППН (2й). 5 или 6 страниц будет тут
void Form3::ppn() {
    // page 1, выход за границу
    ui->p1d1_1->setText(set2D(b(p157,423,4), b(p157,430,0), "ТЭП"));  // ↑↓ грчн1
    ui->p1d1_2->setText(set2D(b(p157,423,6), b(p157,430,2), "ТСП"));
    ui->p1d2_1->setText(set2D(b(p157,424,0), b(p157,430,4), "ТЭП"));
    ui->p1d2_2->setText(set2D(b(p157,424,2), b(p157,430,6), "ТСП"));
    ui->p1d3_1->setText(set2D(b(p157,424,1), b(p157,430,5), "ТЭП"));
    ui->p1d3_2->setText(set2D(b(p157,423,4), b(p157,430,6), "ТСП"));
    ui->p1d4_1->setText(set2D(b(p157,423,5), b(p157,430,1), "ТЭП"));
    ui->p1d4_2->setText(set2D(b(p157,423,6), b(p157,430,2), "ТСП"));
    ui->p1d5_1->setText(set2D(b(p157,424,4), b(p157,431,0), "ТЭП"));
    ui->p1d5_2->setText(set2D(b(p157,424,6), b(p157,431,2), "ТЭП"));

    //page 2, выход за границу
    ui->p1_d_Ppeak->setText(set2D(b(p157,425,0), b(p157,431,4)));
    ui->p1_d_Pgpk->setText(set2D(b(p157,425,1), b(p157,431,5)));
    ui->p1_d_Fpit1->setText(set2D(b(p157,425,4), b(p157,432,0)));
    ui->p1_d_Fpit2->setText(set2D(b(p157,425,5), b(p157,432,1)));
    ui->p1_d_Fpit3->setText(set2D(b(p157,425,6), b(p157,432,2)));
    ui->p1_d_Fpit4->setText(set2D(b(p157,425,7), b(p157,432,3)));
    ui->p1_d_Ptrop1->setText(set2D(b(p157,426,0), b(p157,432,4)));
    ui->p1_d_Ptrop2->setText(set2D(b(p157,426,1), b(p157,432,5)));
    ui->p1_d_Ptrop3->setText(set2D(b(p157,426,2), b(p157,432,6)));
    ui->p1_d_Ptrop4->setText(set2D(b(p157,426,3), b(p157,432,7)));

    //page 3, выход за границу
    ui->p3_d_Pzkp1->setText(set2D(b(p157,426,4), b(p157,433,0)));
    ui->p3_d_Pzkp2->setText(set2D(b(p157,426,5), b(p157,433,1)));
    ui->p3_d_Pgaz->setText(set2D(b(p157,426,6), b(p157,433,2)));
    ui->p3_d_Lkd->setText(set2D(b(p157,426,7), b(p157,433,3)));
    ui->p3_d_dPgcn1->setText(set2D(b(p157,427,0), b(p157,433,4)));
    ui->p3_d_dPgcn2->setText(set2D(b(p157,427,1), b(p157,433,5)));
    ui->p3_d_dPgcn3->setText(set2D(b(p157,427,2), b(p157,433,6)));
    ui->p3_d_dPgcn4->setText(set2D(b(p157,427,3), b(p157,433,7)));
    ui->p3_d_med1->setText(set2D(b(p157,427,4), b(p157,434,0)));
    ui->p3_d_med2->setText(set2D(b(p157,427,5), b(p157,434,1)));
    ui->p3_d_med3->setText(set2D(b(p157,427,6), b(p157,434,2)));
    ui->p3_d_med4->setText(set2D(b(p157,427,7), b(p157,434,3)));

    //page 4, выход за границу
    ui->p4_d_Lpg1->setText(set2D(b(p157,428,0), b(p157,434,4)));
    ui->p4_d_Lpg2->setText(set2D(b(p157,428,1), b(p157,434,5)));
    ui->p4_d_Lpg3->setText(set2D(b(p157,428,2), b(p157,434,6)));
    ui->p4_d_Lpg4->setText(set2D(b(p157,428,3), b(p157,434,7)));

    //page 5, выход за границу
    QString tmps;
    ui->p5d1_1->setText(tmps=set2D(b(p157,425,0), b(p157,431,4),"реак")); // P реак
    ui->p5d2_1->setText(tmps);
    ui->p5d3_1->setText(tmps);
    ui->p5d4_1->setText(tmps);
    ui->p5d1_2->setText(set2D(b(p157,426,0), b(p157,432,4),"пг")); // P троп Пг1..4
    ui->p5d2_2->setText(set2D(b(p157,426,1), b(p157,432,5),"пг"));
    ui->p5d3_2->setText(set2D(b(p157,426,2), b(p157,432,6),"пг"));
    ui->p5d4_2->setText(set2D(b(p157,426,3), b(p157,432,7),"пг"));


    //page 6, выход за границу
    ui->p6d1_1->setText(tmps=set2D(b(p157,425,0), b(p157,431,4),"реак")); // P реак
    ui->p6d2_1->setText(tmps);
    ui->p6d3_1->setText(tmps);
    ui->p6d4_1->setText(tmps);
    ui->p6d1_2->setText(set2D(b(p157,423,4), b(p157,430,0),"ТЭП")); //ТП ГРЧН1 (Т гн1)
    ui->p6d2_2->setText(set2D(b(p157,424,0), b(p157,430,4),"ТЭП")); //ТП ГРЧН1 (Т гн2)
    ui->p6d3_2->setText(set2D(b(p157,424,1), b(p157,430,5),"ТЭП")); //ТП ГРЧН1 (Т гн3)
    ui->p6d4_2->setText(set2D(b(p157,423,5), b(p157,430,1),"ТЭП")); //ТП ГРЧН1 (Т гн4)
    ui->p6d1_3->setText(set2D(b(p157,423,6), b(p157,430,2),"ТСП")); //ТСП ГРЧН1
    ui->p6d2_3->setText(set2D(b(p157,424,2), b(p157,430,6),"ТСП")); //ТСП ГРЧН2
    ui->p6d3_3->setText(set2D(b(p157,424,2), b(p157,430,6),"ТСП")); //ТСП ГРЧН3
    ui->p6d4_3->setText(set2D(b(p157,423,6), b(p157,430,2),"ТСП")); //ТСП ГРЧН4
}

// колонка значений параметров
void Form3::ppn1() {
    // Page 1: значения (осн/резервный)
    ui->p1t1_t->setText( vi(tT, G3 + 0, 1) );
    ui->p1t2_t->setText( vi(tT, G3 + 4, 1) );
    ui->p1t3_t->setText( vi(tT, G3 + 5, 1) );
    ui->p1t4_t->setText( vi(tT, G3 + 1, 1) );
    ui->p1t5_t->setText( vi(tT, G3 + 8, 1) );

    ui->p1t1_u->setText( vi(tU, G1 + 0, 3) );
    ui->p1t2_u->setText( vi(tU, G1 + 4, 3) );
    ui->p1t3_u->setText( vi(tU, G1 + 5, 3) );
    ui->p1t4_u->setText( vi(tU, G1 + 1, 3) );
    ui->p1t5_u->setText( vi(tU, G1 + 8, 3) );

    ui->p1t1_r->setText( vi(tR, G1 + 2, 1) );
    ui->p1t2_r->setText( vi(tR, G1 + 6, 1) );
    ui->p1t3_r->setText( vi(tR, G1 + 6, 1) );
    ui->p1t4_r->setText( vi(tR, G1 + 2, 1) );
    ui->p1t5_r->setText( vi(tR, G1 + 10, 1) );

    // Page 2: значения (осн/резервный)
    ui->p2_Ppeak_p->setText( vi(tP, G3 + 12, 1) );
    ui->p2_Ppeak_i->setText( vi(tI, G1 + 12, 3) );
    ui->p2_Pgpk_p->setText( vi(tP, G3 + 13, 1) );
    ui->p2_Pgpk_i->setText( vi(tI, G1 + 13, 3) );
    ui->p2_Fpit1_f->setText( vi(tF, G3 + 16, 1) );
    ui->p2_Fpit1_i->setText( vi(tI, G1 + 16, 3) );
    ui->p2_Fpit2_f->setText( vi(tF, G3 + 17, 1) );
    ui->p2_Fpit2_i->setText( vi(tI, G1 + 17, 3) );
    ui->p2_Fpit3_f->setText( vi(tF, G3 + 18, 1) );
    ui->p2_Fpit3_i->setText( vi(tI, G1 + 18, 3) );
    ui->p2_Fpit4_f->setText( vi(tF, G3 + 19, 1) );
    ui->p2_Fpit4_i->setText( vi(tI, G1 + 19, 3) );

    ui->p2_Fpit1_f->setText( vi(tF, G3 + 16, 3) );
    ui->p2_Fpit1_i->setText( vi(tI, G1 + 16, 3) );
    ui->p2_Fpit2_f->setText( vi(tF, G3 + 17, 3) );
    ui->p2_Fpit2_i->setText( vi(tI, G1 + 17, 3) );
    ui->p2_Fpit3_f->setText( vi(tF, G3 + 18, 3) );
    ui->p2_Fpit3_i->setText( vi(tI, G1 + 18, 3) );
    ui->p2_Fpit4_f->setText( vi(tF, G3 + 19, 3) );
    ui->p2_Fpit4_i->setText( vi(tI, G1 + 19, 3) );

    ui->p2_Ptrop1_p->setText( vi(tP, G3 + 20, 2) );
    ui->p2_Ptrop1_i->setText( vi(tI, G1 + 20, 3) );
    ui->p2_Ptrop2_p->setText( vi(tP, G3 + 21, 2) );
    ui->p2_Ptrop2_i->setText( vi(tI, G1 + 21, 3) );
    ui->p2_Ptrop3_p->setText( vi(tP, G3 + 22, 2) );
    ui->p2_Ptrop3_i->setText( vi(tI, G1 + 22, 3) );
    ui->p2_Ptrop4_p->setText( vi(tP, G3 + 23, 2) );
    ui->p2_Ptrop4_i->setText( vi(tI, G1 + 23, 3) );

    // Page3: значения
    ui->p3_Pzkp1_p->setText( vi(tP, G3 + 24, 3) );
    ui->p3_Pzkp1_i->setText( vi(tI, G1 + 24, 3) );
    ui->p3_Pzkp2_p->setText( vi(tP, G3 + 25, 3) );
    ui->p3_Pzkp2_i->setText( vi(tI, G1 + 25, 3) );

    ui->p3_Pgaz_p->setText( vi(tP, G3 + 26, 4) );
    ui->p3_Pgaz_i->setText( vi(tI, G1 + 26, 3) );

    ui->p3_Lkd_l->setText( vi(tP, G3 + 27, 0) );
    ui->p3_Lkd_i->setText( vi(tI, G1 + 27, 3) );

    ui->p3_dPgcn1_p->setText( vi(tP, G3 + 28, 3) );
    ui->p3_dPgcn1_i->setText( vi(tI, G1 + 28, 3) );
    ui->p3_dPgcn2_p->setText( vi(tP, G3 + 29, 3) );
    ui->p3_dPgcn2_i->setText( vi(tI, G1 + 29, 3) );
    ui->p3_dPgcn3_p->setText( vi(tP, G3 + 30, 3) );
    ui->p3_dPgcn3_i->setText( vi(tI, G1 + 30, 3) );
    ui->p3_dPgcn4_p->setText( vi(tP, G3 + 31, 3) );
    ui->p3_dPgcn4_i->setText( vi(tI, G1 + 31, 3) );

    ui->p3_med1_p->setText( vi(tP, G3 + 32, 0) );
    ui->p3_med1_i->setText( vi(tI, G1 + 32, 3) );
    ui->p3_med2_p->setText( vi(tP, G3 + 33, 0) );
    ui->p3_med2_i->setText( vi(tI, G1 + 33, 3) );
    ui->p3_med3_p->setText( vi(tP, G3 + 34, 0) );
    ui->p3_med3_i->setText( vi(tI, G1 + 34, 3) );
    ui->p3_med4_p->setText( vi(tP, G3 + 35, 0) );
    ui->p3_med4_i->setText( vi(tI, G1 + 35, 3) );

    // page 4 значения
    ui->p4_Lpg1_l->setText( vi(tP, G3 + 36, 1) );
    ui->p4_Lpg1_i->setText( vi(tI, G1 + 36, 3) );
    ui->p4_Lpg2_l->setText( vi(tP, G3 + 37, 1) );
    ui->p4_Lpg2_i->setText( vi(tI, G1 + 37, 3) );
    ui->p4_Lpg3_l->setText( vi(tP, G3 + 38, 1) );
    ui->p4_Lpg3_i->setText( vi(tI, G1 + 38, 3) );
    ui->p4_Lpg4_l->setText( vi(tP, G3 + 39, 1) );
    ui->p4_Lpg4_i->setText( vi(tI, G1 + 39, 3) );

    // page 5 значения
    ui->p5_Tnas1k_Tnaspp1_1->setText( us(get_dT(w(p153az, 34)), 1) );
    ui->p5_Tnas1k_Tnaspp1_2->setText( vi(tT, G3 + 14, 1) ); // Ts = Тнас 1К
    ui->p5_Tnas1k_Tnaspp1_3->setText( vi(tI, G1 + 12, 3) ); // I = P реак
    ui->p5_Tnas1k_Tnaspp1_4->setText( vi(tT, G3 + 40, 1) ); // Ts ПГ1 = Тнас_пп
    ui->p5_Tnas1k_Tnaspp1_5->setText( vi(tI, G1 + 20, 3) ); // I = из P троп пг1

    ui->p5_Tnas1k_Tnaspp2_1->setText( us(get_dT(w(p153az, 35)), 1) );
    ui->p5_Tnas1k_Tnaspp2_2->setText( vi(tT, G3 + 14, 1) ); // Ts = Тнас 1К
    ui->p5_Tnas1k_Tnaspp2_3->setText( vi(tI, G1 + 12, 3) ); // I = P реак
    ui->p5_Tnas1k_Tnaspp2_4->setText( vi(tT, G3 + 41, 1) ); // Ts ПГ2 = Тнас_пп
    ui->p5_Tnas1k_Tnaspp2_5->setText( vi(tI, G1 + 21, 3) ); // I = из P троп пг2

    ui->p5_Tnas1k_Tnaspp3_1->setText( us(get_dT(w(p153az, 36)), 1) );
    ui->p5_Tnas1k_Tnaspp3_2->setText( vi(tT, G3 + 14, 1) ); // Ts = Тнас 1К
    ui->p5_Tnas1k_Tnaspp3_3->setText( vi(tI, G1 + 12, 3) ); // I = P реак
    ui->p5_Tnas1k_Tnaspp3_4->setText( vi(tT, G3 + 42, 1) ); // Ts ПГ3 = Тнас_пп
    ui->p5_Tnas1k_Tnaspp3_5->setText( vi(tI, G1 + 22, 3) ); // I = из P троп пг3

    ui->p5_Tnas1k_Tnaspp4_1->setText( us(get_dT(w(p153az, 37)), 1) );
    ui->p5_Tnas1k_Tnaspp4_2->setText( vi(tT, G3 + 14, 1) ); // Ts = Тнас 1К
    ui->p5_Tnas1k_Tnaspp4_3->setText( vi(tI, G1 + 12, 3) ); // I = P реак
    ui->p5_Tnas1k_Tnaspp4_4->setText( vi(tT, G3 + 43, 1) ); // Ts ПГ4 = Тнас_пп
    ui->p5_Tnas1k_Tnaspp4_5->setText( vi(tI, G1 + 23, 3) ); // I = из P троп пг4

    // page 6 значения
    ui->p6_Tnas1k_Tmaxgn1_1->setText( us(get_dT(w(p153az, 38)), 1) ); // Тнас1К - Тmax грчн2
    ui->p6_Tnas1k_Tmaxgn1_2->setText( vi(tT, G3 + 14, 1) ); // Ts = Тнас 1К
    ui->p6_Tnas1k_Tmaxgn1_3->setText( vi(tI, G1 + 12, 3) ); // I = P реак
    ui->p6_Tnas1k_Tmaxgn1_4->setText( vi(tT, G3 + 0, 1) ); // Ts ГРЧН1
    ui->p6_Tnas1k_Tmaxgn1_5->setText( vi(tU, G1 + 0, 3) ); // U = из Tгн1
    ui->p6_Tnas1k_Tmaxgn1_6->setText( vi(tR, G1 + 2, 1) ); // R = из Tгн1

    ui->p6_Tnas1k_Tmaxgn2_1->setText( us(get_dT(w(p153az, 39)), 1) ); // Тнас1К - Тmax грчн2
    ui->p6_Tnas1k_Tmaxgn2_2->setText( vi(tT, G3 + 14, 1) ); // Ts = Тнас 1К
    ui->p6_Tnas1k_Tmaxgn2_3->setText( vi(tI, G1 + 12, 3) ); // I = P реак
    ui->p6_Tnas1k_Tmaxgn2_4->setText( vi(tT, G3 + 4, 1) ); // Ts ГРЧН2
    ui->p6_Tnas1k_Tmaxgn2_5->setText( vi(tU, G1 + 4, 3) ); // U = из Tгн2
    ui->p6_Tnas1k_Tmaxgn2_6->setText( vi(tR, G1 + 6, 1) ); // R = из Tгн2

    ui->p6_Tnas1k_Tmaxgn3_1->setText( us(get_dT(w(p153az, 40)), 1) ); // Тнас1К - Тmax грчн2
    ui->p6_Tnas1k_Tmaxgn3_2->setText( vi(tT, G3 + 14, 1) ); // Ts = Тнас 1К
    ui->p6_Tnas1k_Tmaxgn3_3->setText( vi(tI, G1 + 12, 3) ); // I = P реак
    ui->p6_Tnas1k_Tmaxgn3_4->setText( vi(tT, G3 + 5, 1) ); // Ts ГРЧН3
    ui->p6_Tnas1k_Tmaxgn3_5->setText( vi(tU, G1 + 5, 3) ); // U = из Tгн3
    ui->p6_Tnas1k_Tmaxgn3_6->setText( vi(tR, G1 + 6, 1) ); // R = из Tгн3

    ui->p6_Tnas1k_Tmaxgn4_1->setText( us(get_dT(w(p153az, 41)), 1) ); // Тнас1К - Тmax грчн2
    ui->p6_Tnas1k_Tmaxgn4_2->setText( vi(tT, G3 + 14, 1) ); // Ts = Тнас 1К
    ui->p6_Tnas1k_Tmaxgn4_3->setText( vi(tI, G1 + 12, 3) ); // I = P реак
    ui->p6_Tnas1k_Tmaxgn4_4->setText( vi(tT, G3 + 1, 1) ); // Ts ГРЧН4
    ui->p6_Tnas1k_Tmaxgn4_5->setText( vi(tU, G1 + 1, 3) ); // U = из Tгн4
    ui->p6_Tnas1k_Tmaxgn4_6->setText( vi(tR, G1 + 2, 1) ); // R = из Tгн4
}
