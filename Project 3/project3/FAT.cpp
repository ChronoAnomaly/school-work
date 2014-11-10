/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */
#include <cassert>
#include <string>
#include "driver.h"
#include "FAT.h"
#include "SAT.h"

using namespace std;

int FAT::table_size = -1;
int FAT::loaded_track = -1;
node FAT::fat_table;

element FAT::search( string fileName)
{
	
}

void FAT::add( string fileName, int& address, int size, int startTrack)
{
	int const endTrack = startTrack + table_size;

	for( int i = startTrack; i < endTrack; i++) {
		assert( ReadDisk( (unsigned char*) &FAT::fat_table, i) == 0);

		if( FAT::fat_table.elements < 7) {
			if( FAT::fat_table.files[0].size == -1) {
				FAT::fat_table.files[0].name = fileName;
				FAT::fat_table.files[0].size = size;
				FAT::fat_table.files[0].address = i;
				int* ptr = &address;
				*ptr = i;
			} else if( FAT::fat_table.files[1].size == -1) {
				FAT::fat_table.files[1].name = fileName;
				FAT::fat_table.files[1].size = size;
				FAT::fat_table.files[1].address = i;
				int* ptr = &address;
				*ptr = i;
			} else if( FAT::fat_table.files[2].size == -1) {
				FAT::fat_table.files[2].name = fileName;
				FAT::fat_table.files[2].size = size;
				FAT::fat_table.files[2].address = i;
				int* ptr = &address;
				*ptr = i;
			} else if( FAT::fat_table.files[3].size == -1) {
				FAT::fat_table.files[3].name = fileName;
				FAT::fat_table.files[3].size = size;
				FAT::fat_table.files[3].address = i;
				int* ptr = &address;
				*ptr = i;
			} else if( FAT::fat_table.files[4].size == -1) {
				FAT::fat_table.files[4].name = fileName;
				FAT::fat_table.files[4].size = size;
				FAT::fat_table.files[4].address = i;
				int* ptr = &address;
				*ptr = i;
			} else if( FAT::fat_table.files[5].size == -1) {
				FAT::fat_table.files[5].name = fileName;
				FAT::fat_table.files[5].size = size;
				FAT::fat_table.files[5].address = i;
				int* ptr = &address;
				*ptr = i;
			} else if( FAT::fat_table.files[6].size == -1) {
				FAT::fat_table.files[6].name = fileName;
				FAT::fat_table.files[6].size = size;
				FAT::fat_table.files[6].address = i;
				int* ptr = &address;
				*ptr = i;
			}
			break;
		}
	}
}

void FAT::remove( string fileName)
{

}

void FAT::display()
{

}

int FAT::exists( string fileName)
{
	
}

