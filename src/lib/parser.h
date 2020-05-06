// #ifndef PARSER_H
// #define PARSER_H

// #include "list.h"

// enum TokenType
// {
//     TSymbol,
//     TNumber,
//     TList,
//     TProc
// };

// struct Token
// {
//     TokenType type;
//     char *value;
//     Token (*proc)(List<Token> &);

//     List<Token> list = List<Token>();
//     Token(TokenType type = TSymbol) : type(type) {}
//     Token(TokenType type, char *value) : type(type), value(value) {}
//     Token(TokenType type, Token (*proc)(List<Token> &proc)) : type(type), proc(proc) {}
// };

// const Token nil(TSymbol, "nil");

// class Parser
// {
// public:
//     Parser();
//     Token eval(Token token);

// private:
//     bool isdig(char c);
//     List<char *> tokenize(char *s);
//     Token atom(char *token);
//     Token read_from_tokens(List<char *> &tokens);
// }

// // Parser::isdig(char c) {
    
// // }

// #endif
