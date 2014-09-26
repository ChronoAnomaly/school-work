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

		// insert code to process command
	}
	while( cmd != 'Q');
}
