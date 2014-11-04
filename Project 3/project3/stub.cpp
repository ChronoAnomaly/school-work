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

#include "driver.h"

using namespace std;

int g_tracks = 0;

/****************************************************************
 * Part I. Managing the storage allocation table
 ****************************************************************/

void FormatDisk( int tracks)
{
	
}

int Allocate( int &L, int S)
{
	if( S < 1 || S > g_tracks) {
		return 1;
	}
}

int Release( int, int )
	{
	return 0;
	}

/****************************************************************
 * Part II. Managing the file allocation table
 ****************************************************************/

void Table()
	{
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
