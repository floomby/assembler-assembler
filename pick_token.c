#include "pick_token.h"
#include "fsm_helper.h"
#include "tables.h"
#include "token.h"

#include <stdio.h>



int pick_token(const char **itr, struct line_t *syn_struct, struct lexer_purity_t *purity)
{
    unsigned idx = 0;
    unsigned cnt = 0;
    
    while(**itr && (!in_set(**itr, FSM_WORDBOUND_SET))){
        while(**itr > token_tables[purity->tok_purity.curr_table].entries[idx].const_token[cnt]){
            idx++;
            if(idx == token_tables[purity->tok_purity.curr_table].table_length){
                puts("token not found in table");
                return -1;
            }
        }
        
        if(**itr != token_tables[purity->tok_purity.curr_table].entries[idx].const_token[cnt]){
            puts("token not found in table");
            return -1;
        }
        
        cnt++;
        (*itr)++;
    }
    
    /*
    printf("token found: ");
    for(int i = 0; i < cnt; i++)
        printf("%c", *(*itr - cnt + i));
    puts("");
    */
    
    struct token_t tmp;
    tmp.type = TOK_TABLE_ENTRY;
    tmp.data.entry = token_tables[purity->tok_purity.curr_table].entries + idx;
    
    purity->tok_purity.curr_table = token_tables[purity->tok_purity.curr_table].entries[idx].next_table;
    
    return append_tok(syn_struct, &tmp, &purity->tok_purity);
}
