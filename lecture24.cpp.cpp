#include <iostream>
#include <bitset>
#include <cassert>
#include <cstdlib>

#include "disk.h"

using namespace std;

int main() {

	DISK dsk(2000,128);

	const int TRACKSIZE = 128;
	const int bitsPerTrack = TRACKSIZE * 8;	

	bitset<bitsPerTrack> b;

	// WriteDisk( (unsigned char*)&b, 0);
	assert( dsk.WriteDisk((unsigned char*)&b, 1) == 1 );

	b[0] = 1;
	b[1] = 1;
	dsk.WriteDisk((unsigned char*)&b, 0);
	cout << endl;

	for ( int i = 0; i < bitsPerTrack; i++ ) {
		cout << b[i];
		if ((i+1)%64 == 0) cout << endl;
	}
	cout << endl;

	cout << endl;

	cout << b.to_string() << endl;
	

}
