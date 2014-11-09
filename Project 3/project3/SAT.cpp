/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

#include "SAT.h"
#include "driver.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

//const int SAT::bitsPerTrack = 1024;
bitset<SAT::bitsPerTrack> SAT::sat_table;
//bool SAT::exists = false;
int SAT::loaded_track = -1;
//static int sdebug;
//static int gdebug;
/*
 *	init: used to initalize the SAT sat_table.
 */
void SAT::init( int tracks)
{
	SAT::sat_table.reset();
	double tmp = (double) tracks / (double) SAT::bitsPerTrack;
	int sat_track_space = std::ceil( (double) tracks / (double) SAT::bitsPerTrack);
//cout << endl << "sat track space is " << sat_track_space << endl;

//cout << endl << "ceil results " << tmp << endl;
//cout << endl << "tracks is " << tracks << endl;
	// write out the empty SAT table to the disk
	for( int i = 0; i < sat_track_space; i++) {
		assert( WriteDisk( (unsigned char*) &SAT::sat_table, i) == 0);
	}
	
	int sat_overflow = 0;
	if( sat_track_space > SAT::bitsPerTrack) {
		sat_overflow = sat_track_space / SAT::bitsPerTrack;
	}

	// determine which bits are allocated for the inital SAT table
	for( int i = 0; i <= sat_overflow; i++) {
	//std::cout << "inside sat overflow loop " << sat_overflow << std::endl;
	//cout << "i = " << i << " sat table = " << sat_table << endl;
	
		for( int j = 0; j < sat_track_space && j < SAT::bitsPerTrack; j++) {
			SAT::sat_table[j] = 1;
		}
		cout << "i = " << i << " sat table = " << sat_table << endl;

		assert( WriteDisk( (unsigned char*) &SAT::sat_table, i) == 0 );
		SAT::sat_table.reset();
	}

}

/*
 *	getBit: is used to access the bit at the given index.
 *	returns: the bit at index
 */
int SAT::getBit( int index)
{
	int calc_track = index / SAT::bitsPerTrack;
	if( SAT::loaded_track != calc_track) {
//cout << endl << "debug in get bit is " << gdebug << endl; gdebug++;
//cout << endl << "index is " << index << " SAT::bitsPerTrack is " << SAT::bitsPerTrack << endl;
//cout << endl << "loaded track is " << SAT::loaded_track << " calc track is " << calc_track << endl;
		assert( ReadDisk( (unsigned char*) &SAT::sat_table, calc_track) == 0);
		SAT::loaded_track = calc_track;
	}
	int pos = index % SAT::bitsPerTrack;

	return SAT::sat_table[pos];
}

/*
 *	setBit: is used to access and change the value of the bit at the index given.
 */
void SAT::setBit( int index, int bit)
{
	int calc_track = index / SAT::bitsPerTrack;
	if( SAT::loaded_track != calc_track) {

//cout << endl << "debug in set bit is " << sdebug << endl; sdebug++;
		assert( ReadDisk( (unsigned char*) &SAT::sat_table, calc_track) == 0);
		SAT::loaded_track = calc_track;
	}
	int pos = index % SAT::bitsPerTrack;

	SAT::sat_table[pos] = bit;
	assert( WriteDisk( (unsigned char*) &SAT::sat_table, calc_track) == 0);
}

int SAT::findSpace( int size) const
{
	int address = -1;
	
	
}
