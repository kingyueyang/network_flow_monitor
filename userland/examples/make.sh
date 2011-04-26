#/bin/sh

gcc -g  -Wall -I../../kernel -I../../kernel/plugins -I../lib -I../libpcap-1.1.1-ring   -c testing.c -o testing.o
gcc testing.o ../libpcap-1.1.1-ring/libpcap.a   ../lib/libpfring.a -lpthread -o testing
