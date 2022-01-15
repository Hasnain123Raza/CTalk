#include "Client.h"

int getClientSocketFileDescriptor(ApplicationConfigurations* configurations)
{
    struct addrinfo hints = { 0 };
    struct addrinfo *result;

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    char *address = (char *)malloc(sizeof(char) * INET_ADDRSTRLEN);
    if (!address)
    {
        printf("Failed to allocate memory for address\n");
        return 1;
    }
    inet_ntop(AF_INET, &(configurations->address.s_addr), address, INET_ADDRSTRLEN);

    int portStringLength = snprintf(NULL, 0, "%d", configurations->port);
    char *port = (char *)malloc(sizeof(char) * (portStringLength + 1));
    if (!port)
    {
        printf("Failed to allocate memory for port\n");
        free(address);
        return 1;
    }
    snprintf(port, portStringLength + 1, "%d", configurations->port);

    int status = getaddrinfo(address, port, &hints, &result);
    if (status != 0)
    {
        printf("getaddrinfo failed with error: %s\n", gai_strerror(status));
        free(address);
        free(port);
        return 1;
    }

    int socketFileDescriptor = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    free(address);
    free(port);
    freeaddrinfo(result);
    if (socketFileDescriptor == -1)
    {
        printf("Failed to create socket with error: %s\n", strerror(errno));
        return 1;
    }

    while (1)
    {
        if (connect(socketFileDescriptor, result->ai_addr, result->ai_addrlen) == -1)
        {
            if (errno == EINTR)
            {
                continue;
            }
            else
            {
                printf("Failed to connect with error: %s\n", strerror(errno));
                return 1;
            }
        }

        break;
    }

    return socketFileDescriptor;
}

int closeClientSocketFileDescriptor(int socketFileDescriptor)
{
    while (1)
    {
        if (close(socketFileDescriptor) == -1)
        {
            if (errno == EINTR)
            {
                continue;
            }
            else
            {
                printf("Failed to close socket with error: %s\n", strerror(errno));
                return 1;
            }
        }

        break;
    }

    return 0;
}