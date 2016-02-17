#include "ethrecv.h"

//EthRecv::EthRecv(){}
//EthRecv::~EthRecv(){}

#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <linux/ip.h>
#include <linux/udp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/ether.h>
#include <thread>
#include <chrono>         // std::chrono::seconds
#include <iostream>
#include <QDebug>
#include "ethrecv.h"

#define ETHER_TYPE	0xFFFF
#define DEFAULT_IF	"eth0"

extern unsigned char valData[ETH_SRC_NUM][1600];
//const int ethBufBytes = 1516;
int idToN(unsigned char byte_id);
unsigned tBuf[400];

unsigned char ethErrFlag[ETH_SRC_NUM_MAX];
unsigned char lastCnt[ETH_SRC_NUM_MAX];
unsigned char cntPk[ETH_SRC_NUM_MAX];
unsigned int errCnt[ETH_SRC_NUM_MAX];
unsigned char ethCode[ETH_SRC_NUM_MAX] = { 0x8,0xA,0xC,0xE,
                              0x10,0x12,0x14,0x16,
                              0x18,0x1A,0x1C,0x1E,
                              0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,
                              0x28,0x2A,0x2C,0x2E,
                              0x30,0x34,0x36
                            };



//char ethName   [ETH_SRC_NUM_MAX][20] {
//    "153 АЗ", "153 ПЗ", "154 АЗ", "154 ПЗ",
//    "151№1", "151№2", "152№1", "152№2",
//    "157№1", "157№2", "158№1", "158№2",
//    "155 АЗ №1", "155 АЗ №2", "155 ПЗ №1", "155 ПЗ №2",
//    "156 АЗ №1", "156 АЗ №2", "156 ПЗ №1", "156 ПЗ №2",
//    "ПЧА-08 АЗ", "ПЧА-08 ПЗ", "ПЧА-09 АЗ", "ПЧА-09 ПЗ",
//    "ПКЦ-184", "ПКЦ-185", "ПКЦ-186" };

//char ethName   [ETH_SRC_NUM_MAX][20] {
//    "153/154 АЗ", "153/154 ПЗ",
//    "151/152№1", "151/152№2",
//    "157№1/2", "158№1/2",
//    "155/6 АЗ №1", "155/6 АЗ №2", "155/6 ПЗ №1", "155/6 ПЗ №2",
//    "ПЧА-08/9 АЗ", "ПЧА-08/9 ПЗ",
//    "ПКЦ-184/5/6"};

//Pvk { p153az=0, p153pz=1,
//           p151_1=2, p151_2=3,
//           p157=4, p158=5,
//           p155az1=6, p155az2=7, p155pz1=8, p155pz2=9,
//           p08az=10, p08pz=11,
//           pkc=12 };
unsigned char adrToIndex[ETH_SRC_NUM_MAX] = { 0,1,0,1,
                                              2,3,2,3,
                                              4,5,4,5,
                                              6,7,8,9,
                                              6,7,8,9,
                                              10,11,10,11,
                                              12,12,12};

