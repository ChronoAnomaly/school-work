#ifndef _BRAIDED_
#define _BRAIDED_

class node
{
	public:
		node( void );				// node constructor both flink and blink point to node
		virtual ~node(void);			// node destructor
		node*	next( void );			// return pointer to the next node
		node* 	prev( void );			// return a pointer to the previous node
		node*	insert( node* );		// insert this node after the argument node
		node*	remove( void );			// remove this node form the list
	protected:
		node*		flink;			// pointer to the next node (i.e. front link)
		node*		blink;			// pointer to the previous node (i.e. back link)
	friend class braidedTree;
};

class treeNode
{
	public:
		treeNode( int );			// construct a tree node with an integer value
		virtual ~treeNode(void); 		// treeNode destructor
	protected:
		int			data;		// data contents of the tree
		treeNode*	leftTree;		// pointer to the left subtree
		treeNode*	rightTree;		// pointer to the right subtree
	friend class braidedTree;
};

class braidedNode : public node, public treeNode
{
	public:
		braidedNode( int );			// construct a braided node with a data value
		braidedNode* leftChild(void);	// return pointer to left subtree
		braidedNode* rightChild(void);	// return pointer to right subtree
		braidedNode* next(void){ return
dynamic_cast<braidedNode*> (node::next());}
		// return a pointer to
the successor braidedNode
		braidedNode* prev(void);		// return a pointer to the previous braidedNode
	friend class braidedTree;
};

class braidedTree
{
	public:
		braidedTree(void);
		~braidedTree(void);			

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
};

#endif

