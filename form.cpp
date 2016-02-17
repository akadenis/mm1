//#include "form.h"
//#include "ui_form.h"
//#include <QRect>
//#include <QPainter>
//#include "formula.h"

//extern unsigned char valData[ETH_SRC_NUM][1600];

//Form::Form(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::Form)
//{
//    ui->setupUi(this);

//}

//Form::~Form()
//{
//    delete ui;
//}

////QString strDiscr_pvk151_1[24] = {
////    "АКНП: N ≥ 5%",
////    "АКНП: N ≥ 40%",
////    "АКНП: N ≥ 75%",
////    "АКНП: N ≥ N АЗ",
////    "АКНП: N ≥ N ПЗ-1",
////    "АКНП: N ≥ N ПЗ-2",
////    "АКНП:",
////    "АКНП: T < 20c ПЗ-1",
////    "",
////    "АКНП: НЕИСПРАВНОСТЬ",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "КЭ СУЗ: П ПИГ.СУЗ",
////    "КЭ СУЗ: ПАДЕНИЕ ОР",
////    "КЭ СУЗ: ОПРОБЫВАНИЕ",
////    "",
////    "",
////    "",
////    "",
////    "АФСЗ: ОТКР.ДВЕРИ" };


////QString strDiscr_pvk151_2[24] = {
////    "",
////    "CЭ: СЕЙСМИКА"
////    "",
////    "",
////    "АРОМ: РОМ",
////    "ОТО: ОТКЛ. ЭБ",
////    "ОТО: ВЫКЛ. ГЕНЕР.",
////    "ОТО: ЗАКР. 2/4 СК.",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "СВРК: QL ПЗ-2",
////    "СВРК: DNBR ПЗ-2",
////    "СВРК: ОТКЛ ЦЭН",
////    "",
////    "",
////    "",
////    "",
////    "" };

////QString strDiscr_columns[7] = {
////    "вход.", "испр", "лин.св", "имит.", "блок", "результ", "вх.лог" };

////// перевод порядкового номера 0...6 в порядок следования групп сигналов в таблице сигналов 151-152
////int cnv_in[7] {
////    0, //"0.вход.",
////    2, //"1.испр",
////    1, //"2.лин.св",
////    4, //3."имит.",
////    5,//4."блок",
////    3,//"5.результ",
////    0, //6."вх.лог" (см 153-154 узел)

////};

////QString strOutDiscr_columns[] = {
////    "выход 153/154", "выход.", "имит.", "блок.", "испр.", "результ" };

////QString strOutDiscr_pvk155_1az[] = {
////    "ШАК 1.1 АЗ",
////    "ШАК 2.1 АЗ",
////    "ОПРОБЫВАНИЕ (АКНП)",
////    "ОПРОБЫВАНИЕ (АКП)",
////    "Р РЕАК ≤ 150 кгс/см2 & N ≥ 75%",
////    "ОТКЛ 1/4 & N ≥ 75%",
////    "ОТКЛ 3/4 & N ≥ 5%",
////    "L ПВ ПГ 1 ≤ -65 см",
////    "L ПВ ПГ 2 ≤ -65 см",
////    "L ПВ ПГ 3 ≤ -65 см",
////    "L ПВ ПГ 4 ≤ -65 см",
////    "L КД ≤ 460 см",
////    "Р РЕАК ≥ 178,5 кгс/см2",
////    "Р ГАЗ06/1 ≥ 0,306 кгс/см2",
////    "ПОТЕРЯ ПИТАНИЯ СУЗ",
////    "ИЗМ. Р-Р ГЦН 1",
////    "ИЗМ. Р-Р ГЦН 2",
////    "ИЗМ. Р-Р ГЦН 3",
////    "ИЗМ. Р-Р ГЦН 4",
////    "Р ПГ 1 ≤ 50,0 кгс/cм2 & T НАС 1 ≥ 75°C & T НАС 1 ≥ 200°C",
////    "Р ПГ 2 ≤ 50,0 кгс/cм2 & T НАС 2 ≥ 75°C & T НАС 1 ≥ 200°C",
////    "Р ПГ 3 ≤ 50,0 кгс/cм2 & T НАС 3 ≥ 75°C & T НАС 1 ≥ 200°C",
////    "Р ПГ 4 ≤ 50,0 кгс/cм2 & T НАС 4 ≥ 75°C & T НАС 1 ≥ 200°C",
////    "Т ГРЧН - Т НОМ ≥ 8°C"};

