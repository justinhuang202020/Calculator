// Simple C++ program to display "Hello World"
 
// Header file for input output functions
#include<iostream> 
 
using namespace std;

#include <vector>
using std::vector;
#include <sstream>
#include <stdlib.h>  
#include "BtNode.h"
  

 
// main function -
// where the execution of program begins
int main(){
    BTNode node1("bro");
    BTNode node2("yo");
    node1.setLeftBTNode(&node2);
    cout << node1.getLeftBTNode().getData() << "\n";
   
    return 0;
}
