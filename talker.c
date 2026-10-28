#include <stdio.h>
#include "anel.h"

// receiver listening port


int main(int argc, char *argv[])
{
    
    int sockfd = cria_socket_datagram_talker(argv[1], argv[2], sizeof(argv[2]));

    fecha_socket_datagram(sockfd);

    return 0;
}