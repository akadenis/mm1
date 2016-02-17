#include <QString>
QString strDiscr_pvk151_1[24] = {
    "АКНП: N ≥ 5%",
    "АКНП: N ≥ 40%",
    "АКНП: N ≥ 75%",
    "АКНП: N ≥ N АЗ",
    "АКНП: N ≥ N ПЗ-1",
    "АКНП: N ≥ N ПЗ-2",
    "АКНП:",
    "АКНП: T < 20c ПЗ-1",
    "",
    "АКНП: НЕИСПРАВНОСТЬ",
    "",
    "",
    "",
    "",
    "",
    "",
    "КЭ СУЗ: П ПИГ.СУЗ",
    "КЭ СУЗ: ПАДЕНИЕ ОР",
    "КЭ СУЗ: ОПРОБЫВАНИЕ",
    "",
    "",
    "",
    "",
    "АФСЗ: ОТКР.ДВЕРИ" };


QString strDiscr_pvk151_2[24] = {
    "",
    "CЭ: СЕЙСМИКА"
    "",
    "",
    "АРОМ: РОМ",
    "ОТО: ОТКЛ. ЭБ",
    "ОТО: ВЫКЛ. ГЕНЕР.",
    "ОТО: ЗАКР. 2/4 СК.",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "СВРК: QL ПЗ-2",
    "СВРК: DNBR ПЗ-2",
    "СВРК: ОТКЛ ЦЭН",
    "",
    "",
    "",
    "",
    "" };

QString strDiscr_columns[7] = {
    "вход.", "испр", "лин.св", "имит.", "блок", "результ", "вх.лог" };

// перевод порядкового номера 0...6 в порядок следования групп сигналов в таблице сигналов 151-152
int cnv_in[7] {
    0, //"0.вход.",
    2, //"1.испр",
    1, //"2.лин.св",
    4, //3."имит.",
    5,//4."блок",
    3,//"5.результ",
    0, //6."вх.лог" (см 153-154 узел)

};

QString strOutDiscr_columns[6] = {
    "вых.153/154", "выход.", "имит.", "блок.", "испр.", "результ" };

QString strOutDiscr_pvk155_1az[] = {
    "ШАК 1.1 АЗ",
    "ШАК 2.1 АЗ",
    "ОПРОБЫВАНИЕ (АКНП)",
    "ОПРОБЫВАНИЕ (АКП)",
    "Р РЕАК ≤ 150 кгс/см2 & N ≥ 75%",
    "ОТКЛ 1/4 & N ≥ 75%",
    "ОТКЛ 3/4 & N ≥ 5%",
    "L ПВ ПГ 1 ≤ -65 см",
    "L ПВ ПГ 2 ≤ -65 см",
    "L ПВ ПГ 3 ≤ -65 см",
    "L ПВ ПГ 4 ≤ -65 см",
    "L КД ≤ 460 см",
    "Р РЕАК ≥ 178,5 кгс/см2",
    "Р ГАЗ06/1 ≥ 0,306 кгс/см2",
    "ПОТЕРЯ ПИТАНИЯ СУЗ",
    "ИЗМ. Р-Р ГЦН 1",
    "ИЗМ. Р-Р ГЦН 2",
    "ИЗМ. Р-Р ГЦН 3",
    "ИЗМ. Р-Р ГЦН 4",
    "Р ПГ 1 ≤ 50,0 кгс/cм2 & T НАС 1 ≥ 75°C & T НАС 1 ≥ 200°C",
    "Р ПГ 2 ≤ 50,0 кгс/cм2 & T НАС 2 ≥ 75°C & T НАС 1 ≥ 200°C",
    "Р ПГ 3 ≤ 50,0 кгс/cм2 & T НАС 3 ≥ 75°C & T НАС 1 ≥ 200°C",
    "Р ПГ 4 ≤ 50,0 кгс/cм2 & T НАС 4 ≥ 75°C & T НАС 1 ≥ 200°C",
    "Т ГРЧН - Т НОМ ≥ 8°C"};

