#include "parser.h"
#include "env.h"

E *Parser::e;

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

void Parser::parse(char *dest, LinkedList<char *> &tk)
{
  tk.shift();

  char op = *tk.shift();

  switch (op)
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
  case 'r':
    read(dest, tk);
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
}

void Parser::run(char *dest, char *s)
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

    char r[8];
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