//Programmer: Travis Gopaul
//Date: 11/5/20
//TNode.cpp
//Member definitions for TNode class

#include <iostream>
#include "TNode.h"

using namespace std;

TNode::TNode(int x)		//constructor for TNode class object
{
	parent = NULL;
	left = NULL;
	right = NULL;
	data = x;	
}//end constructor


void TNode::printNode()	//function to print data in node
{
	cout << data << endl;
}//end printNode function
