#include <stdio.h>

#include "ApplicationCommon.h"
#include "ArgumentParser.h"
#include "Client.h"
#include "config.h"

int main(int argc, char **argv)
{
    ApplicationConfigurations configurations = { 0 };
    parseArguments(argc, argv, &configurations);

    int socketFileDescriptor = getClientSocketFileDescriptor(&configurations);
    if (socketFileDescriptor != 0)
        return 1;
    
    getchar();

    closeClientSocketFileDescriptor(socketFileDescriptor);

    return 0;
}