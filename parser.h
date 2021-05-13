#include "symbol.h"
#include "variable.hpp"
#include "word.hpp"

using namespace std;
class Parser {
	ifstream& inputFile;
	vector<vector<shared_ptr<Symbol>>> rules {
            { make_shared<Variable>(Variable(E_, NONTERM)), make_shared<Variable>(Variable(T, NONTERM)) },
            { make_shared<Variable>(Variable(E_, NONTERM)), make_shared<Variable>(Variable(T, NONTERM)), make_shared<Word>(Word(PLUS, TERM)) },
            { make_shared<Word>(Word(EPSILON, TERM)) },
            { make_shared<Variable>(Variable(T_, NONTERM)), make_shared<Variable>(Variable(F, NONTERM)) },
            { make_shared<Variable>(Variable(T_, NONTERM)), make_shared<Variable>(Variable(F, NONTERM)),make_shared<Word>(Word(ASTERISK, TERM)) },
            { make_shared<Word>(Word(EPSILON, TERM))},
            { make_shared<Word>(Word(RPAREN, TERM)), make_shared<Variable>(Variable(E, NONTERM)), make_shared<Word>(Word(LPAREN, TERM)) },
            { make_shared<Word>(Word(ID, TERM)) }
    };

	vector<vector<int>> table {
		{ 0, -1, -1, 0, -1, -1 },
		{ -1, 1, -1, -1, 2, 2 },
		{ 3, -1, -1, 3, -1, -1 },
		{ -1, 5, 4, -1, 5, 5 },
		{ 7, -1, -1, 6, -1, -1 }
	};
	vector<shared_ptr<Symbol>> stack;
	vector<shared_ptr<Symbol>> accepted;
	
public:
	Parser(ifstream& file) : inputFile(file) {}
	void parse();
	terminal nextToken ();
	void printLM();
};
