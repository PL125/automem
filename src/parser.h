#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>

enum State { Operation, Value };

class Parser {
    private:
        char *current;
        State state;

    public:
        Parser();
        char *execute(char *input);
        
};

#endif