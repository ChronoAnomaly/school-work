#ifndef _BRAIDED_
#define _BRAIDED_

class node
{
	public:
		node( void )	// node constructor both flink and blink point to node
		{
			flink = this;
			blink = this;
			std::cout << "node" << std::endl;
		}
		virtual ~node(void)		// node destructor
		{ std::cout << "~node" << std::endl; return; }
		node*	next( void )		// return pointer to the next node
		{ return this->flink; }
		node* 	prev( void )		// return a pointer to the previous node
		{ return this->blink; }
		node*	insert( node* );	// insert this node after the argument node
		node*	remove( void );		// remove this node form the list
	protected:
		node*	flink;		// pointer to the next node (i.e. front link)
		node*	blink;		// pointer to the previous node (i.e. back link)
	friend class braidedTree;
};

class treeNode
{
	public:
		treeNode( int d)		// construct a tree node with an integer value
		{
			data = d;
			leftTree = NULL;
			rightTree = NULL;
			std::cout << "treeNode" << std::endl;
		}
		virtual ~treeNode(void) 		// treeNode destructor
		{ std::cout << "~treeNode" << std::endl; return; }
	protected:
		int	data;		// data contents of the tree
		treeNode* leftTree;		// pointer to the left subtree
		treeNode* rightTree;		// pointer to the right subtree
	friend class braidedTree;
};

class braidedNode : public node, public treeNode
{
	public:
		// construct a braided node with a data value
		braidedNode( int d ) : treeNode( d ), node() { }
		braidedNode* leftChild(void)	// return pointer to left subtree
		{ std::cout << "leftChild" << std::endl;return dynamic_cast<braidedNode*> (treeNode::leftTree); }
		braidedNode* rightChild(void)	// return pointer to right subtree
		{ std::cout << "rightChild" << std::endl;return dynamic_cast<braidedNode*> (treeNode::rightTree); }
		// return a pointer to the successor braidedNode
		braidedNode* next(void)
		{ return dynamic_cast<braidedNode*> (node::next()); }
		// return a pointer to the previous braidedNode
		braidedNode* prev(void)
		{ return dynamic_cast<braidedNode*> (node::prev()); }
	friend class braidedTree;
};

class braidedTree
{
	public:
		braidedTree(void)
		{
			root = new braidedNode(-1);
			view = root;
			
			std::cout << "braidedTree" << std::endl;
		}
		~braidedTree(void)
		{ std::cout << root << std::endl; releaseTree(root); }
		int next();	
		int prev();	
		int value();

		void display();		

		bool isFirst();		
		bool isLast();		
		bool isHead();
		bool isEmpty();	


		bool find( int );
		int findMin( void );		
		int findMax( void );

		bool insert( int );		
		bool remove( int );			

		int removeMin(void);			
		int removeMax(void);			

	private:
		braidedNode*	root;	
		braidedNode*	view;	
		braidedNode* findParent( braidedNode*, int value);
		braidedNode* findPos( braidedNode*, int value);
		bool checkLinks( braidedNode*);
		bool isLeftmostNode( braidedNode* ptr, braidedNode* target);
		bool isRightmostNode( braidedNode* ptr, braidedNode* target);
		void searchTree( braidedNode*, int value, bool& found);
		void releaseTree( braidedNode*);
};

#endif

