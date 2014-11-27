
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

/*
 *	traverseDFS:  This function is used to help set up the depth-first search
 *	of the current adjacency matrix.  It creates a visited vector that will be
 *	to check if the node being visited has previously been to.
 */
void DGraph::traverseDFS()
{
	vector<bool> visited(DGraph::adjacent.size(), false);

	int treeCnt = 0;
	for (int v = 0; v < visited.size(); v++) {
		if (!visited[v]) {
			cout << "tree: " << ++treeCnt << endl;
			//cout << "(" << v << ",";
			dfs( visited, v);
		}
	}
}

void DGraph::dfs( vector<bool>& visited, int index)
{
	//cout << "(" << index << ", ";
	//cout << index << endl;
	visited[index] = true;


	for (int w = 0; w < DGraph::adjacent[index].size(); w++) {
		if (DGraph::adjacent[index][w] && !visited[w]) {
			//cout << "(" << index << ", " << DGraph::adjacent[index][w];
			cout << "(" << index << "," << w << ")" << endl;

			dfs( visited, w);
		}

	}
	
}

/*
 *	reverse:  This function is used to reverse the current adjacency matrix.
 *	It creates a temp 2d vectory and reads in the current matrix in reverse.
 *	After it is done, it swaps the adjacency matrix vector out with the reversed
 *	graph.
 */
void DGraph::reverse()
{

	int size = DGraph::adjacent.size();
	vector< vector<int> > reverse;
	reverse = vector<vector<int> >( size, vector<int>(size, false) );

	for( int i = 0; i < size; i++) {
		for( int j = 0; j < size; j++) {
			reverse[j][i] = DGraph::adjacent[i][j];
		}
		
	}
	
	DGraph::adjacent = reverse;

}


