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
	os << "[";
	for ( Node<T>* next = m_head; next != NULL; next = next->m_link )
	{
		os << next->m_data << (next->m_link == NULL ? "]" : ", ");
	}
}


// PROGRAMMING ASSIGNMENT 1
template <typename T>
bool List<T>::hasCycle()
{
	return true;
}

template <typename T>
void List<T>::makeCycle( int K )
{
}

template <typename T>
void List<T>::unique()
{
}

template <typename T>
void List<T>::removeDuplicates()
{
}

template <typename T>
void List<T>::reverse()
{
}

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
void List<T>:: mergeSort( List<T>& L2 )
{
}

// LIST PRIVATE MEMBER FUNCTIONS

template <typename T>
void List<T>::releaseList()
{
	while ( m_head != NULL )
	{
		Node<T>* doomed = m_head;
		m_head = m_head->m_link;
		delete [] doomed;
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