void ethRead() {
    ether_header *eh = (ether_header *) tBuf;
    int sockfd;
    int sockopt;
    ssize_t numbytes;
    struct ifreq ifopts;	// set promiscuous mode
    char ifName[IFNAMSIZ] = "eth0";
    int i;
    unsigned char id, uz;

    for(i=0;i<ETH_SRC_NUM;i++)
        errCnt[i]=lastCnt[i]= cntPk[i]=0;

    // Open PF_PACKET socket, listening for EtherType ETHER_TYPE
    if ((sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETHER_TYPE))) == -1) {
        perror("listener: socket");
        //return -1;
    }

    // Set interface to promiscuous mode - do we need to do this every time?
    strncpy(ifopts.ifr_name, ifName, IFNAMSIZ-1);
    ioctl(sockfd, SIOCGIFFLAGS, &ifopts);
    ifopts.ifr_flags |= IFF_PROMISC;
    ioctl(sockfd, SIOCSIFFLAGS, &ifopts);
    // Allow the socket to be reused - incase connection is closed prematurely
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof sockopt) == -1) {
        perror("setsockopt");
        //close(sockfd);
        exit(EXIT_FAILURE);
    }
    // Bind to device
    if (setsockopt(sockfd, SOL_SOCKET, SO_BINDTODEVICE, ifName, IFNAMSIZ-1) == -1)	{
        perror("SO_BINDTODEVICE");
        //close(sockfd);
        exit(EXIT_FAILURE);
    }
    int cntr=0;
    for(;;) {
        //printf("listener: Waiting to recvfrom...\n");
        numbytes = recvfrom(sockfd, tBuf, 1514 , 0, NULL, NULL); // TODO остальные поля проверить, тип эзернета
        //printf("listener: got packet %lu bytes\n", numbytes);

        //int pkN = idToN(eh->ether_shost[5]);
        //if(pkN<0) continue;

        //cntPk[pkN] = * (  (int*) ( &((unsigned char*)tBuf)[14+1])  );

        // *** подсчет ошибок ***
        id = eh->ether_shost[5];

        uz = id >> 2; // сдвинутые на 2 бита вправо
        if(uz>=0x20 && uz<=0x27) // кроме 155, 156
            uz &= 0xff;
        else
            uz &= 0xfe;
        // ищем соответстве MAC-адреса индексу пакета чтобы переписать в этот пакет по нужному индексу
        for(i=0;i<ETH_SRC_NUM_MAX;i++) {
            if(uz == ethCode[i]) {
                i = adrToIndex[i];
                cntPk[i] =  ((unsigned char*)tBuf)[14] ;
                if(lastCnt[i] ==255) {
                    if (0 != cntPk[i]) {
                        errCnt[i]++;
                        ethErrFlag[i]=1;
                     }
                     else
                        ethErrFlag[i]=0;
                }
                else {
                    if (lastCnt[i]+1 != cntPk[i]) {
                        errCnt[i]++;
                        ethErrFlag[i]=1;
                    }
                    else
                        ethErrFlag[i]=0;
                }

                lastCnt[i] = cntPk[i];
                break;
            }
        }


       //qDebug()<<cntPk[i]<<QString(" : ")<<QString(i)<<QString("\n");



        // копируем данные, без eth-заголовка и без номера пакета в 0м байте
        // TODO переделать чтобы переписывать сразу на свое место
        //int pkN = idToN(eh->ether_shost[5]);
        memcpy(valData[i], (unsigned char*)eh + 15, numbytes-15);

//        printf("%x%x%x%x%x%x\n", eh->ether_shost[0], eh->ether_shost[1], eh->ether_shost[2],
//             eh->ether_shost[3], eh->ether_shost[4], eh->ether_shost[5]);
//        printf("%x%x%x%x%x%x\n", eh->ether_dhost[0], eh->ether_dhost[1], eh->ether_dhost[2],
//             eh->ether_dhost[3], eh->ether_dhost[4], eh->ether_dhost[5]);
//        // Print packet
//        printf("\tData:");
//        for (int i=0; i<numbytes; i++) printf("%02x:", tBuf[i]);
//        printf("\n");

        //std::this_thread::sleep_for(std::chrono::milliseconds(50));

    } // for
    //close(sockfd);
    //return ret;
}

int idToN(unsigned char d) {
    int r;
         if(d>=0x20 && d<=0x27) r=0; //153 АЗ
    else if(d>=0x28 && d<=0x2F) r=1; //153 ПЗ
    else if(d>=0x30 && d<=0x37) r=0; //154 АЗ
    else if(d>=0x38 && d<=0x3F) r=1; //154 ПЗ

    else if(d>=0x40 && d<=0x47) r=2; //151 1
    else if(d>=0x48 && d<=0x4F) r=3; //151 2
    else if(d>=0x50 && d<=0x57) r=2; //152 1
    else if(d>=0x58 && d<=0x5F) r=3; //152 2

    else if(d>=0x60 && d<=0x67) r=4; //157 1
    else if(d>=0x68 && d<=0x6F) r=5; //157 2
    else if(d>=0x70 && d<=0x77) r=4; //158 1
    else if(d>=0x78 && d<=0x7F) r=5; //158 2

    else if(d>=0x80 && d<=0x87) r=6; //155|156 АЗ 1
    else if(d>=0x88 && d<=0x8F) r=7; //155|156 АЗ 2
    else if(d>=0x90 && d<=0x97) r=8; //155|156 ПЗ 1
    else if(d>=0x98 && d<=0x9F) r=9; //155|156 ПЗ 2


    else if(d>=0xa0 && d<=0xa7) r=10; //ПЧА-08 АЗ
    else if(d>=0xa8 && d<=0xaF) r=11; //ПЧА-08 ПЗ
    else if(d>=0xb0 && d<=0xb7) r=10; //ПЧА-09 АЗ
    else if(d>=0xb8 && d<=0xbF) r=11; //ПЧА-09 ПЗ

    else if(d>=0xc0 && d<=0xdf) r=12;//ПКЦ 184..186

    //else if(d>=0xd8 && d<=0xdf) r=14;//ПКЦ 186

    else return -1;
    return r;
}
//#include <QString>
//QString getDevNam(int n) {
//    QString s;
//    switch(n) {
//    case 0: s = "153/154 АЗ"; break;
//    case 1: s = "153/154 ПЗ"; break;

//    case 2: s = "151/152 1"; break;
//    case 3: s = "151/152 2"; break;

//    case 4: s = "157/158 1"; break;
//    case 5: s = "157/158 2"; break;

//    case 6: s = "155/156-1 АЗ "; break;
//    case 7: s = "155/156-2 АЗ "; break;
//    case 8: s = "155/156-1 ПЗ "; break;
//    case 9: s = "155/156-2 ПЗ "; break;

//    case 10: s="ПЧА-08 АЗ"; break;
//    case 11: s="ПЧА-08 ПЗ"; break;
//    case 12: s="ПЧА-09 АЗ"; break;
//    case 13: s="ПЧА-09 ПЗ"; break;

//    case 14: s= "ПКЦ 184/185"; break;
//    case 15: s= "ПКЦ 186"; break;
//    }
//    return s;
//}
