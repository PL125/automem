#ifndef PARSER_H
#define PARSER_H

#include <Arduino.h>
#include <LinkedList.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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
    Token (*proc)(LinkedList<Token> &, E &);

    LinkedList<Token> list = LinkedList<Token>();
    Token(TokenType type = TSymbol) : type(type) {}
    Token(TokenType type, char *value) : type(type), value(value) {}
    Token(TokenType type, Token (*proc)(LinkedList<Token> &proc, E &e)) : type(type), proc(proc) {}
};

class Parser
{
public:
    Parser();

    static E* e;
    static void run(char *dest, char *s);

private:    
    static bool isdig(char c);
    static Token atom(char *token);
    static Token eval(Token token, E *e);
    static LinkedList<char *> tokenize(char *s);
    static Token parse(LinkedList<char *> &tokens);
};

#endif
