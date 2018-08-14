
#include<iostream> 
 
using namespace std;

#include <vector>
using std::vector;
#include <sstream>   
#include "Calculator.h"
 
// main function -
// where the execution of program begins
int main()
{
    cout<<"Welcome to Justin's calculator program!\n Enter an expression and the expression will be evaluated\n";
    string input;
    while (cin>>input) {
      try {
      cout << Calculator::evaluate(input) << "\n";
        } catch (const char* msg) {
          cout << msg << "\n";
      }
   		
    	
    }
    return 0;
}
