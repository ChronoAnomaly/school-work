/*******************************************************************
 * FILE
 *	Stack.cpp - Stack implementation
 * DESCRIPTION
 *	This file implements a bounded stack using an array.
 *******************************************************************
 */

#include <iostream>

#include "Stack.h"

using namespace std;

/*******************************************************************
 * FUNCTION
 *	SNode::SNode - Stack node constructor
 * PARAMETERS
 *	elem	- value of key
 *	curr	- current top of stack
 * RETURN VALUE
 *	not applicable
 *******************************************************************
 */

template <typename keytype>
SNode<keytype>::SNode(keytype elem, SNode *curr)
	{
	key = elem;
	next = curr;
	}

/*******************************************************************
 * FUNCTION
 *	Stack::Stack - Stack constructor
 * PARAMETERS
 *	Not applicable
 * RETURN VALUE
 *	not applicable
 *******************************************************************
 */

template <typename keytype>
Stack<keytype>::Stack()
	{
	top = (SNode<keytype> *) NULL;
	}

/*******************************************************************
 * FUNCTION
 *	Stack::~Stack - Stack destructor
 * PARAMETERS
 *	None
 * RETURN VALUE
 *	not applicable
 *******************************************************************
 */

template <typename keytype>
Stack<keytype>::~Stack()
	{
	while(top)
		{
		SNode<keytype> *doomed = top;
		top = top->next;
		delete doomed;
		}
	}

/*******************************************************************
 * FUNCTION
 *	Stack::Insert - Push an element onto the stack
 * PARAMETERS
 *	elem	- the value to be pushed onto the stack
 * RETURN VALUE
 *	None
 * SIDE EFFECTS
 *	The fatal error handler is called if there is insufficient
 *	memory for the new node.
 *******************************************************************
 */

template <typename keytype>
void Stack<keytype>::Insert(keytype elem)
	{
	top = new SNode<keytype>(elem, top);
	if(top == NULL)
		error("Insert: insufficient memory");
	}

/*******************************************************************
 * FUNCTION
 *	Stack::Remove - Remove an element from the top of the stack
 * PARAMETERS
 *	None
 * RETURN VALUE
 *	The value of the item removed from the stack
 * SIDE EFFECTS
 *	The fatal error handler is called if the stack is empty.
 *******************************************************************
 */

template <typename keytype>
keytype Stack<keytype>::Remove()
	{
	if(top == NULL)
		error("Remove: stack is empty");

	SNode<keytype> *doomed = top;
	keytype elem = top->key;
	top = top->next;
	delete doomed;

	return elem;
	}

/*******************************************************************
 * FUNCTION
 *	Stack::isEmpty - Test for stack empty
 * PARAMETERS
 *	None
 * RETURN VALUE
 *	TRUE if the stack is empty and FALSE otherwise
 *******************************************************************
 */

template <typename keytype>
bool Stack<keytype>::isEmpty()
	{
	return (top == NULL);
	}

/*******************************************************************
 * FUNCTION
 *	Stack::error - fatal error handler for class stack
 * PARAMETERS
 *	msg	- the error message
 * RETURN VALUE
 *	None
 * SIDE EFFECTS
 *	Program execution is halted immediately.
 *******************************************************************
 */

template <typename keytype>
void Stack<keytype>::error(char msg[])
	{
	cout << "Stack::" << msg << "\n";
	exit(1);
	}

template class SNode<int>;
template class Stack<int>;
