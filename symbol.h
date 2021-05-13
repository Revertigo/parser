
#ifndef PARSER_SYMBOL_HPP
#define PARSER_SYMBOL_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "enums.h"
using namespace std;

class Symbol {
protected:
    int symbol;
    Type type; // TERM or NONTERM
public:
    Symbol(int s, Type t) : symbol(s), type(t) {}
    Type getType();
    int getSymbol();
    virtual void printSymbol() const = 0;
};

#endif //PARSER_SYMBOL_HPP