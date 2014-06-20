#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "token.h"

#define PAR_PREFIX  1
#define PAR_OPCODE  2
#define PAR_OPERAND 3

struct item_t
    unsigned type;
    union  {

    } what;
};

int parse(struct token_purity_t *purity);


#endif//PARSER_H_INCLUDED
