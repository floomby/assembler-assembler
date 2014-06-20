#include "fsm_helper.h"

int in_set(char c, const char *set) {
    char *it = (char *)set;
    
    while(*it){
        if(c == *it) return 1;
        it++;
    }
    
    return 0;
}


void skip_whitespace(const char **itr)
{
    while( **itr && in_set(**itr, FSM_WHITESPACE_SET) ){
        (*itr)++;
    }
}

#include <stdio.h>

char unescape(char c)
{
    puts("warning, unescaping not yet implemented");
    
    return c;
}
