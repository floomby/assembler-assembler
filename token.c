#include "token.h"
#include "config.h"

#include <stdio.h>
#include <string.h>


int append_tok(struct line_t *syn_struct, struct token_t *tok, struct token_purity_t *purity)
{
    if(purity->count == TOK_STACK_SIZE){
        puts("error: token stack full");
        return -1;
    }
    
    memcpy(purity->stack + purity->count, tok, sizeof(struct token_t));
    
    purity->count++;
    
    return 0;
}

void print_tok(struct token_t tok)
{
    switch(tok.type){
        case TOK_TABLE_ENTRY:
            printf("type: table_entry value: %s\n", tok.data.entry->const_token);
            break;
        case TOK_SEPERATOR:
            puts("type: seperator");
            break;
        case TOK_BEGIN_INDIRECTION:
            puts("type: begin indirect");
            break;
        case TOK_END_INDIRECTION:
            puts("type: end indirect");
            break;
        case TOK_OPERATOR:
            printf("type: operator value: %c\n", tok.data.operation);
            break;
        default:
            puts("don't know how to print that type of token yet");
            break;
    }
}

void print_tok_stack(struct token_purity_t *purity)
{
    for(int i = 0; i < purity->count; i++){
        printf("%d: ", i);
        print_tok(purity->stack[i]);
    }    
}
