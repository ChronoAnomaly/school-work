

#include <iostream>
#include <string>

using namespace std;

class nullele {

	public:
		const static int spacer = 0;
		int address;
};

class element {

	public:
		string name;
		int size;
		int address;
};

class node{

	public:
		nullele n_one;
		element one;
		nullele n_two;
		element two;
		nullele n_three;
		element three;
		nullele n_four;
		element four;
		nullele n_five;
		element five;
		nullele n_six;
};

int main()
{

	node check;
	element te;
	cout << sizeof(te) << endl;

	int size = sizeof(check);

	cout << size << endl;

}
