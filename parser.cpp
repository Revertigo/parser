//
// Created by dekel on 5/12/21.
//

#include <string>
#include "strings.h"
#include "parser.h"

void Parser::parse(){
    //Always insert to the bottom of the stack $
    stack.push_back(make_shared<Word>(Word(END, TERM)));
    //Parsing is always starting from the first rule production i.e. non-terminal E. It will be above the $
    stack.push_back(make_shared<Variable>(Variable(E, NONTERM)));

    shared_ptr<Symbol> x = stack[stack.size()-1]; //Top of the stack
    terminal a = nextToken();
    printLM();
    while(stack.size() > 1){
        if(x->getType() == TERM && x->getSymbol() == a){
            stack.pop_back();
            a = nextToken();
            //Add the new parsed token to the accepted list
            accepted.push_back(x);
        }
        else if(x->getSymbol() == EPSILON){
            stack.pop_back();
            x = stack[stack.size()-1];
            continue;
        }
        else if(x->getType() == TERM || table[x->getSymbol()][a] == -1){
            cout << "syntax error" << endl;
            return;
        }
        else{
            stack.pop_back();
            int rule = table[x->getSymbol()][a];
            for (auto symbol = rules[rule].begin(); symbol != rules[rule].end(); ++symbol) {
                stack.push_back(*symbol);
            }
        }

        printLM();
        x = stack[stack.size()-1];
    }
}

terminal Parser::nextToken (){
    string token;
    //Read next word into token, if any left
    if(inputFile >> token) {
        return str_to_terminal.at(token);
    }
    else{
        return END;
    }
}

void Parser::printLM(){
    //First print accepted, then | and then the stack (without $)
    for (auto symbol = accepted.begin(); symbol != accepted.end(); ++symbol) {
        (*symbol)->printSymbol();
    }

    cout << "| ";

    for (auto symbol = stack.rbegin(); symbol != stack.rend()-1; ++symbol) {
        (*symbol)->printSymbol();
    }

    cout << endl;
}
