#ifndef QUERY_H
#define QUERY_H

#include "lib/parser.h"

class Query
{
    private:
        E *e;
        char* script;

    public:
        Query(E *e, char* script);
        char *run();
};

#endif