#include <iostream>
 
using namespace std;
#include "BTNode.h"
#include <stack>
#include <sstream>
#include <vector>
using std::vector;
#ifndef BINARYTREE_H

#define BINARYTREE_H
class BinaryTree {
	public:
		BinaryTree();
		~BinaryTree();
		bool isEmpty(void);
		void insert(string data);
		int countNodes(void);
		bool search(string data);
		void inorder(void);
		void postorder(void);
		void preorder(void);
		void insertPostfix(vector<string> postfix);
		float evaluateExpressionTree();
	private:
		BTNode* root;
		float evaluateExpressionTreePrivate(BTNode *node);
		float evaluate(float left, float right, string symbol);
		BTNode* insertRecursive(BTNode* node, string data);
		int countNodesRecursive(BTNode* node);
		bool searchRecursive(BTNode *node, string data);
		void inorderRecursive(BTNode *node);
		void preorderRecursive(BTNode *node);
		void postorderRecursive(BTNode *node);
		stack<BTNode*> insertPostfixNode(string s, stack<BTNode*> st);
};
#endif
