#ifndef _DRIVER_

#define _DRIVER_

/****************************************************************
 * FILE
 *	driver.h - header file containing prototypes for the
 *		   disk simulation
 * DESCRIPTION
 *	These are the declarations for the file system interface.
 * NOTES
 *	*** DO NOT MODIFY THIS FILE ***
 ****************************************************************
 */

#define TRACKSIZE	128	

/****************************************************************
 * Part I. Managing the storage allocation table
 ****************************************************************/

void FormatDisk( int );
int Allocate( int&, int );
int Release( int, int );
void Table();

/****************************************************************
 * Part II. Managing the file allocation table
 ****************************************************************/

int CreateFile( char* FileName, int FileSize, int &Address );
int DestroyFile( char* FileName );
int FindFile( char* FileName, int &FileSize, int &Address );
void ListDirectory();

/****************************************************************
 * Disk access routines in "driver.cpp"
 ****************************************************************/

int ReadDisk(unsigned char *buffer, int tracks);
int WriteDisk(unsigned char *buffer, int tracks);

#endif
