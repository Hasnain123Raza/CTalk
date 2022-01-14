#include "ArgumentParser.h"

const char *argp_program_bug_address = PACKAGE_BUGREPORT;
const char *argp_program_version = PACKAGE_STRING;

static int parse_opt(int key, char *arg, struct argp_state *state);

void parseArguments(int argc, char **argv, ApplicationConfigurations *configurations)
{
    struct argp_option options[] = {
        { "address", 'a', "ADDRESS", 0, "IPv4 address" },
        { "port", 'p', "NUMBER", 0, "Port number" },
        { "username", 'u', "STRING", 0, "Username" },
        { 0 }
    };

    struct argp argp = { options, parse_opt, NULL, NULL, NULL, NULL, NULL };

    if (argp_parse(&argp, argc, argv, 0, NULL, (void *)configurations) == -1)
        exit(EXIT_FAILURE);

    if (configurations->address.s_addr == 0)
    {
        printf("IPv4 address is required\n");
        exit(EXIT_FAILURE);
    }

    if (configurations->port == 0)
    {
        printf("Port number is required\n");
        exit(EXIT_FAILURE);
    }

    if (strlen(configurations->username) == 0)
    {
        printf("Username is required\n");
        exit(EXIT_FAILURE);
    }
}

static int parse_opt(int key, char *arg, struct argp_state *state)
{
    ApplicationConfigurations *configurations = (ApplicationConfigurations *)state->input;

    switch (key) {
        case 'a':
            configurations->address;
            if (inet_pton(AF_INET, arg, &configurations->address) != 1)
                argp_error(state, "Invalid IPv4 address");
            break;
        case 'p':
            configurations->port = htons(atoi(arg));
            break;
        case 'u':
            strncpy(configurations->username, arg, USERNAME_MAX_LENGTH);
            for (int index = 0; index < USERNAME_MAX_LENGTH; index++)
            {
                if (configurations->username[index] == '\0')
                    break;

                if (isalnum(configurations->username[index]) == 0)
                    argp_error(state, "Invalid username");
            }
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}