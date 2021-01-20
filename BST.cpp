//Programmer: Travis Gopaul
//Date: 11/5/20
//BST.cpp
//Member definitions for Binary Search Tree header file

#include <iostream>

#include "BST.h"
#include "TNode.h"

using namespace std;

// * * * * * * * * Private member definitions * * * * * * * * 

TNode* BST::createNode(int x)
{
	TNode *node;
	node = new TNode(x);
	return node;
}// end createNode function

TNode* BST::search(TNode* node, int key)
{
        if (node == NULL || key == node->data)          //if root or node w/ key is found
                return node;                            //returns the node containing the data, or null
        if (key < node->data)
                return search(node->left, key);      //if key is less than current node data, search left
        else
                return search(node->right, key);     //else search right
}//end private search

void BST::inOrder(TNode* node)
{
        if (node != NULL)                       //if tree is populated
        {
                inOrder(node->left);            //recursive call to reach leftmost node
                cout << node->data << " ";      //print that node
                inOrder(node->right);           //reach the rightmost node then print it
        }//end if
}//end private inOrder

void BST::preOrder(TNode* node)
{
	if(node != NULL)			//if tree is populated
	{
		cout << node->data << " ";	//print data at current node(parent)
		preOrder(node->left);		//traverse to left children, then print
		preOrder(node->right);		//traverse to right children, then print
	}//end if
}//end private preOrder


void BST::postOrder(TNode* node)
{
	if (node != NULL)			//if tree is populated
	{
		postOrder(node->left);          //traverse to left children, then print
                postOrder(node->right);         //travers to right children, then print
                cout << node->data << " ";      //print data at current node (parent)

	}//end if
}//end private postOrder

TNode* BST::minNode(TNode* node)		//function returns the node with the smallest key from the given node
{
	while(node->left != NULL)		//search for left most node
	{
		node = node->left;
	}//end while
	return node;
}//end minNode

TNode* BST::successor(TNode* node)		//function returns the successor of the node passed as parameter
{
	if (node->right != NULL)		//if right subtree is not empty
		return minNode(node->right);	//return the the next lowest ancestor 
	else
	{
		TNode *temp = node->parent;			//else look at parent node
		
		while (temp != NULL && node == temp->right)	//iterate until node is temp's left child, it is successor
		{
			node = temp;
			temp = temp->parent;
		}//end while
		return temp;					//return successor node
	}//end else
}//end successor

// * * * * * * * * Public member definitions * * * * * * * *

BST::BST()		//Binary search tree constructor
{
	root = NULL;	//set root equal to NULL
}//end constructor

BST::~BST()		//BST destructor
{
	while(root != NULL)			//keep deleting until root is deleted (root == NULL)
	{
		TNode *temp = root;		//find the minimum node starting from the root
		bstDelete(minNode(temp));	//delete the node
	}//end while
}//end destructor


void BST::inOrder()		//function prints in order walk
{
	TNode *temp = root;	//temp pointer to pass as parameter
	inOrder(temp);		//call private inOrder function
	cout << endl;
}//end inOrder

void BST::preOrder()		//function prints pre order walk
{
	TNode *temp = root;    	//temp TNode set to root; will be used to iterate through the tree  
	preOrder(temp);
	cout << endl;
}//end preOrder

void BST::postOrder()		//function print post order walk
{
	TNode *temp = root;	//temp TNode set to root; will be used to iterate through the tree  
	postOrder(temp);	//call private post order walk		
	cout << endl;
}//end postOrder

void BST::bstInsert(int x)			//insert node function, pass in data for new node
{
	TNode *node = createNode(x);		//create new node with data

	TNode *temp1, *temp2;			//temp node pointers; temp1 = root, temp2 is a placeholder to find
						//location to insert
	temp1 = root;
	temp2 = NULL;

	while(temp1 != NULL)			//find location for new node
	{
		temp2 = temp1;				
		if(node->data < temp1->data)	//if data is less that root:
			temp1 = temp1->left;	//node goes to left side
		else
			temp1 = temp1->right;	//else node does to the right
	}
	
	node->parent = temp2;			//set new node's parent to proper location

	if(temp2 == NULL)			//if parent is NULL then new node is the root
		root = node;
	else if(node->data < temp2->data)		
		temp2->left = node;		//else place node as left leaf
	else
		temp2->right = node;		//or place node as right leaf

}//end Insert

void BST::bstDelete(TNode *node)		//function to delete a node	
{
	TNode *temp1, *temp2;			//temp nodes to be place holders
	if (node->left == NULL || node->right == NULL)	//if node has 1 child
		temp1 = node;				//hold place of child node
	else
		temp1 = successor(node);		//else find node's sucessor

	if (temp1->left != NULL)			//if child or successor has left child
		temp2 = temp1->left;			//hold place of child
	else
		temp2 = temp1->right;			//else hold place of right child

	if(temp2 != NULL)
		temp2->parent = temp1->parent;

	if (temp1->parent == NULL)
		root = temp2;
	else if(temp1 == temp1->parent->left)
		temp1->parent->left = temp2;
	else
		temp1->parent->right = temp2;

	if(temp1 != node)
		node->data = temp1->data;

	delete temp1;
}//end Delete

TNode* BST::bstSearch(int key)		//function searches tree for node; tree and key as parameters
{
	TNode *temp = root;		//temp node set equal to root
	return search(temp, key);	//call private search 
}//end Search

bool BST::isEmpty()			//function returns true if tree is empty, false if it is populated
{
	if(root == NULL)
		return true;
	else 
		return false;
}//end isEmpty
