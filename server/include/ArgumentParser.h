#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include <argp.h>
#include <arpa/inet.h>
#include <stdlib.h>

#include "ApplicationCommon.h"
#include "config.h"

void parseArguments(int argc, char **argv, ApplicationConfigurations *configurations);

#endif