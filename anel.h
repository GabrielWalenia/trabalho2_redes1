#ifndef __ANEL__
#define __ANEL__

int cria_socket_datagram_talker(char *hostname, char *msg, unsigned long msg_length);
int cria_socket_datagram_listner();
int estabelece_conexao();
int fecha_socket_datagram(int sockfd);

#endif