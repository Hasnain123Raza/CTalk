#ifndef APPLICATION_COMMON_H
#define APPLICATION_COMMON_H

#include <netinet/in.h>

#include "config.h"

typedef struct {
    struct in_addr address;
    unsigned short port; 
    char username[USERNAME_MAX_LENGTH + 1];
} ApplicationConfigurations;

#endif