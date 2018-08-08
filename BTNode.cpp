#include <iostream>
 
using namespace std;
#include "BTNode.h"


BTNode::BTNode(std::string data) {
	nodeData = data;
   leftNode = NULL;
   rightNode = NULL;
}
BTNode::~BTNode(void) {

}
BTNode* BTNode::getLeftBTNode(void) {
	return leftNode;
} 
BTNode* BTNode::getRightBTNode(void) {
	return rightNode;
}
void BTNode::setLeftBTNode(BTNode* node) {
	leftNode = node;
}
void BTNode::setRightBTNode(BTNode* node) {
	rightNode = node;
}

std::string BTNode::getData(void) {
	return nodeData;
}
void BTNode::setData(std::string data) {
	nodeData = data;
}