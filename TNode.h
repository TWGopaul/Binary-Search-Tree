//Programmer: Travis Gopaul
//Date: 11/5/20
//TNode.h
//Header file for tree node class

#ifndef TNODE_H
#define TNODE_H

class TNode	//class to define a node that will be part of a tree
{
	private:
		TNode *parent; 		//pointer to parent node
		TNode *left;		//pointer to left child
		TNode *right;		//pointer to right child
		int data;		//data stored in node

	public:
		TNode(int);		//constructor
		void printNode();	//member function to print node information
		friend class BST;	//BST class is friend of TNode class
};

#endif
