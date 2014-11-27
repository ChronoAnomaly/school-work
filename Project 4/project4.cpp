
#include "DGraph.h"
#include <iostream>

using namespace std;

int main()
{

	cout << "Inital graph: " << endl;
	DGraph graph;

	graph.print();

	graph.traverseDFS();

	cout << endl << "Reversing the graph: " << endl;
	graph.reverse();

	graph.print();

	graph.traverseDFS();

	cout << endl;

	return 0;
}
