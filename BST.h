//Programmer: Travis Gopaul
//Date: 11/5/20
//BST.h 
//Header file for binary search tree class

#ifndef BST_H
#define BST_H

#include "TNode.h"

class BST	//class structure for binary search tree
{
	private:
		TNode *root;			//TNode pointer pointing to the root node
		//TNode maxNode(TNode*);		//find TNode storing max value	
		TNode* minNode(TNode*);		//find TNode storing min value
		TNode* successor(TNode*);	//find successor to TNode passed as parameter
		TNode predecessor(TNode*);	//find predecesspr to TNode passed as parameter
		TNode* createNode(int);		//create a new TNode
		TNode* search(TNode*, int);	//utility function to search tree with access to root
		void inOrder(TNode*);		//utility function for in order walk
		void preOrder(TNode*);		//utility function for pre order walk
		void postOrder(TNode*);		//utility function for post order walk

	public:
		BST();				//constructor
		~BST();				//destructor
		void inOrder();			//calls private in order walk
		void preOrder();		//calls private pre order walk
		void postOrder();		//calls private  post order walk
		void bstInsert(int);		//function to insert a node
		void bstDelete(TNode*);		//function to delete a node
		TNode* bstSearch(int);		//calls private search function
		bool isEmpty();			//determines if tree is empty
};

#endif
