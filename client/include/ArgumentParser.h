#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include <argp.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ApplicationCommon.h"
#include "config.h"

void parseArguments(int argc, char **argv, ApplicationConfigurations *configurations);

#endif