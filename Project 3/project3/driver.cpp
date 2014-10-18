/****************************************************************
 * FILE
 *	driver.h - header file containing prototypes for project 2
 * DESCRIPTION
 *	These are the declarations for the file system interface.
 * NOTES
 *	*** DO NOT MODIFY THIS FILE ***
 ****************************************************************
 */

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

#include "driver.h"
#include "disk.h"

using namespace std;

static DISK *disk;
static int totalTracks = 0;

static void TestInput(char *, int), TestOutput(char *, int), TestDummy(char *, int);
static void DoRestOfTest(int);
static void DoFormat(), DoRestart(), DoAllocate(), DoRelease();
static void DoCreate(), DoDestroy();
static void DoInput(), DoOutput(), DoTesting();
static void DoFixedSize(), DoVariableSize();
static void DoFinal();
static void Statistics();

typedef struct pattern
	{
	int	recnum;
	char	rest[TRACKSIZE - sizeof(int)];
	} PATTERN;

static int noisy=1;
static int test=0;
static const int InsufficientSpace = 2;
static const int DuplicateFile = 4;
static const int FileDoesNotExist = 4;

int main(int, char**)
    {
    for( ; ; )
	{
	char cmd;

	cin >> cmd;
	switch(cmd)
	    {
	    case 'A':			// ALLOCATE
		DoAllocate();
		break;
	    case 'C':			// CREATE FILE
		DoCreate();
		break;
	    case 'D':			// DESTROY FILE
		DoDestroy();
		break;
	    case 'F':			// FORMAT
		DoFormat();
		break;
	    case 'G':			// RESTART
		DoRestart();
		break;
	    case 'I':			// INPUT FROM FILE
		DoInput();
		break;
	    case 'L':			// DIRECTORY LISTING
		ListDirectory();
		break;
	    case 'M':			// MESSAGE
		cout << "------------------- MESSAGE ---------------\n";
		do { cin.get(cmd); cout.put(cmd); } while(cmd != '\n');
		cout << "-------------------------------------------\n";
		break;
	    case 'O':			// OUTPUT TO FILE
		DoOutput();
		break;
	    case 'Q':			// QUIT
		return 0;
	    case 'R':			// RELEASE
		DoRelease();
		break;
	    case 'S':			// STATISTICS
		Statistics();
		break;
	    case 'T':			// TABLE
		Table();
		break;
	    case 'X':			// EXTENSIVE TESTS
		DoTesting();
		break;
	    case 'Z':			// DRIVER TEST MODE
		test = 1;
		break;
	    case '0':			// QUIET MODE
		cout << "Narrative disabled...\n";
		noisy = 0;
		break;
	    case '1':			// NOISY MODE
		cout << "Narrative enabled...\n";
		noisy = 1;
		break;
	    default:
		break;
	    }
	}
    }

/****************************************************************
 * FUNCTION
 *	Uniform - Generate a uniform random deviate between 0 and 1
 *	Markov - Generate a Markov random deviate (i.e. negative
 *		exponential distribution) with mean 1.0
 * DESCRIPTION
 *	Generate a random number
 * PARAMETERS
 *	None
 * RETURN VALUE
 *	A random number distributed appropriately.
 ****************************************************************
 */

static
double Uniform()		// Uniform deviate in (0,1)
	{
		return static_cast< double > ( rand() ) / static_cast< double >( RAND_MAX );
	}

static
double Markov()			// Markov deviate with mean 1.0
	{
	double rval = Uniform();
	return - log(rval);
	}

/****************************************************************
 * FUNCTION
 *	Check - Check the status
 * DESCRIPTION
 *	Verifies that the status expected is the one received
 * PARAMETERS
 *	expected - the expected status
 *	got - the actual status
 ****************************************************************
 */

static
void Check(int expected, int got)
	{
	int error = (expected >= 0 && expected != got);
	if( error || noisy)
		cout << "expected (" << expected
			<< ")  got (" << got << ")\n";
	if( error )
		{
		cerr << "Error Detected.\n";
		if( !test )
			exit(1);
		}
	}

