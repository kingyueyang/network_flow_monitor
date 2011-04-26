/*
 * =====================================================================================
 *
 *       Filename:  PFtesting.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/18/2011 03:44:50 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YueYang (www.sibo.net.cn), bj.yueyang@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <signal.h>
#include <pcap.h>

#include "pfring.h"

#define DEVICE "eth0"
#define PROMISC 1
#define PACK_LEN 1500
#define ERET -1

using namespace std;

int recv_size = 0;
pfring *pd;
u_int clusterid = 1;
u_char buff[1024];
struct pfring_pkthdr phdr;

    void
print_stats() {
    printf("pfring stats:\n");
}

    void
per_secound_sigalarm(int sig) {
  print_stats();
  alarm(ALARM_SLEEP);
  signal(SIGALRM, per_secound_sigalarm);
}

    int
main(int argc, char* argv[]) {
    if( NULL == (pd = pfring_open(DEVICE, PROMISC, PACK_LEN, 0)) ) {
        printf("error in open\n");
        return ERET;
    }
    else {
        printf("Using pfring open device: %p\n", pd);
    }
    printf("\nprepare to receive packet...\n");

    while(1) { 
        recv_size = pfring_recv(pd, (char*)buff, sizeof(buff), &phdr, 1);
        if(recv_size <= 0) {
            printf("error in recv\n");
            return ERET;
        }
        else {
            printf("recv a pkt!\n");
        }
    }

    //TODO add signal
    signal(SIGINT, sigproc);
    signal(SIGTERM, sigproc);
    signal(SIGINT, sigproc);

    signal(SIGALRM, per_secound_sigalarm);
    alarm(ALARM_SLEEP);



    pfring_close(pd);
    printf("cloes device...\n");
    sleep(1);
    return 0;
}
