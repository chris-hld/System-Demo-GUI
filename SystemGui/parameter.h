#ifndef PARAMETER_H
#define PARAMETER_H

class Parameter {
private:
  int sockfd;
  const char* hostname;
  int portno;

public:
  int getSocket();
  const char* getHostname();
  int getPortno();
  void setSocket(int s);
  void setHostname(const char* h);
  void setPortno(int p);
};

#endif  // PARAMETER_H
