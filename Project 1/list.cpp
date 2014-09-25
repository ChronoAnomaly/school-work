/*
  Brett Worley
  CS 3100 - 01
  8/28/14
*/

#include <iostream>

#include "list.h"

using namespace std;

template <typename T>
Node<T>::Node( T data )
{
	m_data = data;
	m_link = NULL;
}

template <typename T>
Node<T>::Node( T data, Node* link )
{
	m_data = data;
	m_link = link;
}

template <typename T>
List<T>::List()
{
	m_head = NULL;
}

// LIST PUBLIC MEMBER FUNCTIONS

template <typename T>
List<T>::List( int numItems, const T items[] )
{
	m_head = NULL;
	Node<T>* tail = NULL;

	if ( numItems > 0 )
	{
		m_head = tail = new Node<T>( items[0] );
		for ( int i = 1; i < numItems; i++ )
		{
			tail = tail->m_link = new Node<T>( items[i] );
		}
	}
}

template <typename T>
List<T>::List( List& L )
{
	copyList( L );
}

template <typename T>
List<T>::~List()
{
	releaseList();
}

template <typename T>
List<T>& List<T>::operator=( List& L )
{
	if ( this != &L )
	{
		releaseList();
	}
	copyList( L );

	return *this;
}

template <typename T>
void List<T>::print( ostream& os ) const
{
	int count = 0;
	os << "[";
	for ( Node<T>* next = m_head; next != NULL; next = next->m_link )
	{
		os << next->m_data << (next->m_link == NULL ? "]" : ", ");
		
		if(count % 15 == 0 && count != 0){
			cout << endl;
		}
		
		count++;
	}
}


// PROGRAMMING ASSIGNMENT 1
template <typename T>
bool List<T>::hasCycle()
{
	if(m_head == NULL){
		cout << "ERROR: NULL list for hasCycle()" << endl;
	} else {
	
		Node<T>* slow = m_head;
		Node<T>* fast = m_head->m_link;

		while(fast != NULL && fast->m_link != NULL){

			fast = fast->m_link;

			if(fast == slow){
				return true;
			}
			fast = fast->m_link;
			
			if(fast == slow){
				return true;
			}
			slow = slow->m_link;
		}
		return false;
	}
}

/*
	Goes through the list until the k'th node. Then a pointer will be made and go to the
	end of the list and set the last nodes link to the k'th node.

*/
template <typename T>
Node<T>* List<T>::makeCycle( int K )
{

	Node<T>* Kth = NULL;		// Pointer to node at position 1, 2, 3 ...
	Node<T>* last = m_head;		// Pointer to last node
	int cnt = 0;			// Node counter
	
	// Stop on the last node, if the list is not empty
	while(last != NULL && last->m_link != NULL){
	
		// If cnt equals k, set the Kth pointer
		if(++cnt == K){
			Kth = last;
		}
		
		last = last->m_link;
	}

	last->m_link = Kth;		// Make the cycle
	return last;			// Return the last node on the list before
}

/* 
	Used to remove the current cycle from the list. Node<T>* last is where the 
	original end of the list was before a cycle was created
*/
template <typename T>
void List<T>::removeCycle(Node<T>* last)
{
	last->m_link = NULL;
}

/*
	Goes through the list checking a signle node against the rest of the list.  If
	another node is found to have the same data as the current node, then that node
	will be removed from the linked list.
*/
template <typename T>
void List<T>::unique()
{
	
	T data;
	Node<T>* ptr = m_head;			// Pointer for going throught the list and checking
									// against the other nodes for uniqueness.

	while(ptr != NULL && ptr->m_link != NULL){
	
		data = ptr->m_data;		// Set the data to the current node's data

		/* Traverse the list and check if any of the nodes data is equal to the
		current node.  If so, then we delete the node. */
		for(Node<T>* next = ptr; next != NULL && next->m_link != NULL;
			next = next->m_link){
			
			if(data == next->m_link->m_data){
				removeNode( next);
			}
		}
	
		ptr = ptr->m_link;
	}
}

/*
	Goes through the list and removes any consecutive duplicate nodes. Will cycle through each
	node in the list and once it dectects a consecutive data value it will remove the node
	from the list and check for another consecutive value. If none are found, then it will
	resume traveling through the list.
*/
template <typename T>
void List<T>::removeDuplicates()
{

	T data;
	Node<T>* ptr = m_head;

	while(ptr != NULL && ptr->m_link != NULL){
	
		data = ptr->m_data;

		while(ptr->m_link->m_data == data){
		
			removeNode( ptr);
		}
		ptr = ptr->m_link;
	}
}

/*
	Takes the current list and copys it into a new list in reverse order.  This function
	will use an interative solution to reverse the linked list. It will travel through
	the list and reverse it in place.
*/
template <typename T>
void List<T>::reverse()
{

	Node<T>* current = m_head;
	Node<T>* temp;
	Node<T>* previous = NULL;

	while( current != NULL){

		temp = current->m_link;
		current->m_link = previous;
		previous = current;
		current = temp;
	}

	m_head = previous;
}

