#include <iostream>
 
using namespace std;
#include "BinaryTree.h"
#ifndef CALCULATOR_H
#define CALCULATOR_H
/**
Class that spits back an answer for a valid arithmitic expression. 
**/
class Calculator {
	public:
		static double evaluate(string expression);
  
};
#endif