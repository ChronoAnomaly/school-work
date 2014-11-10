/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

#ifndef _FAT_

#define _FAT_

#include <string>

using namespace std;

class element {

	public:
		element()
		{ name = "null"; size = -1; address = -1; }
		string name;
		short int size;
		short int address;
};

class node {

	public:
		node() { elements = 0; }
		
		unsigned short int elements;
		element files[7];
};

class FAT {

	public:
		element search( string fileName);
		void add( string fileName, int& address, int size, int startTrack);
		void remove(string fileName);
		void display();
		int exists( string fileName);
		static int table_size;
		static node fat_table;
		static int loaded_track;
};
#endif
