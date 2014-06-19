#include "tmain.h"
#include "lexer.h"
#include "isa.h"
#include "config.h"
#include "assemble.h"

#include <stdio.h>

int tmain(const char *input, uint8_t **outbuf)
{
    uint8_t asm_buf[ISA_MAX_INSTR_LEN];
    
    struct line_t line_toks;
    struct lexer_purity_t purity;
    
    struct token_t token_stack[TOK_STACK_SIZE];
    purity.tok_purity.stack = token_stack;
    
    // TODO: better ending case
    while(*input){
        purity.tok_purity.count = 0;
        if(tok_line(&input, &line_toks, &purity)){
            puts("an error occured while parsing");
            return -1;
        }
        print_tok_stack(&purity.tok_purity);
        assemble(&purity.tok_purity);
    }
        
    return 0;
}
