#include <iostream>
 
using namespace std;
#include "BinaryTree.h"
#include "ExpressionParser.h"
#include <vector>
using std::vector;
#include "Calculator.h"
float Calculator::evaluate(string expression) {
	if (ExpressionParser::isValid(expression)) {
		throw "Invalid expression. Please check if inputs are valid\n";
	}
	BinaryTree bt;
	std::vector<string> v = ExpressionParser::postfix(expression);
	bt.insertPostfix(v);
	return bt.evaluateExpressionTree();

}