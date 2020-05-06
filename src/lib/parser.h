#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "list.h"

enum TokenType
{
    TSymbol,
    TNumber,
    TList,
    TProc
};

struct Token
{
    TokenType type;
    char *value;
    Token (*proc)(List<Token> &);

    List<Token> list = List<Token>();
    Token(TokenType type = TSymbol) : type(type) {}
    Token(TokenType type, char *value) : type(type), value(value) {}
    Token(TokenType type, Token (*proc)(List<Token> &proc)) : type(type), proc(proc) {}
};

const Token nil(TSymbol, "nil");

Token add(List<Token> &args)
{
    long initial = atol(args.pop_front().value);
    for(int i=0; i<args.length(); i++) {
      initial += atol(args.get(i).value);
    }
    
    char buf[8];
    sprintf(buf,"%d", initial);
  
    return Token(TNumber, buf);
}

Token mult(List<Token> &args)
{
    long initial = atol(args.pop_front().value);
    for(int i=0; i<args.length(); i++) {
      initial *= atol(args.get(i).value);
    }
    
    char buf[8];
    sprintf(buf,"%d", initial);

    return Token(TNumber, buf);
}

Token sub(List<Token> &args)
{
    long initial = atol(args.pop_front().value);
    for(int i=0; i<args.length(); i++) {
      initial -= atol(args.get(i).value);
    }
    
    char buf[8];
    sprintf(buf,"%d", initial);

    return Token(TNumber, buf);
}

class Parser
{
public:
    Parser();
    static char* run(char *s);

private:
    static bool isdig(char c);
    static Token atom(char *token);
    static Token eval(Token token);
    static List<char *> tokenize(char *s);
    static Token read_from_tokens(List<char *> &tokens);
};

bool Parser::isdig(char c) { return isdigit(static_cast<unsigned char>(c)) != 0; }

List<char *> Parser::tokenize(char *s)
{
  List<char *> ss = List<char *>();

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

Token Parser::read_from_tokens(List<char *> &tokens)
{
  char *token = tokens.pop_front();
  if (*token == '(')
  {
    Token t(TList);
    while (*tokens.get(0) != ')')
    {
      t.list.add(read_from_tokens(tokens));
    }
    tokens.pop_front();
    return t;
  }
  else
  {
    return atom(token);
  }
}

Token Parser::eval(Token token)
{
  if(token.type == TSymbol) 
  {
    if(!strcmp(token.value, "+")) return Token(TProc, &add);
    if(!strcmp(token.value, "-")) return Token(TProc, &sub);
    if(!strcmp(token.value, "*")) return Token(TProc, &mult);
    
  } 
  
  if(token.type == TNumber) 
  {
    return token;
  }

  if(token.list.length() == 0)
  {
    //
  }

  if(token.list.get(0).type == TSymbol) {
    //
  }


  Token proc = eval(token.list.pop_front());
  
  List<Token> args = List<Token>();
  for(int j=0; j<token.list.length(); j++) {
    eval(token.list.get(j));
    args.add(eval(token.list.get(j)));
  }
  
  if(proc.type == TProc)
  {
    return proc.proc(args);
  }
}

char* Parser::run(char* s)
{
  List<char *> t = Parser::tokenize(s);
  Token x = Parser::read_from_tokens(t);
  
  return Parser::eval(x).value;
}

#endif
