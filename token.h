#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

#include <stdlib.h>
#include <stdint.h>

#include "table.h"

#define TOK_TABLE_ENTRY         1
#define TOK_BEGIN_INDIRECTION   2
#define TOK_END_INDIRECTION     3
#define TOK_SEPERATOR           4
#define TOK_OPERATOR            5

struct token_t {
    unsigned type;
    union {
        const struct table_entry_t *entry;
        char operation;
    } data;
};

static struct token_t tok_begin_indirection = { TOK_BEGIN_INDIRECTION, NULL };
static struct token_t tok_end_indirection = { TOK_END_INDIRECTION, NULL };
static struct token_t tok_seperator = { TOK_SEPERATOR, NULL };

struct line_t {
    unsigned tok_count;
    struct token_t *toks;
};

struct token_purity_t {
    struct token_t *stack;
    unsigned count;
    uint8_t curr_table;
};

int append_tok(struct line_t *syn_struct, struct token_t *tok, struct token_purity_t *purity);

void print_tok(struct token_t tok);
void print_tok_stack(struct token_purity_t *purity);

#endif//TOKEN_H_INCLUDED
