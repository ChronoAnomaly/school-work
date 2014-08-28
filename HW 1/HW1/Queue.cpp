/*******************************************************************
 * FILE
 *	Queue.cpp - Queue implementation
 * DESCRIPTION
 *	This file implements an unbounded queue using a linked list.
 *******************************************************************
 */

#include <iostream>

#include "Queue.h"

using namespace std;

/*******************************************************************
 * FUNCTION
 *	QNode::QNode - Queue node constructor
 * PARAMETERS
 *	elem	- value of key
 * RETURN VALUE
 *	not applicable
 *******************************************************************
 */

template <typename keytype>
QNode<keytype>::QNode(keytype elem)
	{
	key = elem;
	next = NULL;
	}

/*******************************************************************
 * FUNCTION
 *	Queue::Queue - Queue constructor
 * PARAMETERS
 *	not applicable
 * RETURN VALUE
 *	not applicable
 *******************************************************************
 */

template <typename keytype>
Queue<keytype>::Queue()
	{
	front = NULL;
	}

/*******************************************************************
 * FUNCTION
 *	Queue::~Queue - Queue destructor
 * PARAMETERS
 *	None
 * RETURN VALUE
 *	not applicable
 *******************************************************************
 */

template <typename keytype>
Queue<keytype>::~Queue()
	{
	while(front)
		{
		QNode<keytype> *doomed = front;
		front = front->next;
		delete doomed;
		}
	}

/*******************************************************************
 * FUNCTION
 *	Queue::Enter - Enter an element into the queue
 * PARAMETERS
 *	elem	- the value to be pushed onto the stack
 * RETURN VALUE
 *	None
 * SIDE EFFECTS
 *	The fatal error handler is called if there is no
 *	memory to allocate.
 *******************************************************************
 */

template <typename keytype>
void Queue<keytype>::Insert(keytype elem)
	{
	QNode<keytype> *curr = new QNode<keytype>(elem);
	if(curr == NULL)
		error("Insert: Insufficient memory");
	if(front)
		rear->next = curr;
	else
		front = curr;
	rear = curr;
	}

/*******************************************************************
 * FUNCTION
 *	Queue::Remove - Remove an element from the top of the stack
 * PARAMETERS
 *	None
 * RETURN VALUE
 *	The value of the item removed from the stack
 * SIDE EFFECTS
 *	The fatal error handler is called if the stack is empty
 * NOTES
 *	When the queue becomes empty, the rear pointer is left
 *	dangling.  The front pointer is the correct pointer to
 *	use when the queue is empty.
 *******************************************************************
 */

template <typename keytype>
keytype Queue<keytype>::Remove()
	{
	if(front == NULL)
		error("Remove: queue is empty");
	QNode<keytype> *doomed = front;
	keytype elem = front->key;
	front = front->next;

	return elem;
	}

/*******************************************************************
 * FUNCTION
 *	Queue::isEmpty - Test for queue empty
 * PARAMETERS
 *	None
 * RETURN VALUE
 *	TRUE if the queue is empty and FALSE otherwise
 *******************************************************************
 */

template <typename keytype>
bool Queue<keytype>::isEmpty()
	{
	return (front == NULL);
	}

/*******************************************************************
 * FUNCTION
 *	Queue::error - fatal error handler for class queue
 * PARAMETERS
 *	msg	- the error message
 * RETURN VALUE
 *	None
 * SIDE EFFECTS
 *	Program execution is halted immediately.
 *******************************************************************
 */

template <typename keytype>
void Queue<keytype>::error(char msg[])
	{
	cout << "Queue::" << msg << "\n";
	exit(1);
	}

template class Queue<int>;
