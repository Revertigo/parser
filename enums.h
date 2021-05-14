#ifndef PARSER_ENUMS_HPP
#define PARSER_ENUMS_HPP

enum terminal { ID, PLUS, ASTERISK, LPAREN, RPAREN, END, EPSILON };
enum nonTerminal { E, E_, T, T_, F, ERROR };
enum Type { TERM, NONTERM };

#endif //PARSER_ENUMS_HPP
