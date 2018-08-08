#include <iostream>
 
using namespace std;
#include <vector>
using std::vector;

#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H
class ExpressionParser {
	public:
		static std::vector<string> postfix(string expression);
		static std::vector<string> delim(string expression);
		static std::vector<string> reversePolish(vector<string> delimString);
		static bool isNumber(string c);
  
	private:
		ExpressionParser();
		static int getPriority(string c);
};
#endif
