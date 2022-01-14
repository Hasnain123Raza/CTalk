#include <stdio.h>

#include "Client.h"
#include "config.h"

int main(void)
{
    printf("%s\n", PACKAGE_STRING);
    printf("Client status: %d\n", initializeClient());

    return 0;
}