/****************************************************************
 * FUNCTION
 *	ReadName - Read a file name
 * RETURN VALUE
 *	A pointer to a file name string
 ****************************************************************
 */

static
char* ReadName()
	{
	char discard;
	enum { NAME=8 };
	static	char fileName[ NAME+1 ];

	cin.get(discard);
	for(int i=0; i<NAME ; i++)
		cin.get(fileName[i]);
	fileName[NAME] = 0;
	return fileName;
	}

/****************************************************************
 * FUNCTION
 *	DoFormat - Format a disk
 * DESCRIPTION
 *	Processes the format request:
 *		F <tracks>
 ****************************************************************
 */

static
void DoFormat()
	{
	cin >> totalTracks;
	if(noisy)
		cout << "FORMAT " << totalTracks << " tracks\n";

	if(totalTracks != 0)
		delete disk;
	disk = new DISK(totalTracks, TRACKSIZE);
	FormatDisk( totalTracks );
	}

/****************************************************************
 * FUNCTION
 *	DoRestart - Power interrupt test
 * DESCRIPTION
 *	Processes the power interrupt request:
 *		G
 ****************************************************************
 */

static
void DoRestart()
	{
#ifdef RESTART
	cout << "-----------------------------------------\n";
	cout << "   Oh oh.  Did those lights just dim?  Oh no. They did.\n";
	cout << "   Don't worry.  You implemented a restart procedure...\n";
	cout << "   Well here goes...\n";

	if(noisy)
		cout << "RESTART " << totalTracks << " tracks\n";

	Restart( totalTracks );

	cout << "   Restart completed.\n";
	cout << "   You did implement a restart, didn't you?\n";
	cout << "-----------------------------------------\n";
#endif
	}

/****************************************************************
 * FUNCTION
 *	DoAllocate - Allocate tracks
 * DESCRIPTION
 *	Processes the allocate request:
 *		A <tracks> <expected>
 ****************************************************************
 */

static
void DoAllocate()
	{
	int address, numTracks, expected, got;

	cin >> numTracks >> expected;

	address = -1;
	got = Allocate( address, numTracks );
	
	if(noisy)
		cout << "ALLOCATE " << numTracks
			<< " at " << address << "   status: ";
	Check(expected, got);
	}

/****************************************************************
 * FUNCTION
 *	DoRelease - Release tracks
 * DESCRIPTION
 *	Processes the release request:
 *		R <address> <tracks> <expected>
 ****************************************************************
 */

static
void DoRelease()
	{
	int address, numTracks, expected, got;

	cin >> address >> numTracks >> expected;

	got = Release( address, numTracks );
	
	if(noisy)
		cout << "RELEASE " << numTracks
			<< " at " << address << "   status: ";
	Check(expected, got);
	}

/****************************************************************
 * FUNCTION
 *	DoCreate - Create a file
 * DESCRIPTION
 *	Processes the create request:
 *		C <name> <tracks> <expected>
 ****************************************************************
 */

static
void DoCreate()
	{
	char *fileName;
	int address, numTracks, expected, got;

	fileName = ReadName();
	cin >> numTracks >> expected;

	got = CreateFile( fileName, numTracks, address );
	
	if(noisy)
		{
		cout << "CREATE " << fileName
			<< " size " << numTracks
			<< " at " << address << "   status: ";
		}
	Check(expected, got);
	}

/****************************************************************
 * FUNCTION
 *	DoDestroy - Destroy a file
 * DESCRIPTION
 *	Processes the destroy request:
 *		D <name> <expected>
 ****************************************************************
 */

static
void DoDestroy()
	{
	char *fileName;
	int expected, got;

	fileName = ReadName();
	cin >> expected;

	got = DestroyFile( fileName );
	
	if(noisy)
		{
		cout << "DESTROY " << fileName
			<< "   status: ";
		}
	Check(expected, got);
	}

