#include "form3.h"
#include "constants.h"
#include "ui_form3.h"

void Form3::ustav() {
    ui->p1u1_1->setText(z( saz_Tgn1_more200_C_A ) + us(get_T(w(p153az,72)),1) ); // >200
    lb(ui->p1u1_1,az_Tgn1_more200_C_A);
    ui->p1u2_1->setText(z( saz_Tgn2_more200_C_A ) + us(get_T(w(p153az,73)),1) );
    lb(ui->p1u2_1, az_Tgn2_more200_C_A);
    ui->p1u3_1->setText( z( saz_Tgn3_more200_C_A ) + us(get_T(w(p153az,74)),1) );
    lb(ui->p1u3_1, az_Tgn3_more200_C_A);
    ui->p1u4_1->setText( z( saz_Tgn4_more200_C_A ) + us(get_T(w(p153az,75)),1) );
    lb(ui->p1u4_1, az_Tgn4_more200_C_A);
    ui->p1u1_2->setText(z( saz_Tgn1_more330_C_A ) + us(get_T(w(p153az,76)),1) ); // >330
    lb(ui->p1u1_2, az_Tgn1_more330_C_A);
    ui->p1u2_2->setText(z( saz_Tgn2_more330_C_A ) + us(get_T(w(p153az,77)),1) );
    lb(ui->p1u2_2, az_Tgn2_more330_C_A);
    ui->p1u3_2->setText(z( saz_Tgn3_more330_C_A ) + us(get_T(w(p153az,78)),1) );
    lb(ui->p1u3_2, az_Tgn3_more330_C_A);
    ui->p1u4_2->setText(z( saz_Tgn4_more330_C_A ) + us(get_T(w(p153az,79)),1) );
    lb(ui->p1u4_2, az_Tgn4_more330_C_A);
    ui->p1u1_3->setText(z( saz_Tgn1_more260_C_A) + us(get_T(w(p153az,80)),1) ); // >260
    lb(ui->p1u1_3, az_Tgn1_more260_C_A);
    ui->p1u2_3->setText( z( saz_Tgn2_more260_C_A) + us(get_T(w(p153az,81)),1) ); //
    lb(ui->p1u2_3, az_Tgn2_more260_C_A);
    ui->p1u3_3->setText( z( saz_Tgn3_more260_C_A) + us(get_T(w(p153az,82)),1) );
    lb(ui->p1u3_3, az_Tgn3_more260_C_A);
    ui->p1u4_3->setText( z( saz_Tgn4_more260_C_A) +  us(get_T(w(p153az,83)),1) );
    lb(ui->p1u4_3, az_Tgn4_more260_C_A);
    ui->p1u1_4->setText( z( saz_Tgn1_less_268_C_A ) + us(get_T(w(p153az,84)),1) ); // <268
    lb(ui->p1u1_4, az_Tgn1_less_268_C_A);
    ui->p1u2_4->setText(z( saz_Tgn2_less_268_C_A ) + us(get_T(w(p153az,85)),1) ); //
    lb(ui->p1u2_4, az_Tgn2_less_268_C_A);
    ui->p1u3_4->setText(z( saz_Tgn3_less_268_C_A ) + us(get_T(w(p153az,86)),1) );
    lb(ui->p1u3_4, az_Tgn3_less_268_C_A);
    ui->p1u4_4->setText(z( saz_Tgn4_less_268_C_A ) + us(get_T(w(p153az,87)),1) );
    lb(ui->p1u4_4, az_Tgn4_less_268_C_A);
    ui->p1u1_5->setText(z( spz_Tgn1_more325_C_A ) + us(get_T(w(p153pz,12)),1) ); // >325
    lb(ui->p1u1_5, pz_Tgn1_more325_C_A);
    ui->p1u2_5->setText( z( spz_Tgn2_more325_C_A ) +us(get_T(w(p153pz,13)),1) ); //
    lb(ui->p1u2_5, pz_Tgn2_more325_C_A);
    ui->p1u3_5->setText(z( spz_Tgn3_more325_C_A ) + us(get_T(w(p153pz,14)),1) );
    lb(ui->p1u3_5, pz_Tgn3_more325_C_A);
    ui->p1u4_5->setText(z( spz_Tgn4_more325_C_A ) + us(get_T(w(p153pz,15)),1) );
    lb(ui->p1u4_5, pz_Tgn4_more325_C_A);
    ui->p2_u_Ppeak1->setText(z( saz_Paz_less150_A ) + us(get_P(w(p153az,42), 0,250),1) ); // <150,0
    lb(ui->p2_u_Ppeak1, az_Paz_less150_A);
    ui->p2_u_Ppeak2->setText(z( saz_Paz_more178_5_A ) + us(get_P(w(p153az,43), 0,250),1) ); // >178,5
    lb(ui->p2_u_Ppeak2, az_Paz_more178_5_A);
    ui->p2_u_Ppeak3->setText(z( saz_Paz_less140_A ) + us(get_P(w(p153az,44), 0,250),1) ); // <140,0
    lb(ui->p2_u_Ppeak3, saz_Paz_less140_A);
    ui->p2_u_Ppeak4->setText(z( saz_Paz_more150_A ) + us(get_P(w(p153az,45), 0,250),1) ); // >150,0
    lb(ui->p2_u_Ppeak4, az_Paz_more150_A);
    ui->p2_u_Ppeak5->setText(z( spz_Ppz_more_170_3_A ) + us(get_P(w(p153pz,16), 0,250),1) ); // >170,3
    lb(ui->p2_u_Ppeak5, pz_Ppz_more_170_3_A);
    ui->p2_u_Ppeak6->setText(z( spz_Ppz_more_165_2_A ) + us(get_P(w(p153pz,17), 0,250),1) ); // >165,2
    lb(ui->p2_u_Ppeak6, pz_Ppz_more_165_2_A);
    ui->p2_u_Pgpk->setText( z( spz_P_gpk_more_70_A )  + us(get_P(w(p153pz,18), 0,100),1) );
    lb(ui->p2_u_Pgpk, pz_P_gpk_more_70_A);
    ui->p2_u_Fpit1->setText( z( saz_Fgcn1_less_46_A) + us(get_F(w(p153az,88)),3) );
    lb(ui->p2_u_Fpit1, az_Fgcn1_less_46_A);
    ui->p2_u_Fpit2->setText( z( saz_Fgcn2_less_46_A) + us(get_F(w(p153az,89)),3) );
    lb(ui->p2_u_Fpit2, az_Fgcn2_less_46_A);
    ui->p2_u_Fpit3->setText( z( saz_Fgcn3_less_46_A) + us(get_F(w(p153az,90)),3) );
    lb(ui->p2_u_Fpit3, az_Fgcn3_less_46_A);
    ui->p2_u_Fpit4->setText( z( saz_Fgcn4_less_46_A) + us(get_F(w(p153az,91)),3) );
    lb(ui->p2_u_Fpit4, az_Fgcn4_less_46_A);
    ui->p2_u_Ptrop1_50->setText( z( saz_Ppg1_less50_A ) + us(get_P(w(p153az,64), 0,100),2) );
    lb(ui->p2_u_Ptrop1_50, az_Ppg1_less50_A);
    ui->p2_u_Ptrop2_50->setText(  z( saz_Ppg1_less50_A ) + us(get_P(w(p153az,65), 0,100),2) );
    lb(ui->p2_u_Ptrop2_50, az_Ppg1_less50_A);
    ui->p2_u_Ptrop3_50->setText(  z( saz_Ppg1_less50_A ) + us(get_P(w(p153az,66), 0,100),2) );
    lb(ui->p2_u_Ptrop3_50, az_Ppg1_less50_A);
    ui->p2_u_Ptrop4_50->setText(  z( saz_Ppg1_less50_A ) + us(get_P(w(p153az,67), 0,100),2) );
    lb(ui->p2_u_Ptrop4_50, az_Ppg1_less50_A);
    ui->p2_u_Ptrop1_80->setText( z( saz_Ppg1_more80_A ) + us(get_P(w(p153az,68), 0,100),2) );
    lb(ui->p2_u_Ptrop1_80, az_Ppg1_more80_A);
    ui->p2_u_Ptrop2_80->setText( z( saz_Ppg2_more80_A ) + us(get_P(w(p153az,69), 0,100),2) );
    lb(ui->p2_u_Ptrop2_80, az_Ppg2_more80_A);
    ui->p2_u_Ptrop3_80->setText( z( saz_Ppg3_more80_A ) + us(get_P(w(p153az,70), 0,100),2) );
    lb(ui->p2_u_Ptrop3_80, az_Ppg3_more80_A);
    ui->p2_u_Ptrop4_80->setText( z( saz_Ppg4_more80_A ) + us(get_P(w(p153az,71), 0,100),2) );
    lb(ui->p2_u_Ptrop4_80, az_Ppg4_more80_A);
    ui->p3_u_Pzkp1_az->setText( z( saz_Ptpn1_less_0_408_A ) + us(get_P(w(p153az,92),0,10),3) ); // 24
    lb(ui->p3_u_Pzkp1_az, az_Ptpn1_less_0_408_A);
    ui->p3_u_Pzkp1_upz->setText( z( spz_P_tpn1_less_0_408_A ) + us(get_P(w(p153pz,23),0,10),3) ); // 24
    lb(ui->p3_u_Pzkp1_upz, pz_P_tpn1_less_0_408_A);
    ui->p3_u_Pzkp2_az->setText( z( saz_Ptpn2_less_0_408_A ) + us(get_P(w(p153az,93),0,10),3) ); // 25
    lb(ui->p3_u_Pzkp2_az, az_Ptpn2_less_0_408_A);
    ui->p3_u_Pzkp2_upz->setText( z( spz_P_tpn2_less_0_408_A ) + us(get_P(w(p153pz,24),0,10),3) ); // 25
    lb(ui->p3_u_Pzkp2_upz, pz_P_tpn2_less_0_408_A);
    ui->p3_u_Pgaz->setText( z( saz_Pgaz06_more0_306_A ) + us(get_P(w(p153az,55),-0.5,1),4) ); // 26 (Рпод.об.)
    lb(ui->p3_u_Pgaz, az_Pgaz06_more0_306_A);
    ui->p3_u_Lkd->setText( z( saz_L_kd_less_460_A ) + us(get_P(w(p153az,54),0,630),0) ); // 27
    lb(ui->p3_u_Lkd, az_L_kd_less_460_A);
    ui->p3_u_dPgcn1_40->setText(z( saz_dPgcn1_less_4_0_A ) + us(get_P(w(p153az,56),0,10),3) ); // 28
    lb(ui->p3_u_dPgcn1_40, az_dPgcn1_less_4_0_A);
    ui->p3_u_dPgcn2_40->setText(z( saz_dPgcn2_less_4_0_A ) + us(get_P(w(p153az,57),0,10),3) ); // 29
    lb(ui->p3_u_dPgcn2_40, az_dPgcn2_less_4_0_A);
    ui->p3_u_dPgcn3_40->setText(z( saz_dPgcn3_less_4_0_A ) + us(get_P(w(p153az,58),0,10),3) ); // 30
    lb(ui->p3_u_dPgcn3_40, az_dPgcn3_less_4_0_A);
    ui->p3_u_dPgcn4_40->setText(z( saz_dPgcn4_less_4_0_A ) + us(get_P(w(p153az,59),0,10),3) ); // 31
    lb(ui->p3_u_dPgcn4_40, az_dPgcn4_less_4_0_A);
    ui->p3_u_dPgcn1_25->setText(z( saz_dPgcn1_less_2_5_A ) + us(get_P(w(p153az,60),0,10),3) ); // 28
    lb(ui->p3_u_dPgcn1_25, az_dPgcn1_less_2_5_A);
    ui->p3_u_dPgcn2_25->setText(z( saz_dPgcn2_less_2_5_A ) + us(get_P(w(p153az,61),0,10),3) ); // 29
    lb(ui->p3_u_dPgcn2_25, az_dPgcn2_less_2_5_A);
    ui->p3_u_dPgcn3_25->setText(z( saz_dPgcn3_less_2_5_A ) + us(get_P(w(p153az,62),0,10),3) ); // 30
    lb(ui->p3_u_dPgcn3_25, az_dPgcn3_less_2_5_A);
    ui->p3_u_dPgcn4_25->setText(z( saz_dPgcn4_less_2_5_A ) + us(get_P(w(p153az,63),0,10),3) ); // 31
    lb(ui->p3_u_dPgcn4_25, az_dPgcn4_less_2_5_A);
    ui->p3_u_med1_az->setText(z( saz_Ngcn1_less_3000_A ) + us(get_P(w(p153az,46),0,16368),0) ); //32
    lb(ui->p3_u_med1_az, az_Ngcn1_less_3000_A);
    ui->p3_u_med2_az->setText(z( saz_Ngcn2_less_3000_A ) + us(get_P(w(p153az,47),0,16368),0) ); //33
    lb(ui->p3_u_med2_az, az_Ngcn2_less_3000_A);
    ui->p3_u_med3_az->setText(z( saz_Ngcn3_less_3000_A ) + us(get_P(w(p153az,48),0,16368),0) ); //34
    lb(ui->p3_u_med3_az, az_Ngcn3_less_3000_A);
    ui->p3_u_med4_az->setText( z( saz_Ngcn4_less_3000_A ) + us(get_P(w(p153az,49),0,16368),0) ); //35
    lb(ui->p3_u_med4_az, az_Ngcn4_less_3000_A);
    ui->p3_u_med1_pz->setText(z( spz_Ngcn1_less_3000_A ) + us(get_P(w(p153pz,19),0,16368),0) ); //32
    lb(ui->p3_u_med1_pz, pz_Ngcn1_less_3000_A);
    ui->p3_u_med2_pz->setText(z( spz_Ngcn2_less_3000_A ) + us(get_P(w(p153pz,20),0,16368),0) ); //33
    lb(ui->p3_u_med2_pz, pz_Ngcn2_less_3000_A);
    ui->p3_u_med3_pz->setText(z( spz_Ngcn3_less_3000_A ) + us(get_P(w(p153pz,21),0,16368),0) ); //34
    lb(ui->p3_u_med3_pz, pz_Ngcn3_less_3000_A);
    ui->p3_u_med4_pz->setText(z( spz_Ngcn4_less_3000_A ) + us(get_P(w(p153pz,22),0,16368),0) ); //35
    lb(ui->p3_u_med4_pz, pz_Ngcn4_less_3000_A);
    ui->p4_u_Lpg1->setText(z( saz_Lpg1_less_175_A ) + us(get_P(w(p153az,50),0,400),1) ); // 36
    lb(ui->p4_u_Lpg1, az_Lpg1_less_175_A);
    ui->p4_u_Lpg2->setText(z( saz_Lpg2_less_175_A ) + us(get_P(w(p153az,51),0,400),1) );
    lb(ui->p4_u_Lpg2, az_Lpg2_less_175_A);
    ui->p4_u_Lpg3->setText(z( saz_Lpg3_less_175_A ) + us(get_P(w(p153az,52),0,400),1) );
    lb(ui->p4_u_Lpg3, az_Lpg3_less_175_A);
    ui->p4_u_Lpg4->setText(z( saz_Lpg4_less_175_A ) + us(get_P(w(p153az,53),0,400),1) );
    lb(ui->p4_u_Lpg4, az_Lpg4_less_175_A);
    ui->p5_u_Tnas1k_Tnaspp1->setText(z( saz_Ts_az__Ts_pg1_more75_C_A ) + us(get_dT(w(p153az,94)),1) );
    lb(ui->p5_u_Tnas1k_Tnaspp1, az_Ts_az__Ts_pg1_more75_C_A);
    ui->p5_u_Tnas1k_Tnaspp2->setText(z( saz_Ts_az__Ts_pg2_more75_C_A ) + us(get_dT(w(p153az,95)),1) );
    lb(ui->p5_u_Tnas1k_Tnaspp2, az_Ts_az__Ts_pg2_more75_C_A);
    ui->p5_u_Tnas1k_Tnaspp3->setText(z( saz_Ts_az__Ts_pg3_more75_C_A ) + us(get_dT(w(p153az,96)),1) );
    lb(ui->p5_u_Tnas1k_Tnaspp3, az_Ts_az__Ts_pg3_more75_C_A);
    ui->p5_u_Tnas1k_Tnaspp4->setText(z( saz_Ts_az__Ts_pg4_more75_C_A ) + us(get_dT(w(p153az,97)),1) );
    lb(ui->p5_u_Tnas1k_Tnaspp4, az_Ts_az__Ts_pg4_more75_C_A);
    ui->p6_u_Tnas1k_Tmaxgn1->setText(z( saz_Ts_az__Tgn1_less_10_C_A ) + us(get_dT(w(p153az,98)),1) );
    lb(ui->p6_u_Tnas1k_Tmaxgn1, az_Ts_az__Tgn1_less_10_C_A);
    ui->p6_u_Tnas1k_Tmaxgn2->setText(z( saz_Ts_az__Tgn2_less_10_C_A ) + us(get_dT(w(p153az,98)),1) );
    lb(ui->p6_u_Tnas1k_Tmaxgn2, az_Ts_az__Tgn2_less_10_C_A);
    ui->p6_u_Tnas1k_Tmaxgn3->setText(z( saz_Ts_az__Tgn3_less_10_C_A ) + us(get_dT(w(p153az,100)),1) );
    lb(ui->p6_u_Tnas1k_Tmaxgn3, az_Ts_az__Tgn3_less_10_C_A);
    ui->p6_u_Tnas1k_Tmaxgn4->setText(z( saz_Ts_az__Tgn4_less_10_C_A ) + us(get_dT(w(p153az,101)),1) );
    lb(ui->p6_u_Tnas1k_Tmaxgn4, az_Ts_az__Tgn4_less_10_C_A);
}
