#ifndef PICK_TOKEN_H_INCLUDED
#define PICK_TOKEN_H_INCLUDED

#include "lexer.h"

int pick_token(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity);


#endif//PICK_TOKEN_H_INCLUDED
