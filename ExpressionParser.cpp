#include <iostream>
 
using namespace std;
#include <vector>
using std::vector;
#include <sstream>
#include <stdlib.h>   
#include <ctype.h> 
#include <stdio.h>
#include <stack>
#include "ExpressionParser.h"
bool ExpressionParser::isValid(string expression) {
	char[] = {'+', '-', ''}
	if () {

	}
}
std::vector<string> ExpressionParser::postfix(string expression) {

 
	vector<string> split = delim(expression);
	return reversePolish(split);
}
std::vector<string> ExpressionParser::delim(string expression) {
	string [] = {"+", "-", "*", "/"};
    std::vector<std::string> parts;

    int currPos = 0;
	for(int i = 0; i<expression.length(); i++) {
		currPos = i;
	bool loop = false;
	bool decimal = false;
    while(isdigit(expression[i]) || (expression[i] == '.' && !decimal)) {
    	loop = true;
    	if (expression[i] == '.') {
    		decimal = true;
    	}
    	i++;
    }
    if (loop) {
    	i--;
    }
    if (expression.substr(currPos, i-currPos+1) !) {

    }
    parts.push_back(expression.substr(currPos, i-currPos+1));
    
}
	  return parts;

}
std::vector<string> ExpressionParser::reversePolish(vector<string> delim) {
		vector<string> rp;
	if (delim.size() == 0) {
		return rp;
	}
	stack <string> stck;
	for (string c : delim) {
		
		if (isNumber(c)) {
			rp.push_back(c);
		}
		else if (c=="(") {
        	stck.push(c);
      }
       else if (c==")") {
        while (stck.top()!="(") {
          rp.push_back(stck.top());
          stck.pop();
        	}
        	stck.pop();
        }
     	else {
        	while (!stck.empty() && getPriority(stck.top()) >= getPriority(c)) {
          		rp.push_back(stck.top());
          		stck.pop();
        		}
        	stck.push(c);
      }
	}
	while (!stck.empty()) {
      rp.push_back(stck.top());
      stck.pop();
    }
	return rp;
}
int ExpressionParser::getPriority(string c) {
	 if (c=="(") {
      return 0;
    } 
    else if (c=="+" || c=="-") {
      return 1;
    }
     else {
      return 2;
    }
}
bool ExpressionParser::isNumber(string c) {
	bool decimal;
	for (int i = 0; i<c.length(); i++) {
		if(isdigit(c[i]) || (c[i] == '.' && !decimal)) {
    		// loop = true;
    		if (c[i] == '.') {
    			decimal = true;
    		}
    	}
    	else {
    		return false;
    	}
    }
    return true;
}
// int main() {
// 	std::vector<string> v = ExpressionParser::postfix("2*6-(23+7)/(1+2)");
// 	for ( string c : v ) std::cout << c<<"\n";
// 	return 0;
// }
