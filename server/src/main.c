#include <stdio.h>

#include "ApplicationCommon.h"
#include "ArgumentParser.h"
#include "Server.h"
#include "config.h"

int main(int argc, char **argv)
{
    ApplicationConfigurations configurations;
    parseArguments(argc, argv, &configurations);

    printf("%s\n", PACKAGE_STRING);
    printf("Server status: %d\n", initializeServer());

    return 0;
}