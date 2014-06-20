#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <stdint.h>

struct table_entry_t {
    const char *const_token;
    const uint8_t what_length;
    const uint8_t *what;
    const uint8_t next_table;
};


// tokens must be in lexical order
struct table_t {
    unsigned table_length;
    const struct table_entry_t *entries;
};


#endif//TABLES_H_INCLUDED
