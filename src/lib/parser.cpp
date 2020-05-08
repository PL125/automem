#include "parser.h"

const Token nil(TSymbol, "nil");

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

void merge(char* dest, LinkedList<char*> &args)
{
  strcpy(dest, args.shift());
  while(args.size() != 0) strcat(dest, args.shift());
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

E* Parser::e;

LinkedList<char *> Parser::tokenize(char *s)
{
  LinkedList<char *> ss;

  while (*s)
  {
    while (*s == ' ')
      ++s;
    if (*s == '(' || *s == ')')
    {
      ss.add(new char(*s++ == '(' ? '(' : ')'));
    }
    else
    {
      char *t = s;
      while (*t && *t != ' ' && *t != '(' && *t != ')')
        ++t;
      char *r = new char[t - s + 1];
      memcpy(r, s, t - s);
      r[t - s] = '\0';

      ss.add(r);
      s = t;
    }
  }

  return ss;
}

Token Parser::atom(char *token)
{
  Token t;
  if (isdig(token[0]) || (token[0] == '-' && isdig(token[1])))
  {
    return Token(TNumber, token);
  }

  return Token(TSymbol, token);
}

void Parser::run(char* dest, char *s)
{
  //(+ 1 (+ 2 1))
  while(strrchr(s, '(') != nullptr && strchr(s, ')') != nullptr)
  {
    int sz = strlen(s);
    int bb = (int)(strrchr(s, '(') - s);

    char b[bb+1];
    memcpy(b, s, bb);
    b[bb] = '\0';

    char t[sz-bb+1];
    memcpy(t, &s[bb], sz-bb);
    t[sz-bb] = '\0';

    int ee = (int)(strchr(t, ')') - t);

    char e[ee+2];
    memcpy(e, t, ee+1);
    e[ee+1] = '\0';

    LinkedList<char *> tk = tokenize(e);
    tk.shift();
    char op = *tk.shift();

    char r[8];  
    switch(op) 
    {
      case '+':
        add(r, tk);
        break;
      case '-':
        sub(r, tk);
        break;
      case '*':
        mult(r, tk);
        break;
      case 'r':
        read(r, tk);
        break;
      case 'm':
        merge(r, tk);
        break;
      case 'f':
        first(r, tk);
        break;
      case 'l':
        last(r, tk);
        break;
    }

    int rsz = strlen(r);

    char q[sz-ee+2];
    memcpy(q, &t[ee+1], sz-ee+1);
    q[sz-ee+1] = '\0';

    char rr[bb+rsz+sz-ee+2];
    strcpy(rr, b);
    strcat(rr, r);
    strcat(rr, q);

    s = rr;
  }

  int sz = strlen(s);

  memcpy(dest, s, sz+1);
  dest[sz+1] = '\0';
}