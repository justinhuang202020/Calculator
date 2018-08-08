// Simple C++ program to display "Hello World"
 
// Header file for input output functions
#include<iostream> 
 
using namespace std;

#include <vector>
using std::vector;
#include <sstream>
#include <stdlib.h>    
#include "Calculator.h"
 
// main function -
// where the execution of program begins
int main()
{
    cout<<"Welcome to Justin's calculator program!\n Enter an expression and the expression will be evaluated\n";
    string input;
    BinaryTree bt;
    while (cin>>input) {
      cout << Calculator::evaluate(input) << "\n";
   		
    	
    }
    return 0;
}