/*
	Takes the current list and copys it into a new list in reverse order.  This function
	will use an recursive solution to reverse the linked list. It will call the recurse
	function to complete the in place reverse recursivly.
*/
template <typename T>
void List<T>::recursiveReverse()
{
	m_head = recurse( m_head, NULL);
}

/*
	This function retrieves the element at the Kth index.  If K happens to be negative
	then we look from the back of the list.
*/
template <typename T>
T List<T>::getKth( int K )
{
	int count = 1;
	Node<T>* ptr = m_head;
	Node<T>* element = NULL;

	while(ptr != NULL && ptr->m_link != NULL) {

		ptr = ptr->m_link;
		count++;
	}
		
	if( m_head == NULL) {
		
		cout << "Error: cannot search through a NULL list." << endl;
		return 0;
	} else if( K == 0) {
		
		cout << "Error: no such element with an index of 0" << endl;
		return 0;
	} else if( K > count) {

		cout << "Error: K is larger than the current list." << endl;
		return 0;
	} else if( K > 0) {

		int index = 1;

		ptr = m_head;

		while( index < K) {
	
			ptr = ptr->m_link;
			index++;
		}

		element = ptr;
	} else if( K < 0) {

		int index = count;
		ptr = m_head;

		while( K + index != 0) {

			ptr = ptr->m_link;

			index--;
		}

		element = ptr;
	}

	return element->m_data;

}

/*
	This function detects if the current list is sorted. It will travese the entire list
	checking against each node to see if a previous node is greater than its next node.
	If a previous node is greater, then it will return false.
*/
template <typename T>
bool List<T>::isSorted()
{


	for(Node<T>* next = m_head; next != NULL && next->m_link != NULL;
		 next = next->m_link){
	
		if(next->m_data > next->m_link->m_data){
			return false;
		}
	}
	
	return true;
}

/*
	Function used to sort the current linked list. We will use a simple insertion sort
	for the function. While the not list is not currently sorted, we will travel through
	and check for out of placed values.
*/
template <typename T>
void List<T>::sort()
{

	Node<T>* current = m_head;
	T tempData;

	if( current != NULL){

		while( !isSorted()){

			if( current->m_link != NULL && current->m_data > current->m_link->m_data){

				tempData = current->m_data;
				current->m_data = current->m_link->m_data;
				current->m_link->m_data = tempData;
			}
			
			if( current->m_link != NULL){
				
				current = current->m_link;
			} else {
		
				current = m_head;
			}
		}

	} else {

		cout << "Error: tried to sort an empty list." << endl;
	}
}

/*
	This function is used to merge two linked lists together. It will put them 
	together in a sorted way.
*/
template <typename T>
void List<T>::mergeSort( List<T>& L2 )
{
	
	
	Node<T>* list1 = m_head;
	Node<T>* list2 = L2.m_head;

	while( list2 != NULL && list2->m_link != NULL) {

		if(list1->m_data <= list2->m_data && list1->m_link != NULL) {

			list1 = list1->m_link;
			
		} else if(list1->m_data > list2->m_data) {
		
			Node<T>* temp = new Node<T>( list2->m_data);

			if(list1 == m_head) {
				
				temp->m_link = m_head;
				m_head = temp;
			} else {
			
				temp->m_link = list1;
				
			}

			list2 = list2->m_link;
		}
	}
	L2.releaseList();
}


// LIST PRIVATE MEMBER FUNCTIONS


/*
	This function is used to remove a single node from the list.  The arg ptr
	will be the previous node from the target to remove. After removing the target node 
	from the list, we will then delete it.
*/
template <typename T>
void List<T>::removeNode( Node<T>* ptr)
{


	if(ptr == NULL || ptr->m_link == NULL) {
	
		cout << "Error: NULL node" << endl;
	} else {

		Node<T>* target = ptr->m_link;

		ptr->m_link = target->m_link;

		delete target;
	}
}

template <typename T>
void List<T>::releaseList()
{
	while ( m_head != NULL )
	{
		Node<T>* doomed = m_head;
		m_head = m_head->m_link;
		delete  doomed;
	}
}

template <typename T>
void List<T>::copyList( List& L )
{
	m_head = NULL;
	Node<T>* tail = NULL;

	if ( L.m_head != NULL )
	{
		m_head = tail = new Node<T>( L.m_head->m_data );
		for ( Node<T>* next = L.m_head->m_link; next != NULL; next = next->m_link )
		{
			tail = tail->m_link = new Node<T>( next->m_data );
		}
	}
}

/*
	Main function for the recursiveReverse function. Used to travel through the list
	and reverse the list in place
*/
template <typename T>
Node<T>* List<T>::recurse( Node<T>* ptr, Node<T>* previous)
{

	Node<T>* temp;

	if( ptr->m_link == NULL) {

		ptr->m_link = previous;
		return ptr;
	} else {
		
		temp = recurse( ptr->m_link, ptr);
		ptr->m_link = previous;
		return temp;
	}

}

// FORCE TEMPLATE CREATION

template class Node<int>;
template class List<int>;
template class Node<double>;
template class List<double>;
template class Node<string>;
template class List<string>;
