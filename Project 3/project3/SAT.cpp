/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

#include "SAT.h"

using namespace std;

//const int SAT::bitsPerTrack = 1024;
bitset<SAT::bitsPerTrack> SAT::sat_table;
bool SAT::exists = false;

/*
 *	init: used to initalize the SAT sat_table.
 */
void SAT::init()
{
	if( !SAT::exists) {
		SAT::makeTable();
	}
}

/*
 *	getBit: is used to access the bit at the given index.
 *	returns: the bit at index
 */
int SAT::getBit( int index)
{
	return SAT::sat_table[index];
}

/*
 *	setBit: is used to access and change the value of the bit at the index given.
 */
void SAT::setBit( int index, int bit)
{
	sat_table[index] = bit;
}

void SAT::makeTable()
{
	sat_table = 0;
	SAT::exists = true;
}
