/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

#ifndef _SAT_

#define _SAT_

#include <bitset>


class SAT {

	public:
		SAT();
		SAT( SAT& );
		~SAT();
		int operator[] ( int );

	private:
		const int bitsPerTrack = 1024;
		static bitset<bitsPerTrack> buf;
	

}

#endif
