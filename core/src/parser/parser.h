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

private:
    Parser();

    static E *e;

    static void setE(char *dest, LinkedList<char *> &args);

    static void add(char *dest, LinkedList<char *> &args);
    static void sub(char *dest, LinkedList<char *> &args);
    static void mult(char *dest, LinkedList<char *> &args);
    static void div(char *dest, LinkedList<char *> &args);
    static void debug(char *dest, LinkedList<char *> &args);
    static void read(char *dest, LinkedList<char *> &args);
    static void write(char *dest, LinkedList<char *> &args);
    static void hex2num(char *dest, LinkedList<char *> &args);
    static void dump(char *dest, LinkedList<char *> &args);
    static void position(char *dest, LinkedList<char *> &args);
    static void merge(char *dest, LinkedList<char *> &args);
    static void first(char *dest, LinkedList<char *> &args);
    static void last(char *dest, LinkedList<char *> &args);
    static void format(char *dest, LinkedList<char *> &args);

    static void parse(char *dest, LinkedList<char *> &args);

    static LinkedList<char *> tokenize(char *s);

public:
    static void call(char *dest, char *s);
};

#endif
