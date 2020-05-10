#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>
#include <LinkedList.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "arch/e.h"

class Parser
{
public:
    Parser();

    static E *e;
    static void run(char *dest, char *s);

private:
    static LinkedList<char *> tokenize(char *s);
    static void parse(char *dest, LinkedList<char *> &tk);
};

#endif
