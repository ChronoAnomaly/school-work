/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

#include "SAT.h"

using namespace std;


bitset<SAT::bitsPerTrack> buf;
bool exists = false;

void SAT::init()
{
	if( !exists) {
		makeTable();
	}
}

int SAT::operator[] ( int pos) const
{
	return buf[pos];

}


void SAT::makeTable()
{
	exists = true;
}
