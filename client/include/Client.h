#ifndef CLIENT_H
#define CLIENT_H

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "ApplicationCommon.h"

int getClientSocketFileDescriptor(ApplicationConfigurations* configurations);
int closeClientSocketFileDescriptor(int socketFileDescriptor);

#endif