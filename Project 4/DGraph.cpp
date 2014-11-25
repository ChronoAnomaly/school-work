
#include <vector>
#include <iostream>
#include "DGraph.h"

using namespace std;

void DGraph::load()
{
	int nodes, V, E;
	cin >> nodes;
	
	//DGraph::adjacent = vector<vector<int> >( nodes, vector<int>(nodes, false) );

	for ( int r = 0; r < nodes; r++ ) {
	  DGraph::adjacent.push_back(vector<int>());
	  for (int c = 0; c < nodes; c++ ){
	    DGraph::adjacent[r].push_back(false);
	  }
	}

	for( int i = 0; i < nodes; i++) {

		cin >> V >> E;
		DGraph::adjacent[V][E] = 1;
	}
	
}

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

}

void DGraph::reverse()
{

}

void DGraph::dfs( vector<int>& visited, int index)
{

}
