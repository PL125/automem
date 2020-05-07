#include "query.h"


Query::Query(E *e, char *script) {
    this->e = e;
    this->script = script;
};

char* Query::run() {
    return Parser::run(*e, script);
};