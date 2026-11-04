#include <netinet/in.h>
#ifndef __ANEL__
#define __ANEL__

int cria_socket_datagram();
int envia_mensagem(int sockfd, char *ip, char *msg, struct sockaddr_in destino);
int recebe_mensagem(int sockfd, char *buf, int tamanho_buf, struct sockaddr_in *remetente);
int estabelece_conexao();
int fecha_socket_datagram(int sockfd);

#endif