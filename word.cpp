//
// Created by dekel on 5/12/21.
//

#include "word.hpp"
#include "strings.h"
using namespace std;

void Word::printSymbol() const {
    cout << terminalStrings[symbol] << " ";
}
