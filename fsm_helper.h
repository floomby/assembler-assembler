#ifndef FSM_HELPER_H_INCLUDED
#define FSM_HELPER_H_INCLUDED

#define FSM_WHITESPACE_SET   " \t"
#define FSM_NUMBER_SET       "-0123456789"
#define FSM_OPEN_BRACKET_SET "{(<["
#define FSM_QUOTE_SET        "'\""

int in_set(char c, const char *set);

void skip_whitespace(const char **itr);

#endif//FSM_HELPER_H_INCLUDED
