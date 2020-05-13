#include "parser.h"

#include "arch/e95.h"

E *pMem;

Parser::Parser() {}

void Parser::setE(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();
  int id = atoi(a);

  delete[] a;

  switch (id)
  {
  case 1:

    char *b = args.shift();
    char *c = args.shift();
    char *d = args.shift();

    int sz = atoi(b);
    int addrsz = atoi(c);
    int pgsz = atoi(d);

    delete[] b;
    delete[] c;
    delete[] d;

    // if (e)
    // {
    //   delete e;
    // }
    pMem = new E95c(4096);
    pMem->setup();
    pMem->print();
    break;

  case 2:
    break;

  case 3:
    break;
  }

  // pMem->setup();
  // pMem->print();
}

void Parser::add(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();
  long initial = atol(a);

  delete[] a;

  while (args.size() > 0)
  {
    char *b = args.shift();
    initial += atol(b);

    delete[] b;
  }

  sprintf(dest, "%ld", initial);
}

void Parser::mult(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();
  long initial = atol(a);

  delete[] a;

  while (args.size() > 0)
  {
    char *b = args.shift();
    initial *= atol(b);

    delete[] b;
  }

  sprintf(dest, "%ld", initial);
}

void Parser::div(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();
  long initial = atol(a);

  delete[] a;

  while (args.size() > 0)
  {
    char *b = args.shift();
    initial /= atol(b);

    delete[] b;
  }

  sprintf(dest, "%ld", initial);
}

void Parser::debug(char *dest, LinkedList<char *> &args)
{
  pMem->print();
}

void Parser::sub(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();
  long initial = atol(a);

  delete[] a;

  while (args.size() > 0)
  {
    char *b = args.shift();
    initial -= atol(b);

    delete[] b;
  }

  sprintf(dest, "%ld", initial);
}

void Parser::read(char *dest, LinkedList<char *> &args)
{
  if (pMem == nullptr)
  {
    Serial.println("Error");
    return;
  }

  char *a = args.shift();
  int address = atoi(a);

  delete[] a;

  sprintf(dest, "%02x", pMem->read(address));
}

void Parser::hex2num(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();
  long value = strtol(a, NULL, 16);

  delete[] a;

  sprintf(dest, "%ld", value);
}

void Parser::write(char *dest, LinkedList<char *> &args)
{
  if (pMem == nullptr)
  {
    Serial.println("Error");
    return;
  }

  char *a = args.shift();
  char *b = args.shift();

  int address = atoi(a);
  int value = atoi(b);

  pMem->write(address, value);

  delay(10);

  delete[] a;
  delete[] b;

  sprintf(dest, "%02x", pMem->read(address));
}

void Parser::dump(char *dest, LinkedList<char *> &args)
{
  pMem->dump();
}

void Parser::position(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();
  char *b = args.shift();

  int position = atoi(a);

  dest[0] = b[position];
  dest[1] = '\0';

  delete[] a;
  delete[] b;
}

void Parser::merge(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();
  strcpy(dest, a);

  delete[] a;

  while (args.size() != 0)
  {
    char *b = args.shift();
    strcat(dest, b);

    delete[] b;
  }
}

void Parser::first(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();

  dest[0] = a[0];
  dest[1] = '\0';

  delete[] a;
}

void Parser::last(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();

  dest[0] = a[strlen(a) - 1];
  dest[1] = '\0';

  delete[] a;
}

void Parser::format(char *dest, LinkedList<char *> &args)
{
  char *a = args.shift();
  char *b = args.shift();
  b[0] = '%';

  long initial = atol(a);
  sprintf(dest, b, initial);

  delete[] a;
  delete[] b;
}

LinkedList<char *> Parser::tokenize(char *s)
{
  LinkedList<char *> ss;

  while (*s)
  {
    while (*s == ' ')
      ++s;
    if (*s == '(' || *s == ')')
    {
      s++;
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

void Parser::parse(char *dest, LinkedList<char *> &tk)
{
  char *op = tk.shift();

  switch (*op)
  {
  case '+':
    add(dest, tk);
    break;
  case '-':
    sub(dest, tk);
    break;
  case '*':
    mult(dest, tk);
    break;
  case '/':
    div(dest, tk);
    break;
  case '@':
    debug(dest, tk);
    break;
  case 'r':
    read(dest, tk);
    break;
  case 'e':
    setE(dest, tk);
    break;
  case 'd':
    dump(dest, tk);
    break;
  case 'p':
    position(dest, tk);
    break;
  case 'n':
    hex2num(dest, tk);
    break;
  case 'z':
    format(dest, tk);
    break;
  case 'w':
    write(dest, tk);
    break;
  case 'm':
    merge(dest, tk);
    break;
  case 'f':
    first(dest, tk);
    break;
  case 'l':
    last(dest, tk);
    break;
  }

  delete[] op;
}

void Parser::call(char *dest, char *s)
{
  while (strrchr(s, '(') != nullptr && strchr(s, ')') != nullptr)
  {
    int sz = strlen(s);
    int bb = (int)(strrchr(s, '(') - s);

    char b[bb + 1];
    memcpy(b, s, bb);
    b[bb] = '\0';

    char t[sz - bb + 1];
    memcpy(t, &s[bb], sz - bb);
    t[sz - bb] = '\0';

    int ee = (int)(strchr(t, ')') - t);

    char e[ee + 2];
    memcpy(e, t, ee + 1);
    e[ee + 1] = '\0';

    char r[16];
    LinkedList<char *> tk = tokenize(e);
    parse(r, tk);

    int rsz = strlen(r);

    char q[sz - ee + 2];
    memcpy(q, &t[ee + 1], sz - ee + 1);
    q[sz - ee + 1] = '\0';

    char rr[bb + rsz + sz - ee + 2];
    strcpy(rr, b);
    strcat(rr, r);
    strcat(rr, q);

    s = rr;
  }

  int sz = strlen(s);

  memcpy(dest, s, sz + 1);
  dest[sz + 1] = '\0';
}