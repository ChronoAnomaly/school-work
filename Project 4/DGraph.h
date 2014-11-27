/*
 *	Brett Worley
 *	CS 3100-01
 *	10/22/14
 */
#ifndef _GRAPH_

#define _GRAPH_

#include <vector>

class DGraph {

	public:
		DGraph() { load(); }
		void load();
		void print();
		void traverseDFS();
		void reverse();

	private:
		std::vector< std::vector<int> > adjacent;
		void dfs( std::vector<bool>& visited, int index);

};

#endif
