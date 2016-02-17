#include <QLabel>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QInputDialog>
#include <QtGlobal>
#include "form3.h"
#include "ui_form3.h"
#include "contentsdlg.h"
#include "constants.h"
#include "ethrecv.h"
#include <QDesktopWidget>


extern unsigned char ethErrFlag[ETH_SRC_NUM];

// ошибки ethernet
void Form3::fail_E() {
    // ошибка ethernet для блоков (по счетчику в пакетах)
    l1(ui->p151_E,!ethErrFlag[p151_1]); // ПВК151Р(1)
    l1(ui->p152_E,!ethErrFlag[p151_2]); // ПВК152Р(1)
    l1(ui->p153az_E,!ethErrFlag[p153az]); // ПВК155Р(1)
    l1(ui->p153pz_E,!ethErrFlag[p153pz]); // ПВК155Р(2)

    l1(ui->p155_1_E,!ethErrFlag[p155az1]); // ПВК155Р(1)
    l1(ui->p155_2_E,!ethErrFlag[p155az2]); // ПВК155Р(2)
    l1(ui->p156_1_E,!ethErrFlag[p155pz1]); // ПВК156Р(1)
    l1(ui->p156_2_E,!ethErrFlag[p155pz2]); // ПВК156Р(2)
    l1(ui->p157_E,!ethErrFlag[p157]); // ПВК157Р(1)
    l1(ui->p158_E,!ethErrFlag[p158]); // ПВК158Р(2)
    l1(ui->p181_E,!ethErrFlag[pkc]); // ПКЦ181
    l1(ui->pca08_E,!ethErrFlag[p08az]); // ПЧА-08
    l1(ui->pca09_E,!ethErrFlag[p08pz]); // ПЧА-09
    l1(ui->bno245_E, !ethErrFlag[p151_1] && !ethErrFlag[p151_2] && !ethErrFlag[p153az] && !ethErrFlag[p153pz]
                && !ethErrFlag[p155az1] && !ethErrFlag[p155az2] && !ethErrFlag[p155pz1] && !ethErrFlag[p155pz1]
                && !ethErrFlag[p157] && !ethErrFlag[p158] && !ethErrFlag[p08az] && !ethErrFlag[p08pz] ); // БНО245

    // ошибка манчестера (внутр. мониторинговый интерфейс для контроля состояния узлов)
    l1(ui->p151_C,okC_p151_1); // ПВК151Р(1)
    l1(ui->p152_C,okC_p151_2); // ПВК152Р(1)
    l1(ui->p153az_C,okC_p153az); // ПВК153Р АЗ(1)
    l1(ui->p153pz_C,okC_p153pz); // ПВК154Р ПЗ(1)
    l1(ui->p155_1_C,okC_p155az1); // ПВК155Р(1)
    l1(ui->p155_2_C,okC_p155pz1); // ПВК155Р(2)
    l1(ui->p156_1_C,okC_p155az2); // ПВК156Р(1)
    l1(ui->p156_2_C,okC_p155pz2); // ПВК156Р(2)
    l1(ui->p157_C,okC_p157); // ПВК157Р(1)
    l1(ui->p158_C,okC_p158); // ПВК158Р(2)
    l1(ui->pca08_C,okC_p08az); // ПЧА-08
    l1(ui->pca09_C,okC_p08pz); // ПЧА-09


    // линии на слайде(тремя цветами, из сегментов). Откуда, куда
    int b1,b2;
    b1=ok_153az151_152_1_osn, b2 = ok_153az151_152_1_res;
    cl(ui->pvk151_pvk153_az1, b1,b2);
    cl(ui->pvk151_pvk153_az2, b1,b2);
    cl(ui->pvk151_pvk153_az3, b1,b2);

    b1=ok_153pz151_152_1_osn; b2 = ok_153pz151_152_1_res;
    cl(ui->pvk151_pvk153_pz1, ok_153pz151_152_1_osn, ok_153pz151_152_1_res);
    cl(ui->pvk151_pvk153_pz2, ok_153pz151_152_1_osn, ok_153pz151_152_1_res );
    cl(ui->pvk151_pvk153_pz3, ok_153pz151_152_1_osn, ok_153pz151_152_1_res);

    b1 = ok_153az151_152_2_osn; b2= ok_153az151_152_2_res;
    cl(ui->pvk152_pvk153_az1, b1, b2);
    cl(ui->pvk152_pvk153_az2, b1, b2);
    cl(ui->pvk152_pvk153_az3, b1, b2);

    b1 = ok_153pz151_152_2_osn; b2= ok_153pz151_152_2_res;
    cl(ui->pvk152_pvk153_pz1, b1, b2);
    cl(ui->pvk152_pvk153_pz2, b1, b2);
    cl(ui->pvk152_pvk153_pz3, b1, b2);

    b1 = ok_153az157_158_1_osn; b2 = ok_153az157_158_1_res;
    cl(ui->pvk157_pvk153_az1, b1,b2);
    cl(ui->pvk157_pvk153_az2, b1,b2);
    cl(ui->pvk157_pvk153_az3, b1,b2);

    b1 = ok_153pz157_158_1_osn; b2 = ok_153pz157_158_1_res;
    cl(ui->pvk157_pvk153_pz1, b1, b2);
    cl(ui->pvk157_pvk153_pz2, b1, b2);
    cl(ui->pvk157_pvk153_pz3, b1, b2);

    b1 = ok_153az157_158_2_osn; b2 = ok_153az157_158_2_res;
    cl(ui->pvk158_pvk153_az1, b1,b2);
    cl(ui->pvk158_pvk153_az2, b1,b2);
    cl(ui->pvk158_pvk153_az3, b1,b2);

    b1 = ok_153pz157_158_2_osn; b2 = ok_153pz157_158_2_res;
    cl(ui->pvk158_pvk153_pz1, b1, b2);
    cl(ui->pvk158_pvk153_pz2, b1, b2);
    cl(ui->pvk158_pvk153_pz3, b1, b2);

    cl(ui->pvk153az_pvk155_1, fail_155az1_153_154_osn, fail_155az1_153_154_res);
    cl(ui->pvk153az_pvk155_2, fail_155az2_153_154_osn, fail_155az2_153_154_res);
    cl(ui->pvk153az_pca08, fail_pca_az_153_osn, fail_pca_az_153_res);

    cl(ui->pvk153pz_pvk156_1, fail_155pz1_153_154_osn, fail_155pz1_153_154_res);
    cl(ui->pvk153pz_pvk156_2, fail_155pz2_153_154_osn, fail_155pz2_153_154_res);
    cl(ui->pvk153pz_pca09, fail_pca_pz_153_osn, fail_pca_pz_153_res);

    // в ПКЦ-181
    l1(ui->fail_pkc_p151,!fail_pkc_151_152_1); // ПВК151Р(1)
    l1(ui->fail_pkc_p152,!fail_pkc_151_152_2); // ПВК152Р(1)
    l1(ui->fail_pkc_p153,!fail_pkc_153_154_az); // ПВК153Р АЗ(1)
    l1(ui->fail_pkc_p154,!fail_pkc_153_154_pz); // ПВК154Р ПЗ(1)
    l1(ui->fail_pkc_p155_1,!fail_pkc_155_156_az_1); // ПВК155Р(1)
    l1(ui->fail_pkc_p155_2,!fail_pkc_155_156_az_2); // ПВК155Р(2)
    l1(ui->fail_pkc_p156_1,!fail_pkc_155_156_pz_1); // ПВК156Р(1)
    l1(ui->fail_pkc_p156_2,!fail_pkc_155_156_pz_2); // ПВК156Р(2)
    l1(ui->fail_pkc_p157,!fail_pkc_157_158_1); // ПВК157Р(1)
    l1(ui->fail_pkc_p158,!fail_pkc_157_158_2); // ПВК158Р(2)
    l1(ui->fail_pkc_pca08,!fail_pkc_pca_az); // ПЧА08
    l1(ui->fail_pkc_pca09,!fail_pkc_pca_pz); // ПЧА09



    l2(ui->pvk153az_B, ok_153az157_158_B); // в 153 АЗ, исправность интерфейса B
    l2(ui->pvk153pz_B, ok_153pz157_158_B); // в 153 ПЗ, исправность интерфейса B

    l2(ui->pvk153az_C, ok_153az157_158_C); // в 153 АЗ, исправность интерфейса C
    l2(ui->pvk153pz_C, ok_153pz157_158_C); // в 153 ПЗ, исправность интерфейса C

    l2(ui->pvk153az_pvk153pz, ok_153_154_az); // в 153 ПЗ, исправность связи с АЗ



}
