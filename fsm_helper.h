#ifndef FSM_HELPER_H_INCLUDED
#define FSM_HELPER_H_INCLUDED

#define FSM_WHITESPACE_SET      " \t"
#define FSM_NUMBER_SET          "0123456789"
#define FSM_OPEN_BRACKET_SET    "{(<["
#define FSM_CLOSE_BRACKET_SET   "})>]"
#define FSM_QUOTE_SET           "'\""
#define FSM_OPERATOR_SET        "-+*"
#define FSM_SEPERATOR_SET       ","

#define FSM_WORDBOUND_SET       (FSM_WHITESPACE_SET FSM_OPEN_BRACKET_SET FSM_CLOSE_BRACKET_SET FSM_QUOTE_SET FSM_OPERATOR_SET FSM_SEPERATOR_SET "\n")

int in_set(char c, const char *set);

void skip_whitespace(const char **itr);

#endif//FSM_HELPER_H_INCLUDED
