/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

#ifndef _FAT_

#define _FAT_

#include <bitset>

class FAT {

	public:
		FAT();
		~FAT():
		int operator[] ( int );

	private:

}

class element {

	public:
		element()
		{ name = "null"; size = -1; address = -1; }
		string name;
		unsigned short int size;
		unsigned short int address;
};

class node {

	public:
		element files[8];
}
#endif
