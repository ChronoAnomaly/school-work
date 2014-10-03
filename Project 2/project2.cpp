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

			bt.value();

		} else if(cmd == 'D') {

			bt.display();

		} else if(cmd == 'F') {

			bt.isFirst();

		} else if(cmd == 'L') {

			bt.isLast();

		} else if(cmd == 'H') {

			bt.isHead();

		} else if(cmd == 'E') {

			bt.isEmpty();

		} else if(cmd == 'S') {

			int value;
			cin >> value;

			bt.find( value);

		} else if(cmd == '<') {

			bt.findMin();

		} else if(cmd == '>') {

			bt.findMax();

		} else if(cmd == '+') {

			int value;
			cin >> value;

			bt.insert( value);
		} else if(cmd == '-') {

			int value;
			cin >> value;

			bt.remove( value);

		} else if(cmd == 'M') {

			bt.removeMin();

		} else if(cmd == 'X') {

			bt.removeMax();

		} 
	}
	while( cmd != 'Q');
}
