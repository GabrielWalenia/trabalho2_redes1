#include <stdio.h>
#include <sys/socket.h>
#include "anel.h"

int cria_socket_datagram(){
    int soquete = socket(AF_LOCAL, SOCK_DGRAM, 0);
    if(soquete < 0)
        return -1;
    
    return 0;
}
int estabelece_conexao(){
    return 0;
}
int fecha_socket_datagram(){
    return 0;
}