mach1: anel
	gcc mach1.c anel.o -o mach1

mach2: anel
	gcc mach2.c anel.o -o mach2

anel: anel.h
	gcc anel.c -c anel.o

clear:
	rm -rf client server anel.o