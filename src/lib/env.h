#ifndef ENV_H
#define ENV_H

#include <LinkedList.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "lib/parser.h"

void add(char* dest, LinkedList<char *> &args)
{
    int initial = atoi(args.shift());
    while(args.size() != 0) initial += atoi(args.shift());

    sprintf(dest,"%d", initial);
}

void mult(char* dest, LinkedList<char*> &args)
{
    int initial = atol(args.shift());
    while(args.size() != 0) initial *= atoi(args.shift());
    
    sprintf(dest,"%d", initial);
}

void sub(char* dest, LinkedList<char*> &args)
{
    int initial = atol(args.shift());
    while(args.size() != 0) initial -= atoi(args.shift());
    
    sprintf(dest,"%d", initial);
}

void read(char* dest, LinkedList<char*> &args)
{
    int address = atoi(args.shift());
    
    sprintf(dest, "%02x", Parser::e->read(address));
}

void write(char* dest, LinkedList<char*> &args)
{
    int address = atoi(args.shift());
    int value = atoi(args.shift());

    Parser::e->write(address, value);

    delay(10);
    
    sprintf(dest, "%02x", Parser::e->read(address));
}

void merge(char* dest, LinkedList<char*> &args)
{
  strcpy(dest, args.shift());

  char* t;
  while(t = args.shift(), *t != ')' && args.size() != 0) strcat(dest, t);
}

void first(char* dest, LinkedList<char*> &args)
{
  dest[0] = args.shift()[0];
  dest[1] = '\0';
}

void last(char* dest, LinkedList<char*> &args)
{
  dest[0] = args.shift()[1];
  dest[1] = '\0';
}

#endif