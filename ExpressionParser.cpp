#include <iostream>
 
using namespace std;
#include <vector>
using std::vector;
#include <algorithm> 
#include <sstream>
#include <stdlib.h>   
#include <ctype.h> 
#include <stdio.h>
#include <stack>
#include <stdexcept>
#include "ExpressionParser.h"
/**
static functoin that takes an expression and converts it to a postfix expression
**/
std::vector<string> ExpressionParser::postfix(string expression) {

 try {
	vector<string> split = delim(expression);
	return reversePolish(split);
	} catch (const char* msg) {
		throw msg;
	}
}
/**
Splits each part of the string into separtes tokens and put into a vector.
This also throws an error if the expression doesn't conform to aritihmitic parterns
**/
std::vector<string> ExpressionParser::delim(string expression) {
	// if previous token is false
	bool prevIsNum = false;
	string validOperators[] = {"+", "-", "*", "/"};
    std::vector<std::string> parts;
    std::vector<int> labels;
    labels.assign(expression.length(), 0);
    int currPos = 0;
	for(int i = 0; i<expression.length(); i++) {
		currPos = i;
		//if it goes through a while loop, aka is a number
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
    	// limits the amount of digits a number can contain.
    	if (expression.substr(currPos, i-currPos+1).length() >17 && decimal) {
    		throw "One of the numbers has too many digits";
    	}
    	// if number doesn't cotain a decimal
    	else if (expression.substr(currPos, i-currPos+1).length() >16) {
    		throw "One of the numbers has too many digits"; 
    	}
    	i--;
    }
  	// if  token is not a number
     if(!isNumber(expression.substr(currPos, i-currPos+1))) {
     	//check if it's an operator
		string* check = std::find(std::begin(validOperators), std::end(validOperators), expression.substr(currPos, i-currPos+1));
		if (check == std::end(validOperators)) {

				if (expression.substr(currPos, i-currPos+1) == "(") {
					// if prevous token is a number or this is not the first token
					if (prevIsNum && i!=0) {
							throw "Invalid expression. Please check if inputs are valid";	
					}
					//check for a matching end parenthesis 
					for (int j = i; j<expression.length(); j++) {
						if (expression.substr(j, 1) == ")") {
							//label this end parenthesis as visited
							if (labels.at(j) ==0) {
								labels.at(j) = 1;
								break;
							}
							
							
						}
						// if no end parenthesis are found
						else if(j+1==expression.length()) {
							throw "Invalid expression. Please check if inputs are valid";
						}
					}
				}
				// checks if end paranethesis has been properly visited and in the correct position
			else if (expression.substr(currPos, i-currPos+1) == ")") {
    			if (labels.at(i) != 1 || !prevIsNum) {
    				throw "Invalid expression. Please check if inputs are valid";
    			}
    		}
    		else {
    			throw "Invalid expression. Please check if inputs are valid";
    		}
		}
		// if operator is found
		else {

			// previous token cannot be not a number
			if (!prevIsNum) {
					throw "Invalid expression. Please check if inputs are valid";
				
			}
			//operator cannot be at end of expression
			if (currPos+1 == expression.length()) {
				throw "Invalid expression. Please check if inputs are valid";
			}
			prevIsNum = false;
		}
	} 
	else {
		prevIsNum = true;
	}
    parts.push_back(expression.substr(currPos, i-currPos+1));
    
}
	  return parts;

}
/**
coverts a vector of tokens to postfix notation using the revereposlih algorithm
**/
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
	if (c.substr(c.length()-1,1) == ".") {
		return false;
	}
	bool decimal;
	for (int i = 0; i<c.length(); i++) {
		if(isdigit(c[i]) || (c[i] == '.' && !decimal)) {
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