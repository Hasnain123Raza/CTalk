#include "ArgumentParser.h"

const char *argp_program_bug_address = PACKAGE_BUGREPORT;
const char *argp_program_version = PACKAGE_STRING;

static int parse_opt(int key, char *arg, struct argp_state *state);

void parseArguments(int argc, char **argv, ApplicationConfigurations *configurations)
{
    struct argp_option options[] = {
        { "port", 'p', "NUMBER", 0, "Port number" },
        { 0 }
    };

    struct argp argp = { options, parse_opt, NULL, NULL, NULL, NULL, NULL };

    if (argp_parse(&argp, argc, argv, 0, NULL, (void *)configurations) == -1)
        exit(EXIT_FAILURE);

    if (configurations->port == 0)
    {
        printf("Port number is required\n");
        exit(EXIT_FAILURE);
    }
}

static int parse_opt(int key, char *arg, struct argp_state *state)
{
    ApplicationConfigurations *configurations = (ApplicationConfigurations *)state->input;

    switch (key) {
        case 'p':
            configurations->port = htons(atoi(arg));
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }

    return 0;
}