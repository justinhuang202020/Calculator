#include <iostream>
 
using namespace std;
#ifndef BTNODE_H
#define BTNODE_H
class BTNode {
	public:
		BTNode(std::string data);
		~BTNode();
		BTNode* getLeftBTNode(void);
		BTNode* getRightBTNode(void);
		std::string getData(void);
		void setLeftBTNode(BTNode* node);
		void setRightBTNode(BTNode* node);
		void setData(std::string data);
	private:
		std::string nodeData;
		BTNode* rightNode;
		BTNode* leftNode;
};
#endif
