/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

#include "SAT.h"

using namespace std;

//const int SAT::bitsPerTrack = 1024;
bitset<SAT::bitsPerTrack> SAT::buf;
bool SAT::exists = false;


void SAT::init()
{
	if( !SAT::exists) {
		SAT::makeTable();
	}
}

int SAT::operator[] ( int pos) const
{
	return buf[pos];

}


void SAT::makeTable()
{
	SAT::exists = true;
}
