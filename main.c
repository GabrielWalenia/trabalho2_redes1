#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "anel.h"
#include "mensagem.h"

int main(int argc, char *argv[]){

    if (argc != 3)
    {
        fprintf(stderr,"usage: talker hostname message\n");
        exit(1);
    }

    int sock_envia = cria_socket_datagram_envia(argv[1]);
    int sock_ouve = cria_socket_datagram_ouve();

    while(1){

    }
    return 0;
}