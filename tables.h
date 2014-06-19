/*
 * This is the file that the
 * assembler-assembler fills out
 *
 * For right now I just want to get
 * the plain old assembler functioning
 */

#ifndef TABLES_H_INCLUDED
#define TABLES_H_INCLUDED

#include "table.h"


const struct table_entry_t token_table_entries[] = {
{"blah", 1, "1"},
{"cow",  1, "2"},
{"moo",  1, "3"}
};

struct table_t token_table = { 3, token_table_entries };





#endif//TABLES_H_INCLUDED
