/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */

/****************************************************************
 * FILE
 *	stub.cpp - driver test stub for project 3
 *
 ****************************************************************
 */

#include <iostream>
#include <cassert>
#include <cstring>
#include <bitset>
#include <string>
#include <iomanip>

#include "driver.h"
#include "SAT.h"
#include "FAT.h"

using namespace std;

int g_tracks = 0;
int g_FAT_address = -1;		// location for the begining of the FAT table on the disk
int g_reserved_end = -1;	/* address for the end of resricted space on the disk
				 * (SAT and FAT tables)
				 */

/****************************************************************
 * Part I. Managing the storage allocation table
 ****************************************************************/

void FormatDisk( int tracks)
{
	SAT sTable;
	FAT fTable;
	g_FAT_address = sTable.init( tracks);
	g_tracks = tracks;
	fTable.table_size = tracks / 7;
	g_reserved_end = g_FAT_address + fTable.table_size;

	for( int i = 0; i < fTable.table_size; i++) {
		sTable.setBit( g_FAT_address + i, 1);
	}
	
	
}

int Allocate( int &L, int S)
{
	SAT sTable;

	if( S < 1 || S > g_tracks - 1) {
		return 1;
	}
	
	int address = sTable.findSpace( g_tracks, S);
	int* ptr = &L;

	if( address == -1) {
		return 2;
	} else {
		*ptr = address;
		for( int i = 0; i < S; i++) {
			sTable.setBit( address + i, 1);
		}
		return 0;
	}

}

int Release( int address, int size)
{
	SAT sTable;
	int index = address;

	if( size < 1 || size > g_tracks - 1) {
		return 1;
	} else if( address < 0 || address > g_tracks - 1) {
		return 3;
	} else {

		for( int i = 0; i < size; i++) {
			sTable.setBit( index, 0);
			index++;
		}
		return 0;
	}
}

/****************************************************************
 * Part II. Managing the file allocation table
 ****************************************************************/
/*
 *	Table: used to print out the current allocation table of the disk.
 *	Format - Allocation table as the table header, then bits 0 - 64 on the top.
 *	Multiples of 64 bits are on the left side of the table. This allows for easy
 *	understanding of the index location for an item within the table.
 */
void Table()
{
	SAT sTable;
	string title = "Allocation Table";
	const int table_width = 64;
	const int disk_size = g_tracks * ( TRACKSIZE * 8);
	int ptr = 0;

	cout << setw( 46) << title << endl;

	// second table header

	cout << setw( 8) << ' ';

	for (int i = 1; i < 7; i++) {
		cout << setw( 10) << i;
	}
	
	cout << endl;
	cout << setw( 7) << ' ';
	
	// third table header
	for( int i = 0; i < table_width; i++) {
		cout << i % 10;
	}
	
	cout << endl;
	
	// main part of the allocation table
	for( int i = 0; ptr < disk_size; i++) {
		cout << setfill( '0') << setw( 5) << i * table_width;
		cout << "  ";
		for( int j = 0; j < table_width; j++, ptr++) {
			cout << sTable.getBit( ptr);
		}
		cout << endl;
	}
}

void Restart( int totalTracks)
{

}
	// File Allocation Table Routines

int CreateFile( char* fileName, int fileSize, int& fileAddress)
{
	FAT fTable;
	int found = -1;
	string name = fileName;

	for( int i = g_FAT_address; i < g_reserved_end; i++) {
		assert( ReadDisk( (unsigned char*) &FAT::fat_table, i) == 0);
		found = fTable.exists( name);
		
		if( found != -1) {
			return 4;
		}
	}
	
	fTable.add( name, fileAddress, fileSize, g_FAT_address);
	Allocate( fileAddress, fileSize);

	return 0;
}

int DestroyFile( char* fileName)
{
	FAT fTable;
	string name = fileName;
	int address = fTable.exists( name);
	element item =  fTable.search( name);
	if( address == -1) {
		return 4;
	} else {
		fTable.remove( name);
		return Release( address, item.size);
	}
}

int FindFile( char* fileName, int &fileSize, int &fileAddress )
{
return 0;
}

void ListDirectory()
{
}
