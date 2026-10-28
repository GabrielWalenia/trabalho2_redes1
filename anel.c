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

int cria_socket_datagram_talker(char *hostname, char* msg, unsigned long msg_length){
    int sockfd;
    struct sockaddr_in rcvr_addr;
    struct hostent *he;
    int numbytes;

    // translates receiver name to address
    he = gethostbyname(hostname) ;
    if (he == NULL)
    {
        perror("gethostbyname");
        return 0;
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
        return 0;
    }

    // sends the message to the receiver using the socket
    numbytes = sendto (sockfd, msg, msg_length, 0,
                       (struct sockaddr *) &rcvr_addr,
                       sizeof(struct sockaddr)) ;
    if (numbytes == -1)
    {
        perror("sendto");
        return 0;
    }

    
    return sockfd;
}

int cria_socket_datagram_listner(){
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
        return 0;
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
        return 0;
    }

    // waits for a packet arriving to the socket
    addr_len = sizeof(struct sockaddr);

    numbytes = recvfrom(sockfd, buf, MAXBUFLEN-1 , 0,
                        (struct sockaddr *) &sndr_addr, &addr_len) ;
    if (numbytes == -1)
    {
        perror ("recvfrom");
        return 0;
    }

    return sockfd;

}

int estabelece_conexao(){
    return 0;
}
int fecha_socket_datagram(int sockfd){
    close(sockfd);
    return 0;
}