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

    static Parser *pInstance;

    E *e;
    void setE(char *dest, LinkedList<char *> &args);

    void add(char *dest, LinkedList<char *> &args);
    void sub(char *dest, LinkedList<char *> &args);
    void mult(char *dest, LinkedList<char *> &args);
    void div(char *dest, LinkedList<char *> &args);
    void debug(char *dest, LinkedList<char *> &args);
    void read(char *dest, LinkedList<char *> &args);
    void write(char *dest, LinkedList<char *> &args);
    void hex2num(char *dest, LinkedList<char *> &args);
    void dump(char *dest, LinkedList<char *> &args);
    void position(char *dest, LinkedList<char *> &args);
    void merge(char *dest, LinkedList<char *> &args);
    void first(char *dest, LinkedList<char *> &args);
    void last(char *dest, LinkedList<char *> &args);
    void format(char *dest, LinkedList<char *> &args);

    void parse(char *dest, LinkedList<char *> &args);

    LinkedList<char *> tokenize(char *s);

public:
    static Parser *getInstance();

    void call(char *dest, char *s);
};

#endif
