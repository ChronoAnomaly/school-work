#include <iostream>
#include <string>
#include <array>
#include <set>
#include <unordered_set>

using namespace std;

void unorderedSetExample() {

	unordered_set<string> myset = { "yellow", "green", "blue" };
	array<string, 2> myarray = { "black", "white" };
	string mystring = "red";

	// insert items
	myset.insert(mystring);								// insertion
	myset.insert(mystring + "dish");					// insertion
	myset.insert(myarray.begin(), myarray.end());		// range insertion

	// display content
	cout << "myset contains:";
	for (unordered_set<string>::const_iterator it = myset.begin(); it != myset.end(); it++) cout << " " << *it;
	cout << endl;

	// access items
	cout << "green is in the set: " << (myset.find("green") != myset.end()) << endl;
	cout << "cyan is in the set: " << (myset.find("cyan") != myset.end()) << endl;

	// performance
	cout << "load factor: " << myset.load_factor() << endl;
	cout << "bucket count: " << myset.bucket_count() << endl;
	for (unsigned int i = 0; i < myset.bucket_count(); i++) {
		cout << "bucket number " << i << " size is: " << myset.bucket_size(i) << endl;
	}
}


class myCompare
{
public:
	bool operator()(const string& s1, const string& s2) const
	{
		return s1 > s2;
	}
};


void orderedSetExample() {

	set<string> myset = { "yellow", "green", "blue" };
	//set<string, myCompare> myset = { "yellow", "green", "blue" };
	array<string, 2> myarray = { "black", "white" };
	string mystring = "red";

	// display content
	cout << "myset contains:";
	for (set<string>::const_iterator it = myset.begin(); it != myset.end(); it++) 
		cout << " " << *it;
	cout << endl;

	// insert items
	myset.insert(mystring);								// insertion
	myset.insert(mystring + "dish");					// insertion
	myset.insert(myarray.begin(), myarray.end());		// range insertion

	// display content
	cout << "myset contains:";
	for (set<string>::const_iterator it = myset.begin(); it != myset.end(); it++) cout << " " << *it;
	cout << endl;

	// access items
	cout << "green is in the set: " << (myset.find("green") != myset.end()) << endl;
	cout << "cyan is in the set: " << (myset.find("yellow") != myset.end()) << endl;

	// performance
	cout << "size: " << myset.size() << endl;
}

int main() {

	unorderedSetExample();
	//orderedSetExample();

	return 0;
}