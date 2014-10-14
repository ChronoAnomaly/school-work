/*******************************************************************
 * FILE
 *	hw1.cpp - A program to test the stack and queue implementations
 * DESCRIPTION
 *	This program allows you to manipulate two stacks and two
 *	queues.
 * USAGE
 *	hw1
 *		Commands are entered to standard input
 * COMMANDS
 *	Q
 *		Quit
 *	I t n k
 *		Insert integer k into an object of type t=Q (Queue)
 *		or t=S (Stack).  Object number n=0 or n=1 identifies
 *		the particular stack or queue.
 *	R t n
 *		Remove an integer from object type t, object number
 *		n.
 *	P t n
 *		Print the contents of object type t, object number
 *		n.
 *******************************************************************
 */

#include <iostream>

#include "Stack.h"
#include "Queue.h"

using namespace std;

template <typename datastruct, typename keytype> 
void print(datastruct &);

/*******************************************************************
 * FUNCTION
 *	main - the main program
 * PARAMETERS
 *	argc	- the number of command line arguments
 *	argv	- the command line arguments
 *******************************************************************
 */

int main(int argc, char **argv)
	{
	Stack<int> S[2];
	Queue<int> Q[2];

	for( ; ; )
		{
		char cmd, obj;
		int num;
		int key;

		cin >> cmd;
		switch(cmd)
		    {
		    case 'Q':			// Quit
			exit(0);
		    case 'I':			// Insert
			cin >> obj >> num >> key;
			if(num < 0 || num > 1)
			    {
			    cerr << "Structure number must be 0 or 1\n";
			    break;
			    }
			switch(obj)
			    {
			    case 'Q':
				Q[num].Insert(key);
				cerr << "Insert Queue " << num << ": "
					<< key << "\n";
				break;
			    case 'S':
				S[num].Insert(key);
				cerr << "Insert Stack " << num << ": "
					<< key << "\n";
				break;
			    default:
				cerr << "Structure must be Q or S\n";
				break;
			    }
			break;
		    case 'R':			// Remove
			cin >> obj >> num;
			if(num < 0 || num > 1)
			    {
			    cerr << "Structure number must be 0 or 1\n";
			    break;
			    }
			switch(obj)
			    {
			    case 'Q':
				key = Q[num].Remove();
				cerr << "Remove Queue " << num << ": "
					<< key << "\n";
				break;
			    case 'S':
				key = S[num].Remove();
				cerr << "Remove Stack " << num << ": "
					<< key << "\n";
				break;
			    default:
				cerr << "Structure must be Q or S\n";
				break;
			    }
			break;
		    case 'P':			// Print
			cin >> obj >> num;
			if(num < 0 || num > 1)
			    {
			    cerr << "Structure number must be 0 or 1\n";
			    break;
			    }
			switch(obj)
			    {
			    case 'Q':
				cerr << "Print Queue " << num << "\n";
				print< Queue<int>, int >(Q[num]);
				break;
			    case 'S':
				cerr << "Print Stack " << num << "\n";
				print< Stack<int>, int >(S[num]);
				break;
			    default:
				cerr << "Structure must be Q or S\n";
				break;
			    }
			break;
		    }
		}
	}

template <typename datastruct, typename keytype>
void print(datastruct &S)
	{
	datastruct S1;
	while(! S.isEmpty())
		{
		keytype key = S.Remove();
		S1.Insert(key);
		cout << key << " ";
		}
	while(! S1.isEmpty())
		S.Insert(S1.Remove());
	cout << "\n";
	}
