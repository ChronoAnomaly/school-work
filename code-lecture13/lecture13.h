#include <iostream>
#include "tnode.h"

using namespace std;

int main()
{
	
	BTree t1, t2, t3;
	
	t1 = BTree(10);
	
	cout << t1 << endl;
	
	t2 = BTree(20);
	
	t3 = BTree(30, t1, t2);
	
	cout << t3 << endl;
	
}
