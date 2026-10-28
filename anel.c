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

// the port I'll listen to
#define RCVR_PORT 4950

// input buffer size
#define MAXBUFLEN 100

int cria_socket_datagram_envia(char *hostname){
    int sockfd;
    struct sockaddr_in rcvr_addr;
    struct hostent *he;
    int numbytes;

    // translates receiver name to address
    he = gethostbyname(hostname) ;
    if (he == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }

    // fills the receiver struct info
    rcvr_addr.sin_family = AF_INET;
    rcvr_addr.sin_port   = htons(RCVR_PORT);
    rcvr_addr.sin_addr   = *((struct in_addr *)he->h_addr);

    // zeroes the rest of the struct
    memset(&(rcvr_addr.sin_zero), '\0', 8);

    // creates the UDP socket
    sockfd = socket (AF_INET, SOCK_DGRAM, 0) ;
    if (sockfd == -1)
    {
        perror("socket");
        exit(1);
    }


    return sockfd;
}
int cria_socket_datagram_ouve(){

    int sockfd;
    struct sockaddr_in rcvr_addr;
    struct sockaddr_in sndr_addr;
    int numbytes;
    socklen_t addr_len;
    char buf[MAXBUFLEN];

    // creates the UDP socket
    if ((sockfd = socket (AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    // fills struct with receiver's info
    rcvr_addr.sin_family = AF_INET;
    rcvr_addr.sin_port = htons(RCVR_PORT);   // short, network byte order
    rcvr_addr.sin_addr.s_addr = INADDR_ANY;  // automatically fill with my IP
    memset(&(rcvr_addr.sin_zero), '\0', 8);  // zero the rest of the struct

    // associates the socket to receiver's data (addr & port)
    if (bind (sockfd, (struct sockaddr *) &rcvr_addr,
              sizeof (struct sockaddr)) == -1)
    {
        perror("bind");
        exit(1);
    }
        // associates the socket to receiver's data (addr & port)
    if (bind (sockfd, (struct sockaddr *) &rcvr_addr,
              sizeof (struct sockaddr)) == -1)
    {
        perror("bind");
        exit(1);
    }

    return sockfd;
}
int estabelece_conexao(){
    return 0;
}
int fecha_socket_datagram(){
    return 0;
}