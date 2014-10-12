#include <iostream>
#include "braided.h"

using namespace std;

//
// class node member functions
//


node*	node::insert( node* )
{ cout << "insert" << endl; return NULL; }

node*	node::remove( void )
{ cout << "remove" << endl; return NULL; }


//
// class treeNode member functions
//

treeNode::~treeNode(void)
{ cout << "~treeNode" << endl; return; }


//
// class braidedNode member functions
//




//
// class braidedTree member functions
//

int braidedTree::next()	
{
	cout << "next" << endl;
	
	if( view == root) {
		cout << "The tree is currently empty" << endl;
	} else {

		view = view->next();
		return view->data;	
	}
}

int braidedTree::prev()	
{
	cout << "prev" << endl;

	if( view == root) {
		cout << "The tree is currently empty" << endl;
	} else {

		view = view->prev();
		return view->data;
	}
}
int braidedTree::value()
{
	cout << "value" << endl;
	
	return view->data;
}

void braidedTree::display()		
{
	cout << "display" << endl;

	cout << "[";

	braidedNode* ptr = dynamic_cast<braidedNode*> (root->flink);
	
	while(ptr != root) {

		cout << " " << ptr->data << (ptr->next != root) ? "," : "]";
	}

	cout << endl;
	return;
}

/*
	Returns true if the list is not empty and view is currently on the smallest
	value.
*/
bool braidedTree::isFirst()		
{
	cout << "isFirst" << endl;

	return (!isEmpty() && (view == root->flink));
}

/*
	Returns true if the list is not empty and view is currently on the largest
	value.
*/
bool braidedTree::isLast()		
{
	cout << "isLast" << endl;

	return (!isEmpty() && (view == root->blink));
}

/*
	Checks if the view node is currently on the root node.
*/
bool braidedTree::isHead()
{
	cout << "isHead" << endl;

	return (view == root);
}

/*
	Checks if the right child of the root is empty. If so, then the tree is empty, else
	the tree has nodes in it.
*/
bool braidedTree::isEmpty()	
{
	cout << "isEmpty" << endl;
	
	return root->rightTree == NULL;
}

bool braidedTree::find( int )
{
	cout << "find" << endl;
	
	return false;
}

/*
	Sets the view node to the smallest value and returns the value if the tree
	contains nodes.
*/
int braidedTree::findMin( void )		
{
	cout << "findMin" << endl;

	if( !isEmpty()) {
	
		view = dynamic_cast<braidedNode*> (root->flink);

		return view->data;
	} else {

		cout << "The tree is currently empty" << endl;
		return 0;
	}
}

/*
	Sets the view node to the largest value and returns the value if the tree
	contains nodes.
*/
int braidedTree::findMax( void )
{
	cout << "findMax" << endl;

	if( !isEmpty()) {

		view = dynamic_cast<braidedNode*> (root->blink);

		return view->data;
	} else {

		cout << "The tree is currently empty" << endl;
		return 0;
	}
}

bool braidedTree::insert( int )		
{
	cout << "insert" << endl;

	return false;
}

bool braidedTree::remove( int )			
{
	cout << "remove" << endl;

	return false;
}

int braidedTree::removeMin(void)
{
	cout << "removeMin" << endl;
	
	if( !isEmpty()) {

		if( view == root->flink) {
			view = root;
		}

		braidedNode* ptr = dynamic_cast<braidedNode*> (root->flink);
		root->flink = ptr->flink;
		delete ptr;
		
	} else {

		cout << "The tree is currently empty" << endl;
	}

	return 0;
}

int braidedTree::removeMax(void)
{
	cout << "removeMax" << endl;
	
	if( !isEmpty()) {

		if( view == root->blink) {
			view = root;
		}

		braidedNode* ptr = dynamic_cast<braidedNode*> (root->blink);
		root->blink = ptr->blink;
		delete ptr;

	} else {

		cout << "The tree is currently empty" << endl;
	}

	return 0;
}

/*
	This function is used by ~braidedTree to delete the whole tree. It will
	traverse the tree in post order form and delete the nodes recursively.
*/
void braidedTree::releaseTree(braidedNode* ptr)
{

	cout << ptr << endl;
	if( ptr != NULL) {
		
		releaseTree( dynamic_cast<braidedNode*> (ptr->leftTree));
		releaseTree( dynamic_cast<braidedNode*> (ptr->rightTree));
		delete ptr;

	}
}
