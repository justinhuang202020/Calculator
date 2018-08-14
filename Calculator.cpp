#include <iostream>
 
using namespace std;
#include "BinaryTree.h"
#include "ExpressionParser.h"
#include <vector>
using std::vector;
#include "Calculator.h"
double  Calculator::evaluate(string expression) {
	try {
	BinaryTree bt;
	std::vector<string> v = ExpressionParser::postfix(expression);
	bt.insertPostfix(v);
	return bt.evaluateExpressionTree();
	}
	catch(const char* msg) {
		throw msg;
	}


}