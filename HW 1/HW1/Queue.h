/*******************************************************************
 * FILE
 *	Queue.h - Queue interface file
 *******************************************************************
 */

template <typename keytype>
class QNode
	{
    private:
	QNode(keytype);			// CONSTRUCTOR
	keytype	key;
	QNode	*next;

	template <typename T> friend class Queue;
	};

template <typename keytype>
class Queue
	{
    public:
	Queue();			// CONSTRUCTOR
	virtual ~Queue();		// DESTRUCTOR
	void Insert(keytype);
	keytype Remove();
	bool isEmpty();
    private:
	void error(char msg[]);		// fatal error handler
	QNode<keytype>	*front;
	QNode<keytype>	*rear;
	};
