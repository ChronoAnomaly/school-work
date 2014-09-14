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
	return true;
}

/*
	Goes through the list until the k'th node. Then a pointer will be made and go to the
	end of the list and set the last nodes link to the k'th node.

*/
template <typename T>
void List<T>::makeCycle( int K )
{
	Node<T>* next = m_head;
	
	for(int i = 1; next != NULL && i < K; i++){
		
		next = next->m_link;
	}
	
	Node<T>* ptr = next->m_link;

	while(ptr != NULL && ptr->m_link != NULL){
	
		ptr = ptr->m_link;
	}

	ptr->m_link = next;
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
	Node<T>* ptr = m_head;
cout << "entering unique()" << endl;
	if(m_head != NULL){
	
cout << "inside if" << endl;
		data = m_head->m_data;

		while(ptr != NULL) {
cout << "inside while" << endl;
			for(Node<T>* next = m_head; next != NULL; next = next->m_link) {
cout << "inside for ---" <<" ptr: "<< ptr << " data: " << data << " next: " << next << endl;
				if(data == next->m_link->m_data && next != ptr){
	
					removeNode( next);
				}
			}
	
			ptr = ptr->m_link;
			data = ptr->m_data;
		}
	} else {
	
		cout << "Error: NULL list." << endl;
	}

}

template <typename T>
void List<T>::removeDuplicates()
{
}

/*
	Takes the current list and copys it into a new list in reverse order.  This function
	will use an interative solution to reverse the linked list.
*/
template <typename T>
void List<T>::reverse()
{
}

/*
	Takes the current list and copys it into a new list in reverse order.  This function
	will use an recursive solution to reverse the linked list.
*/
template <typename T>
void List<T>::recursiveReverse()
{
}

template <typename T>
T List<T>::getKth( int K )
{
	return 0;
}

template <typename T>
bool List<T>::isSorted()
{
	return true;
}

template <typename T>
void List<T>::sort()
{
}

template <typename T>
void List<T>::mergeSort( List<T>& L2 )
{
}


template <typename T>
void List<T>::addFront( T item)
{
	Node<T>* element = new Node<T>( item);

	element->m_link = m_head;

	m_head = element;

}

template <typename T>
void List<T>::addBack( T item)
{
	Node<T>* element = new Node<T>( item);


	for( Node<T>* next = m_head; next != NULL; next = next->m_link){
		
		if( next->m_link == NULL){
			
			next->m_link = element;
		}
	}

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

// FORCE TEMPLATE CREATION

template class Node<int>;
template class List<int>;
template class Node<double>;
template class List<double>;
template class Node<string>;
template class List<string>;
