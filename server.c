// provides required data types
#include <sys/types.h>
// holds address family and socket functions
#include <sys/socket.h>
// has the sockaddr_in structure
#include <netinet/in.h>
// has functions for read and write operations
#include <fcntl.h>
// basic C header
#include <stdio.h>
// header to help with strings
#include <string.h>
// has macros such as EXIT_FAILURE
#include<stdlib.h>
// port through which connection is to be made
#include <unistd.h>
#define CONNECTION_PORT 3500

/*
struct sockaddr_in {
   short int          sin_family;  // Address family
   unsigned short int sin_port;    // Port number (in network byte order)
   struct in_addr     sin_addr;    // Internet address (in network byte order)
   unsigned char      sin_zero[8]; // just fill this with zeros
}; 
*/
int main()
{
    int server_soquete;
    int client_soquete;
    struct sockaddr_in endereco;
    socklen_t socklen;

    endereco.sin_family = 0;
    endereco.sin_port = 0;
    endereco.sin_addr = 0;
    endereco.sin_zero = 0;

    server_soquete = socket (PF_INET,  SOCK_DGRAM,  0) ; /* socket UDP*/
    bind(server_soquete, )
    return 0;
}
