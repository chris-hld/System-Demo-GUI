#ifndef CONNECT_TCP_CLIENT
#define CONNECT_TCP_CLIENT

void error(const char *msg);
void read_TCP(int sockfd);
void write_TCP(int sockfd);

void connect_me(const char* hostname, int portno);
void connect_viaButton(const char* hostname, int portno);

void send_TCP(const char *msg);
#endif // CONNECT_TCP_CLIENT
