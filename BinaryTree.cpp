#include <iostream>
 
using namespace std;
#include "BinaryTree.h"
#include "ExpressionParser.h"
#include <stack>
#include <vector>
using std::vector;

BinaryTree::BinaryTree(void) {
	root = NULL;
}
BinaryTree::~BinaryTree(void) {
}

bool BinaryTree::isEmpty(void) {
	if (root == NULL) {
		return true;
	}
	return false;
} 
void BinaryTree::insertPostfix(vector<string> postfix) {
	stack<BTNode*> st;
	if (postfix.size()==0){
		return;
	}
	for (int i = 0; i<postfix.size(); i++) {
		st = insertPostfixNode(postfix.at(i), st);

	}
	root = st.top();
	st.pop();

}
stack<BTNode*> BinaryTree::insertPostfixNode(string s, stack<BTNode*>st) {
	if (ExpressionParser::isNumber(s)) {
        // leaf (literal)
        BTNode* node = new BTNode(s);
        st.push(node);
    } else {
        // operator node
       BTNode* pNode = new BTNode(s);

        // add operands
       BTNode* right =st.top();
        pNode->setRightBTNode(right) ;
        st.pop();
        BTNode* left = st.top();
          pNode->setLeftBTNode(left) ;
          st.pop();

        // push result to operand stack
        st.push(pNode);
    }
    return st;
}
void BinaryTree::insert(string data) {
         root = insertRecursive(root, data);
 }
 BTNode* BinaryTree::insertRecursive(BTNode* node, string data) {
 	if (node == NULL) {
 			node = new BTNode(data);
 	}
 	else {
    	if (node->getRightBTNode() == NULL) {
    			BTNode* temp = insertRecursive(node->getRightBTNode(), data);
                 node->setRightBTNode(temp);
      	}
       	else {
          	BTNode* temp = insertRecursive(node->getLeftBTNode(), data);
          	node->setLeftBTNode(temp);             
       	}
   	}
 	return node;
 }
int BinaryTree::countNodes() {
	return countNodesRecursive(root);
}
int BinaryTree::countNodesRecursive(BTNode *node) {
	if (node == NULL) {
       	return 0;
   	}
  	
  	int numNodes = 1;
   	numNodes += countNodesRecursive(node->getLeftBTNode());
   	numNodes += countNodesRecursive(node->getRightBTNode());
  	return numNodes;
}
bool BinaryTree::search(string data){
	cout << "there\n";
  	return searchRecursive(root, data);
}
bool BinaryTree::searchRecursive(BTNode *node, string data) {
	if (node->getData() == data) {
		cout <<"1a\n";
       	return true;
	}
   	if (node->getLeftBTNode() != NULL) {
   		cout << "1b\n";
      	if (searchRecursive(node->getLeftBTNode(), data)) {
         	return true;
       	}
 	}
   	if (node->getRightBTNode() != NULL) {
   		cout << "1c\n";
       	if (searchRecursive(node->getRightBTNode(), data)) {
           	return true;
       	}
   	}
   	return false;         
     
}
void BinaryTree::inorder(){
   	inorderRecursive(root);
}
void BinaryTree::inorderRecursive(BTNode *node){
  	if (node == NULL) {
    	inorderRecursive(node->getLeftBTNode());
       cout << node->getData() << " ";
     	inorderRecursive(node->getRightBTNode());
  	}
}
void BinaryTree::preorder(){
 	preorderRecursive(root);
}
void BinaryTree::preorderRecursive(BTNode *node) {
   	if (node != NULL) {
     	cout << node->getData() << " ";
      	preorderRecursive(node->getLeftBTNode());             
       	preorderRecursive(node->getRightBTNode());
   	}
}
void BinaryTree::postorder() {
  	postorderRecursive(root);
}
void BinaryTree::postorderRecursive(BTNode *node) {
  	if (node != NULL) {
     	postorderRecursive(node->getLeftBTNode());             
        postorderRecursive(node->getRightBTNode());
        cout << node->getData() << " ";
   	}
}     
float BinaryTree::evaluateExpressionTree() {
	return evaluateExpressionTreePrivate(root);
}
float BinaryTree::evaluateExpressionTreePrivate(BTNode *node) {
	if (ExpressionParser::isNumber(node->getData())) {
		float ret = 0;
		ret = strtof((node->getData()).c_str(),0);
		return ret;
	}
	else {
		float left = evaluateExpressionTreePrivate(node->getLeftBTNode());
		float right = evaluateExpressionTreePrivate(node->getRightBTNode());
		return evaluate(left, right, node->getData());	
	}
	return 0;
}
float BinaryTree::evaluate(float left, float right, string symbol) {
	if (symbol == "+") {
		return left + right;
	}
	else if (symbol == "-") {
		return left - right;
	}
	else if (symbol == "*") {
		return left*right;
	}
	else if (symbol == "/") {
		return left/right;
	}
	return 0;

}