/****************************************************************
 * FUNCTION
 *	DoInput - Input a pattern from a file
 * DESCRIPTION
 *	Processes the input request:
 *		I <name> <expected>
 ****************************************************************
 */

static
void DoInput()
	{
	char *fileName;
	int expected;

	fileName = ReadName();
	cin >> expected;
	TestInput(fileName, expected);
	}

static
void TestInput(char *fileName, int expected)
	{
	int address, numTracks, got, savenoisy;
	static PATTERN pat;

	savenoisy = noisy;
	address = numTracks = -1;
	got = FindFile( fileName, numTracks, address );
	
	if(address<0 || numTracks<1 || got!=0)
		noisy = 1;

	if(noisy)
		{
		cout << "INPUT FROM " << fileName
			<< " size " << numTracks
			<< " at " << address << "   status: ";
		}
	Check(expected, got);
	noisy = savenoisy;
	if(got != 0)
		return;

	if(numTracks<1)
		{
		cout << "Error: File size must be positive\n";
		exit(1);
		}

	noisy = 0;
	for(int i=0 ; i<numTracks ; i++ )
		{
		Check(0, ReadDisk( (unsigned char *) &pat, address + i ));
		if( pat.recnum != i || strncmp(pat.rest, fileName, 10) != 0 )
			{
			cout << "INPUT FAILURE: " << fileName
				<< " record " << i << "\n";
			}
		}
	noisy = savenoisy;
	}

/****************************************************************
 * FUNCTION
 *	DoOutput - Output a pattern to a file
 * DESCRIPTION
 *	Processes the output request:
 *		O <name> <expected>
 ****************************************************************
 */

static
void DoOutput()
	{
	char *fileName;
	int expected;

	fileName = ReadName();
	cin >> expected;
	TestOutput(fileName, expected);
	}

static
void TestOutput(char *fileName, int expected)
	{
	int address, numTracks, got, savenoisy;
	static PATTERN pat;

	savenoisy = noisy;
	address = numTracks = -1;
	got = FindFile( fileName, numTracks, address );
	
	if(address<0 || numTracks<1 || got!=0)
		noisy = 1;

	if(noisy)
		{
		cout << "OUTPUT TO " << fileName
			<< " size " << numTracks
			<< " at " << address << "   status: ";
		}
	Check(expected, got);
	noisy = savenoisy;
	if(got != 0)
		return;

	if(numTracks<1)
		{
		cout << "Error: File size must be positive\n";
		exit(1);
		}

	noisy = 0;
	memset( (unsigned char *) &pat, 0, sizeof(PATTERN) );
	strcpy(pat.rest, fileName);
	for(int i=0 ; i<numTracks ; i++ )
		{
		pat.recnum = i;
		Check(0, WriteDisk( (unsigned char *) &pat, address + i ));
		}
	noisy = savenoisy;
	}

static
void TestDummy(char *fileName, int expected)
	{
	int address, numTracks, got, savenoisy;

	savenoisy = noisy;
	address = numTracks = -1;
	got = FindFile( fileName, numTracks, address );
	
	if(address<0 || numTracks<1 || got!=0)
		noisy = 1;

	if(noisy)
		{
		cout << "HEAD MOVEMENT TO " << fileName
			<< " size " << numTracks
			<< " at " << address << "   status: ";
		}
	Check(expected, got);
	noisy = savenoisy;
	if(got != 0)
		return;

	if(numTracks<1)
		{
		cout << "Error: File size must be positive\n";
		exit(1);
		}

	noisy = 0;
	for(int i=0 ; i<numTracks ; i++ )
		Check(0, disk->MoveHeads( address + i ));
	noisy = savenoisy;
	}

/******************************************************************
 * FUNCTION
 *	DoTesting - a variety of file manipulation tests
 * PARAMETERS
 *	Processes various file manipulation tests
 *		X1 <size>		- create & destroy files of fixed size
 *		X2 <seed> <size>	- same but size is an average
 *		X3			- part of final driver test
 * RETURN VALUE
 *	None
 ******************************************************************
 */

