/*******************************************************************
 * FILE
 *	Stack.h - Stack interface file
 *******************************************************************
 */

template <typename keytype>
class SNode
	{
    private:
	SNode(keytype, SNode *);	// CONSTRUCTOR
	keytype key;
	SNode *next;

	template <typename T> friend class Stack;
	};

template <typename keytype>
class Stack
	{
    public:
	Stack();			// CONSTRUCTOR
	virtual ~Stack();		// DESTRUCTOR
	void Insert(keytype);
	keytype Remove();
	bool isEmpty();
    private:
	void error(char msg[]);		// fatal error handler
	SNode<keytype> *top;
	};
