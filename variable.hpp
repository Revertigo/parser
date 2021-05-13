//
// Created by dekel on 5/12/21.
//

#ifndef PARSER_VARIABLE_HPP
#define PARSER_VARIABLE_HPP

#include "symbol.h"

//Non-terminal
class Variable : public Symbol {
public:
    void printSymbol() const override;
    //Inherit ctor
    using Symbol::Symbol;
};

#endif //PARSER_VARIABLE_HPP
