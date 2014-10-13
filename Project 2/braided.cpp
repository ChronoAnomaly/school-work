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



//
// class braidedNode member functions
//




//
// class braidedTree member functions
//

int braidedTree::next()	
{
	cout << "next" << endl;
	
	if( isEmpty()) {
		cout << "The tree is currently empty" << endl;
	} else {

		view = view->next();
		return view->data;	
	}
}

int braidedTree::prev()	
{
	cout << "prev" << endl;

	if( isEmpty()) {
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
		ptr = ptr->next();
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

	return (!isEmpty() && (view == root->next()));
}

/*
	Returns true if the list is not empty and view is currently on the largest
	value.
*/
bool braidedTree::isLast()		
{
	cout << "isLast" << endl;

	return (!isEmpty() && (view == root->prev()));
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
	cout << boolalpha << "is empty = " << (root->rightTree == NULL) << endl;
	return (root->rightChild() == NULL);
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

		root->rightTree = new braidedNode( value);
		braidedNode* ptr = root->rightChild();
		ptr->flink = root;
		ptr->blink = root;
		root->flink = ptr;
		root->blink = ptr;

		root->rightTree = ptr;
		view = ptr;
		return true;
	} else {

		bool duplicate = false;
		searchTree( root->rightChild(), value, duplicate);

		if( duplicate) {
			return false;
		} else {


			braidedNode* ptr =  findPos( root->rightChild(), value);
			if( value < ptr->data) {
			
				ptr->leftTree = new braidedNode( value);
				braidedNode* target = ptr->leftChild();
				target->flink = ptr;
				target->blink = ptr->prev();
				ptr->blink->flink = target;
				ptr->blink = target;
				
				ptr->leftTree = target;
				view = target;

			} else {

				ptr->rightTree = new braidedNode( value);
				braidedNode* target = ptr->rightChild();
				target->flink = ptr->next();
				target->blink = ptr;
				ptr->flink->blink = target;
				ptr->flink = target;
	
				ptr->rightTree = target;
				view = target;
			}
			
			return true;
		}
	}
}



/*
	This function is used to find the current position of node with the data: value.
	It returns a pointer to the node if it is found, otherwise it will return
	a NULL.
*/
braidedNode* braidedTree::findPos( braidedNode* ptr, int value)
{

	braidedNode* target = ( value < ptr->data) ? ptr->leftChild(): ptr->rightChild();

	return (target) ? findPos( target, value) : ptr;
/*
	if( ptr == NULL) {

		return NULL;
	} else if {

		
	}
	if( value > ptr->data) {

		findPos( ptr->rightChild(), value);
	} else if ( value < ptr->data) {

		findPos( ptr->leftChild(), value);
	}
	return ptr;
*/
}

/*
	This function is used to find the parent of a certain node. It will go through
	the tree until it comes across a node which one of its children contain the
	value we are looking for. If found, it will return a pointer to the parent, else
	it will return NULL.
*/
braidedNode* braidedTree::findParent( braidedNode* ptr, int value)
{

	if( ptr == NULL) {

		return NULL;
	} else if( ptr == root->rightChild()) {

		return ptr;
	}

	if( ptr->leftTree != NULL || ptr->rightTree != NULL || ptr->leftTree->data == value 
	|| ptr->rightTree->data == value) {

		return ptr;
	}
	findParent( ptr->leftChild(), value);
	findParent( ptr->rightChild(), value);
}

/*
	This function is used to find out if our target node if the right most node in the tree.
	This will be used after inserting a node into the tree to find out if we need to
	link the node to the root of the tree or the header node.
*/
bool braidedTree::isLeftmostNode( braidedNode* ptr, braidedNode* target)
{

	while( ptr != NULL && ptr->leftTree != NULL) {
	
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

	while( ptr != NULL && ptr->rightTree != NULL) {
		ptr = ptr->rightChild();
	}
	
	if( target == ptr) {

		return true;
	} else {
	
		return false;
	}
}

/*
	Used by remove function to determine if the node is a leaf node.
*/
bool braidedTree::isLeaf( braidedNode* ptr)
{

	if( ptr->rightChild() == NULL && ptr->leftChild() == NULL) {
		
		return true;
	} else {
		
		return false;
	}
}

bool braidedTree::remove( int value)			
{
	cout << "remove" << endl;

	bool found = false;

	searchTree( root->rightChild(), value, found);

	if( found) {

		braidedNode* parent = findParent( root->rightChild(), value);	

		if( value < parent->data) {

			braidedNode* doomed = parent->leftChild();
		
			if( isLeaf( doomed)) {

				parent->leftTree = NULL;
				parent->blink = doomed->prev();
				delete doomed;

			} else {

				if( doomed->leftTree != NULL) {
			
					braidedNode* left = doomed->leftChild();
					left->flink = parent;
					parent->leftTree = left;
					//parent->leftTree = doomed->leftChild();
					//parent->leftTree->flink = parent;
					delete doomed;
				} else {

					braidedNode* right = doomed->rightChild();
					right->blink = parent;
					parent->rightTree = right;
					//parent->rightTree = doomed->rightChild();
					//parent->rightTree->blink = parent;
					delete doomed;
				}
			}
		} else {

			braidedNode* doomed = parent->rightChild();

			if( isLeaf( doomed)) {

				parent->rightTree = NULL;
				parent->flink = doomed->next();
				delete doomed;

			} else {
	
				if( doomed->leftTree != NULL) {

					braidedNode* left = doomed->leftChild();
					left->flink = parent;
					parent->leftTree = left;
					//parent->leftTree = doomed->leftChild();
					//parent->leftTree->flink = parent;
					delete doomed;
				} else {

					braidedNode* right = doomed->rightChild();
					right->blink = parent;
					parent->rightTree = right;
					//parent->rightTree = doomed->rightChild();
					//parent->rightTree->blink = parent;
					delete doomed;
				}
			}
			
		}
		return found;

	} else {

		view = root;
		return found;
	}
}

/*
	Removes the smallest node currently in the tree and returns the value of the node.
*/
int braidedTree::removeMin(void)
{
	cout << "removeMin" << endl;
	
	int val = 0;

	if( !isEmpty()) {

		if( view == root->next()) {
			view = root;
		}

		braidedNode* ptr = root->next();
		braidedNode* clearChild = findParent( root->rightChild(), root->next()->data);
		clearChild->leftTree = NULL;
		root->flink = ptr->next();	// manually set the links for the header node
		ptr->flink->blink = ptr->prev();
		val = ptr->data;
		delete ptr;
		
	} else {

		cout << "The tree is currently empty" << endl;
	}

	return val;
}

/*
	Removes the largest node currently in the tree and returns the value of the node.
*/
int braidedTree::removeMax(void)
{
	cout << "removeMax" << endl;
	
	int val = 0;

	if( !isEmpty()) {

		if( view == root->prev()) {
			view = root;
		}

		braidedNode* ptr = root->prev();
		braidedNode* clearChild = findParent( root->rightChild(), root->prev()->data);
		clearChild->rightTree = NULL;
		root->blink = ptr->blink;	// manually set the links for the header node
		ptr->blink->flink = ptr->next();
		val = ptr->data;
		delete ptr;

	} else {

		cout << "The tree is currently empty" << endl;
	}

	return val;
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
