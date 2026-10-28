all: server client

server: anel
	gcc listener.c anel.o -o client
client: anel
	gcc talker.c anel.o -o server

anel: anel.h
	gcc anel.c -c anel.o

clear:
	rm -rf client server anel.o