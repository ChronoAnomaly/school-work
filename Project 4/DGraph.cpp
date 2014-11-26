
#include <vector>
#include <iostream>
#include "DGraph.h"

using namespace std;

/*
 *	load: This function loads the graph from the keyboard into an adjacency
 *	matrix that is a 2d vector.
 */
void DGraph::load()
{
	int nodes, V, E;
	cin >> nodes;
	
	DGraph::adjacent = vector<vector<int> >( nodes, vector<int>(nodes, false) );

	/*for ( int r = 0; r < nodes; r++ ) {
	  DGraph::adjacent.push_back(vector<int>());
	  for (int c = 0; c < nodes; c++ ){
	    DGraph::adjacent[r].push_back(false);
	  }
	}*/

	for( int i = 0; i < nodes; i++) {

		cin >> V >> E;
		DGraph::adjacent[V][E] = 1;
	}
	
}

/*
 *	print:  This function is used to print out the current adjacency matrix.
 *	A 1 will represent a node whose conection is row and column (such as a node
 *	with v 3 and e 5).  A 0 will represent no node.
 */
void DGraph::print()
{
	int size = DGraph::adjacent.size();
	for( int i = 0; i < size; i++) {

		int csize = DGraph::adjacent[i].size();
		for( int j = 0; j < csize; j++) {
			cout << DGraph::adjacent[i][j] << " ";
		}
		
		cout << endl;
	}
}

void DGraph::traverseDFS()
{
	vector<bool> visited(DGraph::adjacent.size(), false);

	int treeCnt = 0;
	for (int v = 0; v < visited.size(); v++) {
		if (!visited[v]) {
			cout << "tree: " << ++treeCnt << endl;
			dfs( visited, v);
		}
	}
}

void DGraph::dfs( vector<bool>& visited, int index)
{
	cout << index << endl;
	visited[index] = true;

	// 1

	for (int w = 0; w < DGraph::adjacent[index].size(); w++) {
		if (DGraph::adjacent[index][w] && !visited[w]) {
			// 2
			dfs( visited, w);
			// 3
		}
	}
	
	// 4
}

void DGraph::reverse()
{

}


