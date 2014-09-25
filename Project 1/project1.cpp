/*
  Brett Worley
  CS 3100 - 01
  8/28/14 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <time.h>

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

		cout << "L.makeCycle(4)" << endl;

		Node<int>* last = L.makeCycle(4);

		cout << boolalpha << "has cycle: " << L.hasCycle() << endl;
		
		L.removeCycle(last);

		cout << "after remove cycle: " << L << endl;

		cout << boolalpha << "has cycle: " << L.hasCycle() << endl;

		L.reverse();

		cout << "reversed List: " << L << endl;

		L.recursiveReverse();

		cout << "reversed again List: " << L << endl;
	
		cout << boolalpha << "isSorted() = " << L.isSorted() << endl;	

		cout << endl;
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

		L.unique();

		cout << "List unique(): " << L << endl;
	
		cout << endl;
	}

	// Add additional test fragments
	
	// Test Fragment 3
	{
		int numItems = 12;
		double items[] = {2.56, 4.87, 665.48, 2.56, 1897.564, 2258.5546, 2258.5546
				, 2258.5546, 176.5, 17.0, 17.1, 17.66548};
		
		List<double> L( numItems, items);
	
		cout << "List: " << L << endl;

		cout << boolalpha << "isSorted() = " << L.isSorted() << endl;

		L.sort();

		cout << "Sorted List: " << L << endl;



		cout << endl;
	}

	// Test Fragment 4
	{
		int numItems = 10;
		string items[] = {"dog", "cat", "cat", "hat dog", "counting", "random strings"
			, "hatter", "using strings", "testing", "final"};
	
		List<string> L( numItems, items);

		cout << "List: " << L << endl;

		cout << boolalpha << "isSorted() = " << L.isSorted() << endl;

		L.sort();

		cout << "Sorted List: " << L << endl;


		cout << endl;
	}

	// Test Fragment 5
	{
	
		srand(time(NULL));
	
		int numItems;
		numItems = rand() % 500;
		
		int items[numItems];

		for(int i = 0; i < numItems; i++){
			
			items[i] = rand() % 5000;
		} 
		
		List<int> L( numItems, items);
		
			
		cout << "List: " << L << endl;

		L.sort();

		cout << "Sorted list: " << L << endl;

		L.removeDuplicates();

		cout << "list after removeDuplicates(): " << L << endl;
		

		cout << endl;
	}


	// Test Fragment 6
	{
		int numItems = 25;

		int items[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17
				, 18, 19, 20, 21, 22, 23, 24, 25};

		List<int> L( numItems, items);

		cout << "List: " << L << endl;

		L.recursiveReverse();
	
		cout << "recursiveReverse(): " << L << endl;

		L.reverse();

		cout << "reverse(): " << L << endl;

		cout << endl;
	}

	// Test Fragment 7
	{
		
		int numItems = 23;

		int items[] = {2, 2, 2, 3, 3, 2, 3, 4, 4, 5, 17, 8, 9, 17, 23, 23, 23,
				50, 50, 50, 50, 51, 60};

		List<int> L( numItems, items);

		cout << "List: " << L << endl;
	
		L.removeDuplicates();

		cout << "List duplicates(): " << L << endl;

		cout << endl;
	}

}


