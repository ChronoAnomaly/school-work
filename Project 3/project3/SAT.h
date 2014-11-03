/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

#ifndef _SAT_

#define _SAT_

#include <bitset>

using namespace std;

class SAT {

	public:
		SAT();
		~SAT();
		int operator[] ( int ) const;
		void init();

	private:
		void makeTable();
		static const int bitsPerTrack = 1024;
		static bitset<bitsPerTrack> buf;
		static bool exists;

};

#endif
