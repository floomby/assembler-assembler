assembler-assembler
===================

A tool to build speedy assemblers based on a ISA spec sheet


TODO
----

In this order

 * Finish the lexer and parser (strings, numbers, address brackets, size modifiers, and commas)
 * It can't handle size modifiers (eg. DWORD, short, etc)
 * The abstract syntax tokens only have one type right now (due to the unfinished lexer/parser)
 * Change the tables so that pick_token uses correct tables for each thing (prefixes vs opcodes vs registers)
 * Create the table generator in ruby
 * Make erb templates for the other stuff (ISA and config)
 * Finish the assemble portion (this sound realy huge, but I think have the tables set up well will make this easy)
 * Do the output buffer things
 * Make a nice little command line utility with it 

