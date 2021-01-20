//Programmer: Travis Gopaul
//Date: 11/8/20
//Lab7.cpp
//Executable driver program to test binary search tree functionality

#include <iostream>
#include "TNode.h"
#include "BST.h"

using namespace std;

int main()
{
	char menuChoice;		//variables to store user input
        int nodeData;
	BST tree;			//create BST object to store nodes

	do	// display menu			
	{
		cout << "Binary Tree Program" << endl;
		cout << "===================" << endl;
		cout << "1. Insert a Node" << endl;
                cout << "2. Delete a Node" << endl;
                cout << "3. Print In Order" << endl;
                cout << "4. Print Post Order" << endl;
                cout << "5. Print Pre Order" << endl;
                cout << "6. Exit Program" << endl;

		cin >> menuChoice;	// user menu selection

		while(menuChoice < '1' || menuChoice > '6')	//input validation
		{
			cout << "Please make valid selection." << endl;
			cin >> menuChoice;
		} // end whlie


	if(menuChoice == '1')						//insert a node
	{
		system("clear");

		cout << "Enter int to store in node: " << endl;		// gather node data from user
		cin >> nodeData;

		if(tree.bstSearch(nodeData) == NULL)			//search tree for node existence 
			
			tree.bstInsert(nodeData);			//if distinct, create new node with data given and insert
		else							//else display node already exists and do nothing
			cout << "Node already exists in tree." << endl;

	}// end if 1

        if(menuChoice == '2')						//delete a node
	{
                system("clear");

                if(tree.isEmpty())                                        //if tree is empty display message and do nothing
                        cout << "Tree is empty." << endl;
		else
		{
	                cout << "Enter the int of the node to delete." << endl;		//gather search query
        	        cin >> nodeData;

			TNode *temp = tree.bstSearch(nodeData);				//search for node

			if(temp == NULL)						//check if node exists
				cout << "Node does not exist in the tree." << endl;	//if not, display message and do nothing
			else
			{
				tree.bstDelete(temp);					//else delete the node
			}//end else
		}//end else
	}// end if 2

        if(menuChoice == '3')			//print in order walk
	{
                system("clear");
		if(tree.isEmpty())		//if tree is empty, display message and do nothing
			cout << "Tree is empty." << endl;
		else
			tree.inOrder();		//call public inOrder walk function	
	}	// end if 3

        if(menuChoice == '4')			//print post order walk
	{
                system("clear");

		if(tree.isEmpty())               //if tree is empty, display message and do nothing
                	cout << "Tree is empty." << endl;
		else
			tree.postOrder();	//call public post order 
	}	// end if 4

        if(menuChoice == '5')			//print pre order walk
	{
                system("clear");

		if(tree.isEmpty())              //if tree is empty, display message and do nothing
                	cout << "Tree is empty." << endl;
		else
			tree.preOrder();	//call public preOrder walk function
	}	// end if 5
	
	}// end do	

	while(menuChoice != '6');	// exit if user enters 6

	return 0;
}//end main
