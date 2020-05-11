#ifndef ENV_H
#define ENV_H

#include <LinkedList.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "parser/parser.h"
#include "arch/e95.h"
#include "arch/e24c.h"
#include "arch/e93c.h"

void add(char* dest, LinkedList<char *> &args)
{
    long initial = atol(args.shift());
    while(args.size() != 1) initial += atol(args.shift());

    sprintf(dest,"%ld", initial);
}

void mult(char* dest, LinkedList<char*> &args)
{
    long initial = atol(args.shift());
    while(args.size() != 1) initial *= atol(args.shift());
    
    sprintf(dest,"%ld", initial);
}

void div(char* dest, LinkedList<char*> &args)
{
    long initial = atol(args.shift());
    while(args.size() != 1) initial /= atol(args.shift());
    
    sprintf(dest,"%ld", initial);
}

void sub(char* dest, LinkedList<char*> &args)
{
    long initial = atol(args.shift());
    while(args.size() != 1) initial -= atol(args.shift());
    
    sprintf(dest,"%ld", initial);
}

void read(char* dest, LinkedList<char*> &args)
{
    E93c e(512, 9, 8);
    e.setup();

    int address = atoi(args.shift());
    
    sprintf(dest, "%02x", e.read(address));
}

void i(char* dest, LinkedList<char*> &args)
{
    long value = strtol(args.shift(), NULL, 16);
    
    sprintf(dest, "%ld", value);
}

void removeLast(char* dest, LinkedList<char*> &args)
{
  char* initial = args.shift();
  initial[strlen(initial)-1] = '\0';

  strcpy(dest, initial);
}

void write(char* dest, LinkedList<char*> &args)
{
    E93c e(512, 9, 8);
    e.setup();

    int address = atoi(args.shift());
    int value = atoi(args.shift());

    e.write(address, value);

    delay(10);

    sprintf(dest, "%02x", e.read(address));
}

void position(char* dest, LinkedList<char*> &args)
{
  int position = atoi(args.shift());
  
  dest[0] = args.shift()[position];
  dest[1] = '\0';
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

void format(char* dest, LinkedList<char*> &args)
{
    long initial = atol(args.shift());
    char *format = args.shift();
    
    sprintf(dest, format, initial);
}

#endif