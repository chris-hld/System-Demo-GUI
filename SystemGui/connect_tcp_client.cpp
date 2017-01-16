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
#include "connect_tcp_client.h"
#include "parameter.h"
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
    bzero(buffer,256);

    while(1) {  // Keep connection open
        if (fgets(buffer,255,stdin) != NULL){
          n = send(sockfd,buffer,strlen(buffer), 0);
        }
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
    bzero(buffer,256);

    while(1) {  // Keep connection open
        n = recv(sockfd,buffer,255, 0);
        if (n < 0){
            error("ERROR reading from socket");
            break;
        }
        printf("%s",buffer);  // "%s\n"
    }
}


void connect_me(const char* hostname, int portno)
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    printf("Trying to connect to %s : %i \n", hostname, portno);
    // create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    // get the server's DNS entry from hostname
    server = gethostbyname(hostname);
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

    extern Parameter global_socket;
    global_socket.setSocket(sockfd);
    printf("Socket: %d\n",global_socket.getSocket());

    // Transmission
    printf("--- Connection established --- \n");

    std::thread reading (read_TCP, sockfd);     // spawn new thread
    std::thread writing (write_TCP, sockfd);  // spawn new thread
    // synchronize threads:
    reading.join();                // pauses until finished
    writing.join();               // pauses until finished

    close(sockfd);
    //return 0;
}

void connect_viaButton(const char* hostname, int portno)
{
    connect_me(hostname, portno);
}

void close_connection()
{
    extern Parameter global_socket;
    close(global_socket.getSocket());
    printf("--- Socket closed --- \n");
};


void send_TCP(const char *msg)
{
    int n;
    extern Parameter global_socket;

    n = send(global_socket.getSocket(), msg, strlen(msg), 0);
    if (n < 0){
        error("ERROR writing to socket");
    }

}
