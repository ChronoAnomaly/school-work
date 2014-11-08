/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

#ifndef _SAT_

#define _SAT_

#include "driver.h"
#include <bitset>

using namespace std;

class SAT {

	public:
		SAT() { };
		~SAT() { };
		void init(int tracks);
		int getBit( int index);
		void setBit( int index, int bit);
		int findSpace( int size) const;

	private:
		//void makeTable( int tracks);
		static const int bitsPerTrack = TRACKSIZE * 8;
		static bitset<bitsPerTrack> sat_table;
		//static bool exists;
		static int loaded_track;

};

#endif
