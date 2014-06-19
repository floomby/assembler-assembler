#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include "table.h"

#define TOK_TABLE_ENTRY     1

struct token_t {
    unsigned type;
    union {
        struct table_entry_t *entry;
    } data;
};

struct line_t {
    unsigned tok_count;
    struct token_t *toks;
};

struct token_purity_t {
    struct token_t *stack;
    unsigned count;
};

int append_tok(struct line_t *syn_struct, struct token_t *tok, struct token_purity_t *purity);

void print_tok(struct token_t tok);
void print_tok_stack(struct token_purity_t *purity);

#endif//TOKEN_H_INCLUDED
