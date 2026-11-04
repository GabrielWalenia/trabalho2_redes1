#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "anel.h"

int main(void) {

    struct sockaddr_in remetente;
    char buffer[1000];

    int soquete = cria_socket_datagram();

    if (soquete == -1) {
        return 1;
    }

    if (envia_mensagem(soquete, "10.254.223.68", "Oi", remetente) == -1) {
        fecha_socket_datagram(soquete);
        return 1;
    }

    if (recebe_mensagem(soquete, buffer, 1000, &remetente) == -1) {
        fecha_socket_datagram(soquete);
        return 1;
    }

    printf("Mensagem recebida: %s\n", buffer);

    fecha_socket_datagram(soquete);

    return 0;
}