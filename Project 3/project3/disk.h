#ifndef _DISK_

#define _DISK_

enum RW_Status {OK=0, Failure=1};

class DISK
{
	private:
		int			tracksize;
		int			numtrack;
		unsigned char **	disk;
		int			headposition;
		int			headtravel;
		int			numreads;
		int			numwrites;
	public:
		DISK(int,int);
		~DISK();
		RW_Status ReadDisk (unsigned char *, int);
		RW_Status WriteDisk (unsigned char *, int);
		RW_Status MoveHeads(int);
		void DiskStatistics( int &, int &, int &);
};

#endif
