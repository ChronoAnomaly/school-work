#include <iostream>

#include "sequence.h"

using namespace std;

template <typename T>
void testSeq( Sequence<T> s );

int main()
{
	Sequence<int> s(3);
	
	cout << s << endl;
	//operator<<(cout,s);
	//testSeq(s);
	//cout << s << endl;
	
	s[0] = 100;
	s[1] = s[0] + 100;
	s[2] = s[1] + s[2];
	
	cout << s << endl;
}

template <typename T>
void testSeq( Sequence<T> r )
{
	r.m_items[0] = 100;
	cout << "inside " << r << endl;
}

