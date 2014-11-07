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
#include <cstring>
#include <bitset>
#include <string>
#include <iomanip>

#include "driver.h"
#include "SAT.h"

using namespace std;

int g_tracks = 0;
int g_FAT_address = -1;

/****************************************************************
 * Part I. Managing the storage allocation table
 ****************************************************************/

void FormatDisk( int tracks)
{
	SAT sTable;
	sTable.init( tracks);
	g_tracks = tracks;
}

int Allocate( int &L, int S)
{
	if( S < 1 || S > g_tracks - 1) {
		return 1;
	}
}

int Release( int address, int size)
{
	
}

/****************************************************************
 * Part II. Managing the file allocation table
 ****************************************************************/

void Table()
{
	SAT sTable;
	string title = "Allocation Table";
	const int table_width = 64;
	const int SAT_size = g_tracks * ( TRACKSIZE * 8);
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
	
	for( int i = 0; ptr < SAT_size; i++, ptr += 64) {
		cout << setfill( '0') << setw( 5) << i * table_width;
		cout << "  ";
		for( int j = 0; j < table_width; j++, ptr++) {
			cout << sTable.getBit( ptr);
		}
		cout << endl;
	}
}

	// File Allocation Table Routines

int CreateFile( char*, int, int & )
	{
	return 0;
	}

int DestroyFile( char* )
	{
	return 0;
	}

int FindFile( char*, int &fileSize, int &track )
	{
	return 0;
	}

void ListDirectory()
	{
	}
