
#include <vector>
#include <iostream>
#include "DGraph.h"


void DGraph::load()
{
	int nodes, V, E;
	std::cin >> nodes;
	
	//adjacent = vector<vector<bool>>( nodes, vector<int>(nodes, false) );

	for ( int r = 0; r < nodes; r++ ) {
	  adjacent.push_back(vector<int>());
	  for (int c = 0; c < nodes; c++ ){
	    adjacent[r].push_back(false);
	  }
	}
	
	for( int i = 0; i < nodes; i++) {

		std::cin >> V >> E;
		DGraph::adjacent[V][E] = 1;
	}
	
}

void DGraph::print()
{
	int size = DGraph::adjacent.size();
	for( int i = 0; i < size; i++) {

		int csize = DGraph::adjacent[i].size();
		for( int j = 0; j < csize; j++) {
			std::cout << DGraph::adjacent[i][j] << " ";
		}
		
		std::cout << std::endl;
	}
}

void DGraph::traverseDFS()
{

}

void DGraph::reverse()
{

}

void DGraph::dfs( std::vector<bool>& visited, int index)
{

}
