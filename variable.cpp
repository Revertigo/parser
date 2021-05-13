//
// Created by dekel on 5/12/21.
//

#include "variable.hpp"
#include "strings.h"

using namespace std;

//Non-terminal
void Variable::printSymbol() const {
    cout << tokenStrings[symbol] << " ";
}

