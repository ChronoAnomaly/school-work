#include <iostream>
#include <cctype>
#include "braided.h"

using namespace std;

int main()
{
	braidedTree	bt;
	char 		cmd;

	do
	{
		// read a command
		cin >> cmd;

		// convert to uppercase
		cmd = toupper ( cmd );

		if(cmd == 'N'){
		
			bt.next();

		} else if(cmd == 'P') {
		
			bt.prev();

		} else if(cmd == 'V') {

			cout << "View's current value is : " << bt.value() << endl;;

		} else if(cmd == 'D') {

			bt.display();

		} else if(cmd == 'F') {

			if( bt.isFirst()) {
			
				cout << "View is currently on the smallest node" << endl;
			} else {
			
				cout << "View is not on the smallest node" << endl;
			}

		} else if(cmd == 'L') {

			if( bt.isLast()) {
			
				cout << "View is currently on the largest node" << endl;
			} else {

				cout << "View is not on the largest node" << endl;
			}

		} else if(cmd == 'H') {

			if( bt.isHead()) {
			
				cout << "View is the on the root node" << endl;
			} else {
	
				cout << "View is not on the root node" << endl;
			}

		} else if(cmd == 'E') {

			if( bt.isEmpty()) {

				cout << "The tree is empty" << endl;
			} else {

				cout << "The tree is not empty" << endl;
			}

		} else if(cmd == 'S') {

			int value;
			cin >> value;

			bt.find( value);

		} else if(cmd == '<') {

			cout << "The smallest value is: " << bt.findMin() << endl;

		} else if(cmd == '>') {

			cout << "The largest value is: " << bt.findMax() << endl;

		} else if(cmd == '+') {

			int value;
			cin >> value;

			bt.insert( value);
		} else if(cmd == '-') {

			int value;
			cin >> value;

			bt.remove( value);

		} else if(cmd == 'M') {

			cout << boolalpha << "removeMin() successful: " 
			<< bt.removeMin() << endl;

		} else if(cmd == 'X') {

			cout MM boolalpha << "removeMax() successful: "
			 << bt.removeMax() << endl;

		} else if(cmd != 'Q') {

			cout << "Error: " << cmd << " is not a valid command" << endl;

		}
	}
	while( cmd != 'Q');
}
