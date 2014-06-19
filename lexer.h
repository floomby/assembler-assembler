#ifndef LEXER_H_INCLUDED
#define LEXER_H_INCLUDED

#include "token.h"

struct lexer_purity_t {
    char waiting_for;
    struct token_purity_t tok_purity;
};

int tok_line(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity);

#endif//LEXER_H_INCLUDED