QString strOutDiscr_pvk155_2az[] = {
    "ШАК 1.2 АЗ",
    "ШАК 2.2 ПЗ",
    "F 3/4 ГЦН ≤ 46 Гц",
    "Т НАС 1К - Т MAX ГРЧН 1 ≤ 10°C",
    "2 ТПН ВЫКЛ & N ≥ 40°C",
    "Т ДР, ДП, ИД ≤ 10",
    "N ДР, ДП, ИД ≥ N УСТ",
    "СЕЙСМИЧ.ВОЗД ≥ 6 баллов",
    "Р АЗ ≤ 140 кгс/см2",
    "Р ТРОП ПГ",
    "ОТКЛ. ГЦН 1 (АКНП)",
    "ОТКЛ. ГЦН 2 (АКНП)",
    "ОТКЛ. ГЦН 3 (АКНП)",
    "ОТКЛ. ГЦН 4 (АКНП)",
    "ОБОБЩ.ИСПРАВНОСТЬ",
    "ОБОБЩ.ПРОВЕРКА",
    "",
    "",
    "ПЕРЕГРУЗ.МАШИНА",
    "КРУГОВОЙ КРАН",
    "СРАБАТЫВАНИЕ АЗ"
};

QString strOutDiscr_pvk155_1pz[] = {
    "ШАК 1.1 АЗ",
    "ШАК 2.1 ПЗ",
    "ШАК 1.1 АЗ",
    "ШАК 2.1 ПЗ",
    "ШАК 1.1 УПЗ",
    "ШАК 2.1 УПЗ",
    "ОТКЛ ГЦН 1 (АРОМ)",
    "ОТКЛ ГЦН 2 (АРОМ)",
    "ОТКЛ ГЦН 3 (АРОМ)",
    "ОТКЛ ГЦН 4 (АРОМ)",
    "ОТКЛ ТПН 1 (АРОМ)",
    "ОТКЛ ТПН 2 (АРОМ)",
    "ОТКЛ ЭБ (АРОМ)",
    "ВЫКЛ ГЕНЕР (АРОМ)",
    "ЗАКР 2/4 СК (АРОМ)",
    "ЗАКР 2/4 СК (АРОМ)",
    "ОТКЛ ЦЭН (АРОМ)",
    "",
    "",
    "Т ГРЧ ГЦТ ≥ +3",
    "Р РЕАК ≥ 170,3 кгс/см2",
    "Р ГПК ≥ 65 кгс/см2",
    "Т ДР, ДП, ИД ≤ 20",
    "N ДР ≤ N УСТ"
};

QString strOutDiscr_pvk155_2pz[] = {
    "ШАК 1.2 АЗ",
    "ШАК 2.2 ПЗ",
    "ШАК 1.2 АЗ",
    "ШАК 2.2 ПЗ",
    "ШАК 1.2 УПЗ",
    "ШАК 2.2 УПЗ",
    "РОМ",
    "",
    "",
    "N ДП ≤ УСТ.ПЗ-2",
    "P РЕАК ≥ 165,2 см2",
    "ПАДЕНИЕ ОР",
    "QL ≥ УСТ.ПЗ-2",
    "DNBR ≤ УСТ ПЗ-2",
    "ОТКЛ 1/4 ГЦН & N ≥ 75%",
    "ОТКЛ ЭБ & N ≥ 75%",
    "ВЫКЛ ГЕНЕР & N ≥ 75%",
    "ОТКЛ 1/2 ТПН & N ≥ 75%",
    "ЗАКР.2/4 СК. & N ≥ 75%",
    "ОБОБЩ. ПЗ-1",
    "ОБОБЩ. ПЗ-1",
    "ОБОБЩ. УПЗ-1",
    "",
    "СРАБАТЫВАНИЕ ПЗ"
};


int cnv_out[6] {
    0, //"0.вых.153/154", // см 153/154
    2, //"1.вых.",
    1, //"2.имит",
    4, //3."блок.",
    5,//4."испр",
    0, //5."результ."

};


QString str_pca_az[] = {
    "P РЕАК",
    "Т ХН 1",
    "Т ХН 2",
    "Т ХН 3",
    "Т ХН 4",
    "F ПИТ ГЦН 1",
    "F ПИТ ГЦН 2",
    "F ПИТ ГЦН 3",
    "F ПИТ ГЦН 4",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
};

QString str_pca_pz[] = {
    "F ПИТ ГЦН 1",
    "F ПИТ ГЦН 2",
    "F ПИТ ГЦН 3",
    "F ПИТ ГЦН 4",
    "","","","","","","","","","","","",
};
