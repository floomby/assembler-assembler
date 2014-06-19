#include "pick_token.h"
#include "fsm_helper.h"
#include "tables.h"
#include "token.h"

#include <stdio.h>


int pick_token(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity)
{
    unsigned idx = 0;
    unsigned cnt = 0;
    
    while(**itr && (!in_set(**itr, FSM_WHITESPACE_SET"\n"))){
        while(**itr > token_table.entries[idx].const_token[cnt]){
            idx++;
            if(idx == token_table.table_length){
                puts("token not found");
                return -1;
            }
        }
        
        if(**itr != token_table.entries[idx].const_token[cnt]){
            puts("token not found");
            return -1;
        }
        
        cnt++;
        (*itr)++;
    }
    
    puts("token found");
    
    struct token_t tmp;
    tmp.type = TOK_TABLE_ENTRY;
    tmp.data.entry = token_table.entries + idx;
    
    return append_tok(syn_struct, &tmp, &purity->tok_purity);
}
