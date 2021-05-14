//
// Created by dekel on 5/12/21.
//
#include <iostream>
#include "word.hpp"
#include "strings.h"

using namespace std;

void Word::printSymbol() const {
    //Since EPSILON is nothing
    if(symbol != EPSILON) {
        cout << terminalStrings[symbol] << " ";
    }
}
