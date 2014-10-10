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
braidedTree::braidedTree(void)
{ 
	root = new braidedNode(-1);
	view = root;
	root->flink = root;
	root->blink = root;

	cout << "braidedTree" << endl; 
}

braidedTree::~braidedTree(void)			
{ cout << "~braidedTree" << endl; return; }

int braidedTree::next()	
{
	cout << "next" << endl;
	
	if( view == root) {
		cout << "The tree is currently empty" << endl;
	} else {

		view = view->next();	
	}
}

int braidedTree::prev()	
{
	cout << "prev" << endl;

	if( view == root) {
		cout << "The tree is currently empty" << endl;
	} else {

		view = view->prev();
	}
}
int braidedTree::value()
{
	cout << "value" << endl;
	
	cout << view->data << endl;

	return 0;
}

void braidedTree::display()		
{ cout << "display" << endl; return; }

bool braidedTree::isFirst()		
{ cout << "isFirst" << endl; return false; }

bool braidedTree::isLast()		
{ cout << "isLast" << endl; return false; }

bool braidedTree::isHead()
{ cout << "isHead" << endl; return false; }

bool braidedTree::isEmpty()	
{ cout << "isEmpty" << endl; return false; }

bool braidedTree::find( int )
{ cout << "find" << endl; return false; }

int braidedTree::findMin( void )		
{ cout << "findMin" << endl; return 0; }

int braidedTree::findMax( void )
{ cout << "findMax" << endl; return 0; }

bool braidedTree::insert( int )		
{ cout << "insert" << endl; return false; }

bool braidedTree::remove( int )			
{ cout << "remove" << endl; return false; }

int braidedTree::removeMin(void)			
{ cout << "removeMin" << endl; return 0; }

int braidedTree::removeMax(void)
{ cout << "removeMax" << endl; return 0; }
