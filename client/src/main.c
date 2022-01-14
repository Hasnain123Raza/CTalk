#include <stdio.h>

#include "Client.h"

int main(void)
{
    printf("Hello, World!\n");
    printf("Client status: %d\n", initializeClient());

    return 0;
}