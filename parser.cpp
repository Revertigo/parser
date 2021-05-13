//
// Created by dekel on 5/12/21.
//
#include <sstream>
#include <string>

#include "strings.h"
#include "parser.h"

void Parser::parse(){
    string line;
    getline(inputFile, line);
    istringstream iss(line);
//Parsing is always starting from the non-terminal E
    stack.push_back(make_shared<Word>(Word(END, TERM)));//Always insert to the end of the stack $
    stack.push_back(make_shared<Variable>(Variable(E, NONTERM)));

    shared_ptr<Symbol> x = stack[stack.size()-1]; //Top of the stack
    string a;
    iss >> a;
    while(stack.size() > 1){
        if(terminalStrings[x->getSymbol()] == a){

        }
    }
}

terminal Parser::nextToken (){

}

void Parser::printLM(){

}
