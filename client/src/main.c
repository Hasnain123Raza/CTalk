#include <stdio.h>

#include "ApplicationCommon.h"
#include "ArgumentParser.h"
#include "Client.h"
#include "config.h"

int main(int argc, char **argv)
{
    ApplicationConfigurations configurations = { 0 };
    parseArguments(argc, argv, &configurations);

    printf("%s\n", PACKAGE_STRING);
    printf("Client status: %d\n", initializeClient());

    return 0;
}