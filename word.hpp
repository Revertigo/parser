//
// Created by dekel on 5/12/21.
//

#ifndef PARSER_WORD_HPP
#define PARSER_WORD_HPP

#include "symbol.h"

//Terminal
class Word : public Symbol{
public:
    void printSymbol() const override;
    //Inherit ctor
    using Symbol::Symbol;
};

#endif //PARSER_WORD_HPP