////QString strOutDiscr_pvk155_2az[] = {
////    "ШАК 1.2 АЗ",
////    "ШАК 2.2 ПЗ",
////    "F 3/4 ГЦН ≤ 46 Гц",
////    "Т НАС 1К - Т MAX ГРЧН 1 ≤ 10°C",
////    "2 ТПН ВЫКЛ & N ≥ 40°C",
////    "Т ДР, ДП, ИД ≤ 10",
////    "N ДР, ДП, ИД ≥ N УСТ",
////    "СЕЙСМИЧ.ВОЗД ≥ 6 баллов",
////    "Р АЗ ≤ 140 кгс/см2",
////    "Р ТРОП ПГ",
////    "ОТКЛ. ГЦН 1 (АКНП)",
////    "ОТКЛ. ГЦН 2 (АКНП)",
////    "ОТКЛ. ГЦН 3 (АКНП)",
////    "ОТКЛ. ГЦН 4 (АКНП)",
////    "ОБОБЩ.ИСПРАВНОСТЬ",
////    "ОБОБЩ.ПРОВЕРКА",
////    "",
////    "",
////    "ПЕРЕГРУЗ.МАШИНА",
////    "КРУГОВОЙ КРАН",
////    "СРАБАТЫВАНИЕ АЗ"
////};

////QString strOutDiscr_pvk155_1pz[] = {
////    "ШАК 1.1 АЗ",
////    "ШАК 2.1 ПЗ",
////    "ШАК 1.1 АЗ",
////    "ШАК 2.1 ПЗ",
////    "ШАК 1.1 УПЗ",
////    "ШАК 2.1 УПЗ",
////    "ОТКЛ ГЦН 1 (АРОМ)",
////    "ОТКЛ ГЦН 2 (АРОМ)",
////    "ОТКЛ ГЦН 3 (АРОМ)",
////    "ОТКЛ ГЦН 4 (АРОМ)",
////    "ОТКЛ ТПН 1 (АРОМ)",
////    "ОТКЛ ТПН 2 (АРОМ)",
////    "ОТКЛ ЭБ (АРОМ)",
////    "ВЫКЛ ГЕНЕР (АРОМ)",
////    "ЗАКР 2/4 СК (АРОМ)",
////    "ЗАКР 2/4 СК (АРОМ)",
////    "ОТКЛ ЦЭН (АРОМ)",
////    "",
////    "",
////    "Т ГРЧ ГЦТ ≥ +3",
////    "Р РЕАК ≥ 170,3 кгс/см2",
////    "Р ГПК ≥ 65 кгс/см2",
////    "Т ДР, ДП, ИД ≤ 20",
////    "N ДР ≤ N УСТ"
////};

////QString strOutDiscr_pvk155_2pz[] = {
////    "ШАК 1.2 АЗ",
////    "ШАК 2.2 ПЗ",
////    "ШАК 1.2 АЗ",
////    "ШАК 2.2 ПЗ",
////    "ШАК 1.2 УПЗ",
////    "ШАК 2.2 УПЗ",
////    "РОМ",
////    "",
////    "",
////    "N ДП ≤ УСТ.ПЗ-2",
////    "P РЕАК ≥ 165,2 см2",
////    "ПАДЕНИЕ ОР",
////    "QL ≥ УСТ.ПЗ-2",
////    "DNBR ≤ УСТ ПЗ-2",
////    "ОТКЛ 1/4 ГЦН & N ≥ 75%",
////    "ОТКЛ ЭБ & N ≥ 75%",
////    "ВЫКЛ ГЕНЕР & N ≥ 75%",
////    "ОТКЛ 1/2 ТПН & N ≥ 75%",
////    "ЗАКР.2/4 СК. & N ≥ 75%",
////    "ОБОБЩ. ПЗ-1",
////    "ОБОБЩ. ПЗ-1",
////    "ОБОБЩ. УПЗ-1",
////    "",
////    "СРАБАТЫВАНИЕ ПЗ"
////};


////int cnv_out[7] {
////    0, //"0.вход.",
////    2, //"1.испр",
////    1, //"2.лин.св",
////    4, //3."имит.",
////    5,//4."блок",
////    3,//"5.результ",
////    0, //6."вх.лог" (см 153-154 узел)

////};


////QString str_pca_az[] = {
////    "P РЕАК",
////    "Т ХН 1",
////    "Т ХН 2",
////    "Т ХН 3",
////    "Т ХН 4",
////    "F ПИТ ГЦН 1",
////    "F ПИТ ГЦН 2",
////    "F ПИТ ГЦН 3",
////    "F ПИТ ГЦН 4",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "",
////    "",
////    ""
////};

////QString str_pca_pz[] = {
////    "F ПИТ ГЦН 1",
////    "F ПИТ ГЦН 2",
////    "F ПИТ ГЦН 3",
////    "F ПИТ ГЦН 4",
////    "","","","","","","","","","","","",
////};



//void Form::drawVTxt(QPainter *painter, const QPoint& p, const QString& str)
//{
////    QTransform old = painter->transform();
////    painter->translate(p);
////    painter->rotate(90);
////    painter->drawText(0, 0, str);
////    painter->setTransform(old);

//    //QPainter painter(this);
//    QTransform old = painter->transform();
//    painter->translate(p);
//    painter->rotate(270);
//    painter->drawText(0, 0, str);
//    //painter.rotate(-270);
//    painter->setTransform(old);
//}

