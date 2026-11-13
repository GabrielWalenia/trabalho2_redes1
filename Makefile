all: roleta.o
	gcc main.c roleta.o -o principal
roleta:
	gcc roleta.c roleta.h -o roleta
server:
	gcc listener.c -o server
client:
	gcc talker.c -o client

clean:
	rm *.o $(obejct)