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

/* ------ TALVEZ MUDAR -------------*/
#define RCVR_PORT 4950

#define MAXBUFLEN 100
/* ------ TALVEZ MUDAR -------------*/

int cria_socket_datagram(void) {

    int sockfd;
    struct sockaddr_in local_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    memset(&local_addr, 0, sizeof(local_addr));

    local_addr.sin_family = AF_INET;
    local_addr.sin_port = htons(RCVR_PORT);
    local_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1) {

        perror("bind");
        close(sockfd);
        return -1;

    }

    return sockfd;

}

int envia_mensagem(int sockfd, char *ip, char *msg,
                   struct sockaddr_in destino) {

    int numbytes;

    memset(&destino, 0, sizeof(destino));

    destino.sin_family = AF_INET;
    destino.sin_port = htons(4950);

    if (inet_pton(AF_INET, ip, &destino.sin_addr) != 1) {
        perror("inet_pton");
        return -1;
    }

    numbytes = sendto(sockfd, msg, strlen(msg), 0,
                      (struct sockaddr *)&destino,
                      sizeof(destino));

    if (numbytes == -1) {
        perror("sendto");
        return -1;
    }

    return numbytes;
}

int recebe_mensagem(int sockfd, char *buf, int tamanho_buf, struct sockaddr_in *remetente) {

    socklen_t addr_len = sizeof(*remetente);

    int numbytes = recvfrom(sockfd, buf, tamanho_buf - 1, 0, (struct sockaddr *)remetente, &addr_len);

    if (numbytes == -1) {
        perror("recvfrom");
        return -1;
    }

    buf[numbytes] = '\0';

    return numbytes;

}

int fecha_socket_datagram(int sockfd){
    close(sockfd);
    return 0;
}