static
void DoTesting()
	{
	char which;

	cout << "------- Begin EXTENSIVE TEST ----------------\n";
	int savenoisy = noisy;		// Save noisy status
	noisy = 0;			// Cut down noise

	cin >> which;
	switch(which)
		{
		case '1':		// FIXED SIZE
			DoFixedSize();
			break;
		case '2':		// VARIABLE SIZE
			DoVariableSize();
			break;
		case '3':		// VARIABLE SIZE
			DoFinal();
			break;
		default:
			cerr << "Illegal command: X" << which << "\n";
			exit(1);
		}

	noisy = savenoisy;		// Restore noise
	cout << "------- End EXTENSIVE TEST ----------------\n";
	}

static
char* genFilename(int num)
	{
	static char filename[80];

	int d1 = num % 5;
	num /= 5;
	int d2 = num %10;
	num /= 10;
	int d3 = num %10;
	num /= 10;
	int d4 = num %10;
		// Create a file name:  F n X Y Z n n n
		// where the digits nnnn are backwards
		// to keep things in a messy sequence
		// A total of 5000 distinct file names
		// are possible.
	sprintf(filename, "F%dXYZ%d%d%d", d1, d2, d3, d4);
	return filename;
	}

static
void DoFixedSize()
	{
	int size;

	cin >> size;
	cout << "FIXED size test, size = " << size << "\n";

	ListDirectory();
	cout << "\n"
		<< "   Attempting to create lots of files\n"
		<< "   Each dot is 50 files\n";

	for(int i=0 ; i<5000 ; i++)
		{
		if(i%50 == 49)
			{
			cout << ".";
			cout.flush();
			}
		char *fname=genFilename(i);
		int track;
		int got = CreateFile(fname, size, track);
		if(got != 0)
			{
			cout << "\n"
				<< i << " files created\n\n";
			Check(InsufficientSpace, got);
			DoRestOfTest(i);
			return;
			}
		}
	cout << "\n"
		<< "5000 files were successfully created.\n"
		<< "Either this is an awfully large disk or\n"
		<< "you have something really strange here...\n";
	Table();
	DoRestOfTest(5001);
	}

static
void DoVariableSize()
	{
	int seed;
	double asize;

	cin >> seed >> asize;
	srand(seed);
	cout << "VARIABLE size test, average = " << asize << "\n";

	ListDirectory();
	cout << "\n"
		<< "   Attempting to create lots of files\n"
		<< "   Each dot is 50 files\n";

	for(int i=0 ; i<5000 ; i++)
		{
		if(i%50 == 49) { cout << "."; cout.flush(); }
		char *fname=genFilename(i);
		double rsize = 0.5 + asize * Markov();
		int size = (int) rsize;
		if(size < 1) size = 1;
		int track;
		int got = CreateFile(fname, size, track);
		if(got != 0)
			{
			cout << "\n"
				<< i << " files created\n\n";
			Check(InsufficientSpace, got);
			DoRestOfTest(i);
			return;
			}
		}
	cout << "\n"
		<< "5000 files were successfully created.\n"
		<< "Either this is an awfully large disk or\n"
		<< "you have something really strange here...\n";
	Table();
	DoRestOfTest(5001);
	}

