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
    char *a = args.shift();
    long initial = atol(a);

    delete [] a;

    while(args.size() > 0) {
      char *b = args.shift();
      initial += atol(b);
      
      delete [] b;
    }

    sprintf(dest,"%ld", initial);
}

void mult(char* dest, LinkedList<char*> &args)
{
    char *a = args.shift();
    long initial = atol(a);

    delete [] a;

    while(args.size() > 0) {
      char *b = args.shift();
      initial *= atol(b);
      
      delete [] b;
    }

    sprintf(dest,"%ld", initial);
}

void div(char* dest, LinkedList<char*> &args)
{
    char *a = args.shift();
    long initial = atol(a);

    delete [] a;

    while(args.size() > 0) {
      char *b = args.shift();
      initial /= atol(b);
      
      delete [] b;
    }

    sprintf(dest,"%ld", initial);
}

void sub(char* dest, LinkedList<char*> &args)
{
    char *a = args.shift();
    long initial = atol(a);

    delete [] a;

    while(args.size() > 0) {
      char *b = args.shift();
      initial -= atol(b);
      
      delete [] b;
    }

    sprintf(dest,"%ld", initial);
}

void read(char* dest, LinkedList<char*> &args)
{
    E93c e(512, 9, 8);
    e.setup();

    char *a = args.shift();
    int address = atoi(a);
    
    delete [] a;

    sprintf(dest, "%02x", e.read(address));
}

void hex2num(char* dest, LinkedList<char*> &args)
{
    char *a = args.shift();
    long value = strtol(a, NULL, 16);

    delete [] a;
    
    sprintf(dest, "%ld", value);
}

void write(char* dest, LinkedList<char*> &args)
{
    E93c e(512, 9, 8);
    e.setup();

    char *a = args.shift();
    char *b = args.shift();

    int address = atoi(a);
    int value = atoi(b);

    e.write(address, value);

    delay(10);

    delete [] a;
    delete [] b;

    sprintf(dest, "%02x", e.read(address));
}

void position(char* dest, LinkedList<char*> &args)
{
  char *a = args.shift();
  char *b = args.shift();
  
  int position = atoi(a);
  
  dest[0] = b[position];
  dest[1] = '\0';

  delete [] a;
  delete [] b;
}

void merge(char* dest, LinkedList<char*> &args)
{
  char *a = args.shift();
  strcpy(dest, a);

  delete [] a;

  while(args.size() != 0) 
  {
    char *b = args.shift();
    strcat(dest, b);

    delete [] b;
  }
}

void first(char* dest, LinkedList<char*> &args)
{
  char *a = args.shift();

  dest[0] = a[0];
  dest[1] = '\0';

  delete [] a;
}

void last(char* dest, LinkedList<char*> &args)
{
  char *a = args.shift();

  dest[0] = a[strlen(a)-1];
  dest[1] = '\0';

  delete [] a;
}

void format(char* dest, LinkedList<char*> &args)
{
    char *a = args.shift();
    char *b = args.shift();
    b[0] = '%';

    long initial = atol(a);
    sprintf(dest, b, initial);

    delete [] a;
    delete [] b;
}

#endif