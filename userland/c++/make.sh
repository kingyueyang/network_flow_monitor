#/bin/sh

g++ -g  -c -I../../kernel -I../libpcap-1.1.1-ring -I../lib PFring.cpp
ar rc libpfring_cpp.a PFring.o libpfring_cpp.a
ranlib libpfring_cpp.a
g++ -g  -I../../kernel -I../libpcap-1.1.1-ring -I../lib PFtesting.cc libpfring_cpp.a ../libpcap-1.1.1-ring/libpcap.a -o PFtesting ../lib/libpfring.a -lpthread
