#ifndef PURITY_H_INCLUDED
#define PURITY_H_INCLUDED

struct lexer_purity_t;
struct parser_purity_t;
struct assembler_purity_t;
struct thread_purity_t;

struct purity_t {
    struct lexer_purity_t       *lexer_purity;
    struct parser_purity_t      *parser_purity
    struct assembler_purity_t   *assembler_purity;
    struct thread_purity_t      *thread_purity;
};

#endif//PURITY_H_INCLUDED