static
void DoFinal()
	{
	const int MAXFILES = 2000;
	const int seed = 1000;
	const double asize = 25.0;
	static char fsize[MAXFILES];
	int totsize = 0;
	int got;

	srand(seed);
	cout << "VARIABLE size test, average = " << asize << "\n";

	Table();
	ListDirectory();
	Statistics();

	cout << "\n"
		<< "   Attempting to create lots of files\n"
		<< "   Each dot is 50 files\n";

   int i;
   for(i=0 ; i<MAXFILES ; i++)
		{
		char *fname;
		switch(i%50)
			{
			case 10:
			case 11:
			case 20:
			case 21:
				fname = genFilename(i-1);
				TestOutput(fname,0);
				break;
			case 12:
			case 13:
			case 22:
			case 23:
				fname = genFilename(i-3);
				TestInput(fname,0);
				break;
			case 49:
				cout << "."; cout.flush();
				break;
			}
#ifdef RESTART
		if(i==30)
			{
			noisy = 1;
			fname = genFilename(10);
			cout << "Simulated system shutdown coming up\n";
			cout << "Before Shutdown\n";
			Table();
			ListDirectory();
			DoRestart( );
			Table();
			ListDirectory();
			TestInput(fname,0);
			noisy = 0;
			}
#endif
		fname=genFilename(i);
		double rsize = 0.5 + asize * Markov();
		int size = (int) rsize;
		if(size < 1) size = 1;
		if(size > 50) size = 50;
		int track;
		if(got = CreateFile(fname, size, track))
			break;
		totsize += size;
		TestDummy(fname,0);
		}

	Table();
	ListDirectory();
	Statistics();

	cout << "\n" << i << " files created\n"
		<< totsize << " tracks used for files\n";
	if(got)
		Check(InsufficientSpace, got);

	DoRestOfTest(i);
	}

static
void DoRestOfTest(int numfiles)
	{
	int got;
	ListDirectory();
	cout << "\n"
		<< "   Deleting (almost) half the files\n";

   int i;
   for (i=2 ; i<numfiles ; i+=2)
		{
		if(i%100 == 98) { cout << "."; cout.flush(); }
		char *fname=genFilename(i);
		got = DestroyFile(fname);
		if(got !=0) cout << "\n";
		Check(0,got);
		}
	cout << "\n";

	ListDirectory();
	cout << "\n"
		<< "   Deleting all but one of the remaining files\n";

	for(i=1 ; i<numfiles ; i+=2)
		{
		if(i%100 == 99) { cout << "."; cout.flush(); }
		char *fname=genFilename(i);
		got = DestroyFile(fname);
		if(got !=0) cout << "\n";
		Check(0,got);
		}
	cout << "\n";

	ListDirectory();

	cout << "\n";
	noisy = 1;
	char *fname=genFilename(0);
	cout << "   Creating duplicate file " << fname << "   ";
	int dummy;
	got = CreateFile(fname, 1, dummy);
	Check(DuplicateFile,got);
	cout << "   Deleting file " << fname << "   ";
	got = DestroyFile(fname);
	Check(0,got);
	cout << "   Deleting nonexistant file " << fname << "   ";
	got = DestroyFile(fname);
	Check(FileDoesNotExist,got);

	ListDirectory();
	Table();
	Statistics();
	}

/******************************************************************
 * FUNCTION
 *	ReadDisk - Disk I/O interface
 *	WriteDisk - Disk I/O interface
 * PARAMETERS
 *	buffer - read/write buffer
 *	address - disk track address
 * RETURN VALUE
 *	I/O status
 ******************************************************************
 */

int ReadDisk(unsigned char *buffer, int address)
	{
	return disk->ReadDisk(buffer, address);
	}

int WriteDisk(unsigned char *buffer, int address)
	{
	return disk->WriteDisk(buffer, address);
	}

/******************************************************************
 * FUNCTION
 *	Statistics - Print simulated disk statistics
 * PARAMETERS
 *	None
 * RETURN VALUE
 *	None
 ******************************************************************
 */

static void Statistics()
	{
	int reads, writes, movement;

	disk->DiskStatistics(reads, writes, movement);
	cout << "+----------------------------------------------+\n";
	cout << "|             DISK STATISTICS                  |\n";
	cout << "+----------------------------------------------+\n";
	cout << " Number of reads: " << reads << "\n";
	cout << "Number of writes: " << writes << "\n";
	cout << "   Head movement: " << movement << "\n";
	cout << "\n";
	}
