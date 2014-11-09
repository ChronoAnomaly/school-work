

#include <iostream>
#include <string>

using namespace std;


class element {

	public:
		string name;
		unsigned short int size;
		unsigned short int address;
};

class node{

	public:
		element files[8];
};

int main()
{

	node check;
	element te;
	cout << sizeof(te) << endl;

	int size = sizeof(check);

	cout << size << endl;

	for( int i = 0; i <7 ; i++) {
		cout << check.files[i].name << endl;;
	}
}