//// вх.дискр сигнал для схем алгоритмов
//void Form::i1(int x, int y, int w, int h) {
//    QPainter painter(this);
//    QRect r1_outborder(x,y,w,h);
//    painter.drawRect(r1_outborder);
//    QRect r1_outter(r1_outborder.adjusted(1,1,0,0));
//    painter.fillRect(r1_outter, Qt::yellow);
//    QRect r1_inborder(r1_outter.adjusted(2,2,-3,-3));
//    painter.drawRect(r1_inborder);
//    QRect r1_inner(r1_inborder.adjusted(1,1,0,0));
//    painter.fillRect(r1_inner, Qt::red);

//    QRect r2_outborder(r1_outborder.x()+r1_outborder.width(),y,100,h);
//    painter.drawRect(r2_outborder);
//    QRect r2_outter(r2_outborder.adjusted(1,1,0,0));
//    painter.fillRect(r2_outter, Qt::red);
//    QRect r2_inborder(r2_outter.adjusted(2,2,-3,-3));
//    painter.drawRect(r2_inborder);
//    QRect r2_inner(r2_inborder.adjusted(1,1,0,0));
//    painter.fillRect(r2_inner, Qt::gray);

//    QRect r3_outborder(r2_outborder.x()+r2_outborder.width(),y,20,h);
//    painter.drawRect(r3_outborder);
//    QRect r3_outter(r3_outborder.adjusted(1,1,0,0));
//    painter.fillRect(r3_outter, Qt::red);
//}

//int dSlideN;

//void Form::paintEvent(QPaintEvent* e) {
//    if(dSlideN==0) {
//        paintEvent1(in151);
//    }
//    else if(dSlideN==1) {
//        paintEvent1(out155az);
//    }

//}

//void Form::paintEvent1(DevType type) {
//    int i,j;
//    int x=0;

//    QPainter p(this);

//    QFont oldfont, font = p.font();
//    oldfont = font;
//    font.setPixelSize(28);
//    p.setFont(font);
//    if(type == in151)
//        p.drawText(QPoint(175, 28), "Входные дискретные сигналы");
//    else if(type==pca)
//        p.drawText(QPoint(175, 28), "Выходные частотные сигналы");
//    else
//        p.drawText(QPoint(175, 28), "Выходные дискретные сигналы");
//    p.setFont(oldfont);


//    font = p.font();
//    oldfont = font;
//    font.setPixelSize(14);
//    p.setFont(font);

//    if(type==out155az) {
//        p.drawText(QPoint(145, 70), "ПВК-151Р 1");
//        p.drawText(QPoint(545, 70), "ПВК-151Р 2");
//    }
//    else if(type==pca) {
//        p.drawText(QPoint(145, 70), "ПЧА-08Р АЗ");
//        p.drawText(QPoint(545, 70), "ПЧА-08Р ПЗ");
//    }
//    else if(type==out155az)
//        p.drawText(QPoint(145, 70), "ПВК-155Р АЗ");
//    else if(type==out155pz)
//            p.drawText(QPoint(145, 70), "ПВК-155Р ПЗ");


//    p.setFont(oldfont);

//    // гориз.линия сверху
//    p.drawLine(0, 35, 799, 35);

//    // вертикальные линии
//    p.drawLine(400, 35, 400, 599);
//    p.drawLine(799, 120, 799, 120+20*24);


//    // табл.слева (для ПВК 151_1)
//    // горизонтальные линии, текст и прямоугольники (по 6 шт в строке)
//    QRect rect(300, 120+2, 10, 15);
//    for(i=0;i<24;i++) {
//        //i1(x,y+ i*h + 1,w,h);
//        p.drawLine(0, 120+20*i, 400, 120+20*i);
//        p.drawText(QPoint(5, 120+20*i + 15), strDiscr_pvk151_1[i]);
//        rect.moveTop(120+2 + i*20);
//        x = rect.x();
//        for(j=0;j<7;j++) {
//            rect.moveLeft(x + j*15);
//            //p.fillRect(rect, j%2?Qt::red:Qt::green);
//            p.fillRect(rect, valData[p151_1][cnv_in[j*24 + i]]? Qt::red : Qt::green);
//        }
//        rect.moveLeft(x);
//    }

//    // табл.слева (для ПВК 151_1)
//    // горизонтальные линии, текст и прямоугольники (по 6 шт в строке)
//    rect.moveLeft(700);
//    for(i=0;i<24;i++) {
//        //i1(x,y+ i*h + 1,w,h);
//        p.drawLine(400, 120+20*i, 799, 120+20*i);
//        p.drawText(QPoint(5 + 400, 120+20*i + 15), strDiscr_pvk151_2[i]);
//        rect.moveTop(120+2 + i*20);
//        x = rect.x();
//        for(j=0;j<7;j++) {
//            rect.moveLeft(x + j*15);
//            //p.fillRect(rect, j%2?Qt::red:Qt::green);
//            p.fillRect(rect, valData[p151_2][cnv_in[j*24 + i]]? Qt::red : Qt::green);
//        }
//        rect.moveLeft(x);
//    }

//    // подписи к колонкам с прямоугольниками
//    for(i=0; i<7; i++) {
//        drawVTxt(&p, QPoint(310 + 15*i, 118), strDiscr_columns[i]);
//        drawVTxt(&p, QPoint(710 + 15*i, 118), strDiscr_columns[i]);
//    }
//}

