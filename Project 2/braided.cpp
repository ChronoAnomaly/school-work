#include <iostream>
#include "braided.h"

using namespace std;

//
// class node member functions
//


node*	node::insert( node* )
{
 cout << "insert" << endl; return NULL; }

node*	node::remove( void )
{ cout << "remove" << endl; return NULL; }


//
// class treeNode member functions
//



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

	braidedNode* ptr = root->next();
	
	while(ptr != root) {

		cout << " " << ptr->data; 
	}

	cout << "]" << endl;
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

/*
	This function will start a search in the current tree for some value and
	will return true or false if the value is found in the tree.
*/
bool braidedTree::find( int value)
{
	cout << "find" << endl;
	
	bool found = false;

	searchTree( root->rightChild(), value, found);
	
	return found;
}

/*
	Searches through the current tree for the value. If it is found, it will update
	a boolean varible to true and exit the recursion.
*/
void braidedTree::searchTree( braidedNode* ptr, int value, bool& found)
{

	if( ptr != NULL && !found){

		if( ptr->data == value){
			found = true;
			view = ptr;
		}
		searchTree( ptr->leftChild(), value, found);
		searchTree( ptr->rightChild(), value, found);
	}
}

/*
	Sets the view node to the smallest value and returns the value if the tree
	contains nodes.
*/
int braidedTree::findMin( void )		
{
	cout << "findMin" << endl;

	if( !isEmpty()) {
	
		view = root->next();

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

		view = root->prev();

		return view->data;
	} else {

		cout << "The tree is currently empty" << endl;
		return 0;
	}
}

bool braidedTree::insert( int value)		
{
	cout << "insert" << endl;

	/* If the tree is empty, then we create a new head node under the header root node
	and set its links to the root node. */
	if( isEmpty()) {

		braidedNode* ptr = root->rightChild();
		ptr = new braidedNode( value);
		ptr->flink = root;
		ptr->blink = root;
		root->flink = ptr;
		root->blink = ptr;

		view = ptr;
		return true;
	} else {

		bool duplicate = false;
		searchTree( root->rightChild(), value, duplicate);

		if( duplicate) {
			return false;
		} else {


			braidedNode* ptr =  findPos( root->rightChild(), value);
			
			
		}
	}
}

braidedNode* braidedTree::findPos( braidedNode* ptr, int value)
{

	if( value > ptr->data) {

		findPos( ptr->rightChild(), value);
	} else {

		findPos( ptr->leftChild(), value);
	}
	return ptr;
}

braidedNode* braidedTree::findParent( braidedNode* ptr, int value)
{

	if( ptr->leftTree->data == value || ptr->rightTree->data == value) {

		return ptr;
	}
	findParent( ptr->leftChild(), value);
	findParent( ptr->rightChild(), value);
	return NULL;
}

/*
	This function is used to find out if our target node if the right most node in the tree.
	This will be used after inserting a node into the tree to find out if we need to
	link the node to the root of the tree or the header node.
*/
bool braidedTree::isLeftmostNode( braidedNode* ptr, braidedNode* target)
{

	while( ptr->leftTree != NULL) {
	
		ptr = ptr->leftChild();
	}

	if( target == ptr) {
	
		return true;
	} else {
	
		return false;
	}
}

/*
	This function is used to find out if our target node if the left most node in the tree.
	This will be used after inserting a node into the tree to find out if we need to
	link the node to the root of the tree or the header node.
*/
bool braidedTree::isRightmostNode( braidedNode* ptr, braidedNode* target)
{

	while( ptr->rightTree != NULL) {
		ptr = ptr->rightChild();
	}
	
	if( target == ptr) {

		return true;
	} else {
	
		return false;
	}
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

		if( view == root->next()) {
			view = root;
		}

		braidedNode* ptr = root->next();
		root->flink = ptr->flink;	// manually set the links for the header node
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

		if( view == root->prev()) {
			view = root;
		}

		braidedNode* ptr = root->prev();
		root->blink = ptr->blink;	// manually set the links for the header node
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
		
		releaseTree( ptr->leftChild());
		releaseTree( ptr->rightChild());
		delete ptr;

	}
}
