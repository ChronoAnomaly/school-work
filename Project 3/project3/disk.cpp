#include <iostream>
#include <cstdlib>

#include "disk.h"

using namespace std;

DISK::DISK(int tracks, int size)
{
	tracksize = size;
	numtrack = tracks;
	if (size < 1)
	{
		cerr << "Invalid track size (" << size << ") \n";
		exit(1);
	}
	if (tracks < 1)
	{
		cerr << "Invalid number of tracks (" << tracks << ") \n";
		exit(1);
	} 
	if ((disk = new unsigned char*[tracks]) == 0)
	{
		cerr << "The disk is too big -- define a smaller size\n";
		exit(1);
	}
	for(int i=0 ; i<tracks ; i++)
	{
		disk[i] = 0;
	}
	headtravel = 0;
	headposition = 0;
	numreads = 0;
	numwrites = 0;
}

DISK::~DISK()
{
	for (int i = 0; i < numtrack; i++)
	    if(disk[i] != 0)
		delete disk[i];
	delete disk;
}

// READ FROM SIMULATED DISK
RW_Status DISK::ReadDisk (unsigned char *buffer, int address)
{
 	if (address < 0 || address >= numtrack)
		return Failure; 
	if (disk[address] == 0)
	{
		for (int i = 0; i < tracksize; i++)
			buffer[i] = 0;
	}
	else
	{
		for (int i=0; i < tracksize; i++)
			buffer[i] = disk[address][i];
	}
 	numreads++;
 	headtravel += (headposition < address ? address - headposition : headposition - address);
 	headposition = address;
 	return OK;
}

// DUMMY WRITE TO SIMULATED DISK
RW_Status DISK::MoveHeads(int address)
{
 	if (address < 0 || address >= numtrack)
		return Failure; 
 	numwrites++;
 	headtravel += (headposition < address ? address - headposition : headposition - address);
 	headposition = address;
	return OK;
}

// WRITE TO SIMULATED DISK
RW_Status DISK::WriteDisk (unsigned char *buffer, int address)
{
 	if (address < 0 || address >= numtrack)
		return Failure;
	if (disk[address] == 0)
	{
		if ((disk[address] = new unsigned char[tracksize]) == 0)
		{
			cerr << "Disk Overflow -- use a smaller disk size\n";
			exit(1);
		}
	}
 	for (int i = 0; i < tracksize; i++)
		disk[address][i] = buffer[i];
 	numwrites++;
 	headtravel += (headposition < address ? address - headposition : headposition - address);
 	headposition = address;
 	return OK;
}

	// DISK STATISTICS

void DISK::DiskStatistics( int &reads, int &writes, int &travel)
	{
	reads = numreads;
	writes = numwrites;
	travel = headtravel;
	}
