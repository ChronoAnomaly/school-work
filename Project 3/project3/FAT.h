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
		FAT( FAT& );
		~FAT():
		int operator[] ( int );

	private:
		const int bitsPerTrack = 1024;
		static bitset<bitsPerTrack> buf;

}

#endif
