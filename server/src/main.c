#include <stdio.h>

#include "Server.h"
#include "config.h"

int main(void)
{
    printf("%s\n", PACKAGE_STRING);
    printf("Server status: %d\n", initializeServer());

    return 0;
}