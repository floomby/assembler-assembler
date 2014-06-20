#include "lexer.h"
#include "token.h"
#include "fsm_helper.h"
#include "fsm_consts.h"

#include <stdio.h>
#include <stdlib.h>

#include "pick_token.h"

int tok_bracket(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity);
int tok_string(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity);
int tok_number(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity);
int tok_operator(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity);

int tok_line(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity)
{
    while(**itr && (**itr != '\n')){
        if(**itr == ','){
            append_tok(syn_struct, &tok_seperator, &purity->tok_purity);
            (*itr)++;
        }else if(   in_set(**itr, FSM_WHITESPACE_SET)){
            skip_whitespace(itr);
        }else if(   in_set(**itr, FSM_NUMBER_SET)){
            if(tok_number(itr, syn_struct, purity)) return -1;
        }else if(   in_set(**itr, FSM_OPEN_BRACKET_SET)){
            purity->waiting_for = matches[**itr];
            if(tok_bracket(itr, syn_struct, purity)) return -1;
        }else if(   in_set(**itr, FSM_QUOTE_SET)){
            purity->waiting_for = matches[**itr];
            if(tok_string(itr, syn_struct, purity)) return -1;
        }else{
            if(pick_token(itr, syn_struct, purity)) return -1;
        }
    }
    return 0;
}


int tok_bracket(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity)
{
    if(purity->waiting_for != ']'){
        puts("only [] are used right now");
        return -1;
    }
    
    if(append_tok(syn_struct, &tok_begin_indirection, &purity->tok_purity)) return -1;
    (*itr)++;

    while(**itr != purity->waiting_for){
        if(!**itr || **itr == '\n'){
            printf("missing %c\n", purity->waiting_for);
            return -1;
        }
        
        if(in_set(**itr, FSM_WHITESPACE_SET)){
            skip_whitespace(itr);
        }else if(in_set(**itr, FSM_NUMBER_SET)){
            if(tok_number(itr, syn_struct, purity)) return -1;
        }else if(in_set(**itr, FSM_OPERATOR_SET)){
            if(tok_operator(itr, syn_struct, purity)) return -1;
        }else{
            if(pick_token(itr, syn_struct, purity)) return -1;
        }
    }
    
    (*itr)++;
    return append_tok(syn_struct, &tok_end_indirection, &purity->tok_purity);
}


int tok_string(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity)
{
    puts("string");
    return -1;
}

int tok_number(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity)
{
    puts("number");
    return -1;
}

int tok_operator(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity)
{
    struct token_t tmp;
    tmp.type = TOK_OPERATOR;
    tmp.data.operation = **itr;
    
    (*itr)++;    
    return append_tok(syn_struct, &tmp, &purity->tok_purity);
}
