#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "list.h"

#include "arch/e.h"

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
    Token (*proc)(List<Token> &, E &);

    List<Token> list = List<Token>();
    Token(TokenType type = TSymbol) : type(type) {}
    Token(TokenType type, char *value) : type(type), value(value) {}
    Token(TokenType type, Token (*proc)(List<Token> &proc, E &e)) : type(type), proc(proc) {}
};

class Parser
{
public:
    Parser();
    static char* run(E &e, char *s);

private:

    static bool isdig(char c);
    static Token atom(char *token);
    static Token eval(Token token, E &e);
    static List<char *> tokenize(char *s);
    static Token parse(List<char *> &tokens);
};

#endif
