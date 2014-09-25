/*
  Brett Worley
  CS 3100 - 01
  8/28/14 
*/

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
		
		T	m_data;
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
		/* Dectects if the list has a cycle */
		bool hasCycle();
		/* Creates a cycle withen the list, linking the last node with the node
		being passed. Returns a pointer to the the last node in the list before making
		a cycle, this node will be used to remove the cycle later. */
		Node<T>* makeCycle( int );
		/* Removes the cycle within the list, allowing the list to be deleted */
		void removeCycle( Node<T>* );
		/* Makes the current list unique by removing any duplicates from the list */
		void unique();
		/* Removes any consecutive duplicate node in the current list */
		void removeDuplicates();
		/* Reverses the list current list in place */
		void reverse();
		void recursiveReverse();
		/* Gets the data from the Kth node in the list: if it exits */
		T getKth( int );
		/* Checks if the current list is sorted */
		bool isSorted();
		/* Sorts the current list */
		void sort();
		/* Merges two lists together */
		void mergeSort( List<T>& );
		
	protected:
		Node<T>*	m_head;
		
	private:
		/* Used to remove a single node from the list. The passed node must be the
		previous node of the targeted node. */
		void removeNode( Node<T>*);
		void releaseList();
		void copyList( List& );
		/* Used by the recursiveReverse function to reverse the list in place */
		Node<T>* recurse( Node<T>* current, Node<T>* previous);
		
};

#endif
