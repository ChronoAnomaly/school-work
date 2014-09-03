/*
  Brett Worley
  CS 3100 - 01
  8/28/14 */

#include <iostream>
#include <iomanip>

#include "list.h"

using namespace std;

int main()
{
	// Sample Test Fragment 1
	{
		int numItems = 6;
		int items[] = {1, 3, 5, 7, 8, 10};

		List<int> L( numItems, items );

		cout << "List: " << L << endl;

		L.reverse();

		cout << "reversed List: " << L << endl;

		L.recursiveReverse();

		cout << "reversed again List: " << L << endl;
	}

	// Sample Test Fragment 2
	{
		int numItems = 8;
		int items[] = {5, 2, 5, 9, 9, 10, 12, 12};

		List<int> L( numItems, items );

		cout << "List: " << L << endl;

		cout << boolalpha << "isSorted()= " << L.isSorted() << endl;

		L.sort();

		cout << "Sorted List: " << L << endl;
	}

	// Add additional test fragments

}

