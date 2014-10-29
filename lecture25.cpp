#include <iostream>
#include <map>
//#include <unordered_map>

using namespace std;

int main()
{
{
	map<string,int> dict;

	dict["hello"] = 100;
	dict["bye"] = 200;
	dict["third"] = 300;

	map<string,int>::const_iterator it;

	for ( it = dict.begin(); it != dict.end(); it++ ) {
		cout << (*it).first << ", " << (*it).second << endl;
	}
	cout << endl;
}
{
	typedef pair<string,int> data;

	multimap<string,int> dict;

	dict.insert(data("hello",100));
	dict.insert(data("hello",200));
	dict.insert(data("third",300));

	map<string,int>::const_iterator it;

	for ( it = dict.begin(); it != dict.end(); it++ ) {
		cout << (*it).first << ", " << (*it).second << endl;
	}
	cout << endl;
}
}
