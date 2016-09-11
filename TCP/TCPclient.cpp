//#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <thread>         // std::thread

/* Syntax: client <ServerIP> <Port>
Adapted from:
http://www.linuxhowtos.org/C_C++/socket.htm
Compile: g++ -std=c++0x TCPclient.cpp -o client -pthread
*/

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

void read_TCP(int sockfd)
{
    int n;
    char buffer[256];

    while(1) {  // Keep connection open
        bzero(buffer,256);
        fgets(buffer,255,stdin);
        n = send(sockfd,buffer,strlen(buffer), 0);
        if (n < 0){
            error("ERROR writing to socket");
            break;
        }
    }
}

void write_TCP(int sockfd)
{
    int n;
    char buffer[256];

    while(1) {  // Keep connection open
        bzero(buffer,256);
        n = recv(sockfd,buffer,255, 0);
        if (n < 0){
            error("ERROR reading from socket");
            break;
        }
        printf("%s",buffer);  // "%s\n"
    }
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    // command line arguments
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    // create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    // get the server's DNS entry from hostname: argv[1]
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // build server adress
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    // Connect
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Transmission
    printf("Connection established: \n");

    std::thread reading (read_TCP, sockfd);     // spawn new thread
    std::thread writing (write_TCP, sockfd);  // spawn new thread
    // synchronize threads:
    reading.join();                // pauses until finished
    writing.join();               // pauses until finished

    close(sockfd);
    return 0;
}
