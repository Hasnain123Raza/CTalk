#include <stdio.h>

#include "Server.h"

int main(void)
{
    printf("Hello, World!\n");
    printf("Server status: %d\n", initializeServer());

    return 0;
}