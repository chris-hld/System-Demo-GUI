#include <iostream>

#include "parameter.h"

int Parameter::getSocket()
{
  return sockfd;
}

const char* Parameter::getHostname()
{
  return hostname;
}

int Parameter::getPortno()
{
  return portno;
}

void Parameter::setSocket(int s)
{
  sockfd = s;
}

void Parameter::setHostname(const char* h) {
  hostname = h;
}

void Parameter::setPortno(int p) {
  portno = p;
}
