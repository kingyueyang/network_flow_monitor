/*
 * =====================================================================================
 *
 *       Filename:  testing.c
 *
 *    Description:  testing pf_ring
 *
 *        Version:  1.0
 *        Created:  04/14/2011 02:19:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YueYang (blog.163.com/it_ningjing), bj.yueyang@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */


#include <pcap.h>

#include "pfring.h"

#define DEVICE "eth0"
#define PROMISC 1
#define PACK_LEN 1500
#define ERET -1

int if_err = 0;
pfring *pd;
u_int clusterid = 1;
u_char buff[1024];
struct pfring_pkthdr phdr;

int
main(int argc, char* argv[]) {
    if(NULL == (pd = pfring_open(DEVICE, PROMISC, PACK_LEN, 0)) ) {
        printf("error in open\n");
        return ERET;
    }
    else {
        printf("Using pfring open device: %p\n", pd);
    }

    printf("prepare to receive packet...");
    if_err = pfring_recv(pd, (char*)buff, sizeof(buff), &phdr, 1);
    if(if_err <= 0) {
        printf("error in recv\n");
        return ERET;
    }
    else {
        printf(" OK!\n");
    }

    /*printf("prepare to add in a cluster...");*/
    /*[>cluster_per_flow is enum in cluster struct ,equivanlen 0 <]*/
    /*[>and other value is cluster_round_robin<]*/
    /*if_err = pfring_set_cluster(pd, clusterid, cluster_per_flow);*/
    /*if(-1 == if_err) {*/
        /*return ERET;*/
    /*}*/
    /*else {*/
        /*printf(" OK!\n");*/
    /*}*/

    /*have some issue*/
#if 0
    printf("prepare to add in a cluster...");
    if_err = pfring_remove_from_cluster(pd);
    if(-1 == if_err) {
        return ERET;
    }
    else {
        printf(" OK!\n");
    }
#endif

    pfring_close(pd);
    printf("cloes device...\n");
    sleep(1);

    return 0;
} 
