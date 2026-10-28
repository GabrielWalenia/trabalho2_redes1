#include <stdio.h>
#include <sys/socket.h>
#include "anel.h"

int main(void)
{
    
    int sockfd = cria_socket_datagram_listner();
    fecha_socket_datagram(sockfd);

    return 0;
}