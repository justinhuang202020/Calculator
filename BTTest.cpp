
#include<iostream> 
 
using namespace std;

#include <vector>
using std::vector;
#include <sstream>
#include <stdlib.h>  
#include "BtNode.h"
#include "BinaryTree.h"
  

 
// main function -
// where the execution of program begins
int main(){
    // BTNode node1("bro");
    // BTNode node2("yo");
    BinaryTree bt;
    cout << "checkpoint\n";
    bt.insert("1");
    bt.insert("2");
    bt.insert("3");
    bt.insert("4");
    cout << bt.countNodes() << "\n";
    cout << "here\n";
    cout <<bt.search("2");
    cout <<bt.search("1");
   cout <<bt.search("3");
    return 0;
}
