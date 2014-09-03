/*
  Brett Worley
  CS 3100 - 01
  8/28/14 */

#ifndef _LIST_

#define _LIST_

#include <iostream>

using namespace std;

// CLASS DECLARATIONS
template <typename T>
class Node {
	private:
		Node( T );
		Node( T, Node* );
		
		T 		m_data;
		Node*	m_link;
		
		template <typename sT> friend class List;
};

template <typename T>
class List {
	public:
		List();
		List( int, const T [] );
		List( List& );
		~List();
		List& operator=( List& );
		void print( ostream& = cout ) const;
		
		friend ostream& operator<<( ostream& os, const List<T>& L )
		{
			L.print( os );
			return os;
		}
		
		// Programming Assignment 1
		bool hasCycle();
		void makeCycle( int );
		void unique();
		void removeDuplicates();
		void reverse();
		void recursiveReverse();
		T getKth( int );
		bool isSorted();
		void sort();
		void mergeSort( List<T>& );
		
	protected:
		Node<T>*	m_head;
		
	private:
		void releaseList();
		void copyList( List& );
		
};

#endif
