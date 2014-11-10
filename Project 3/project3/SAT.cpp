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

bitset<SAT::bitsPerTrack> SAT::sat_table;
int SAT::loaded_track = -1;

/*
 *	init: used to initalize the SAT sat_table.
 */
int SAT::init( int tracks)
{
	SAT::sat_table.reset();
	int sat_track_space = std::ceil( (double) tracks / (double) SAT::bitsPerTrack);

	// write out the empty SAT table to the disk
	for( int i = 0; i < sat_track_space; i++) {
		assert( WriteDisk( (unsigned char*) &SAT::sat_table, i) == 0);
	}
	
	int sat_overflow = 0;
	if( sat_track_space > SAT::bitsPerTrack) {
		sat_overflow = sat_track_space / SAT::bitsPerTrack;
	}

	for( int i = 0; i <= sat_overflow; i++) {
	
		for( int j = 0; j < sat_track_space && j < SAT::bitsPerTrack; j++) {
			SAT::sat_table[j] = 1;
		}

		assert( WriteDisk( (unsigned char*) &SAT::sat_table, i) == 0 );
		SAT::sat_table.reset();
	}
	
	return sat_track_space;
}

/*
 *	getBit: is used to access the bit at the given index.
 *	returns: the bit at index
 */
int SAT::getBit( int index)
{
	SAT::load( index);
	int pos = index % SAT::bitsPerTrack;

	return SAT::sat_table[pos];
}

/*
 *	setBit: is used to access and change the value of the bit at the index given.
 */
void SAT::setBit( int index, int bit)
{
	SAT::load( index);
	int pos = index % SAT::bitsPerTrack;

	SAT::sat_table[pos] = bit;
	int calc_track = index / SAT::bitsPerTrack;
	assert( WriteDisk( (unsigned char*) &SAT::sat_table, calc_track) == 0);
}

/*
 *	load: used to check which track of the disk is currently loaded into the
 *	SAT table and load a track if needed.
 */
void SAT::load( int index)
{
	int calc_track = index / SAT::bitsPerTrack;
	if( SAT::loaded_track != calc_track) {

		assert( ReadDisk( (unsigned char*) &SAT::sat_table, calc_track) == 0);
		SAT::loaded_track = calc_track;
	}
}

/*
 *	findSpace: used to find a continuous block of free space on the disk.
 *	returns: -1 if no space is found. A valid index if space is found.
 */
int SAT::findSpace( int tracks, int size)
{
	int address = -1;
	
	int disk_size = tracks * SAT::bitsPerTrack;

	for( int i = 0; i < disk_size; i++) {
		SAT::load( i);
		int ptr = i;
		int locationSize = 0;

		while( SAT::getBit( i) == 0) {
			locationSize++;
			
			if( locationSize == size) {
				address = ptr;
				break;
			}
		}
		
		if( address != -1) {
			return address;
		}
	}
	
	return address;
	
}
