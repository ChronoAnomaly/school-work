#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

void printSet( const set<int>& );
pair<int,int> findMinEdge( const vector< vector< int > >&, const set<int>, set<int> );
vector< pair<int,int> > primMCST( const vector< vector< int > >&, const set<int>& );

int main() {

	// Undirected graph for demonstration purpose
	const int inf = numeric_limits<int>::max();
	const int N = 6;
	int C[N][N] = {
		{  inf,  8, 12,  inf,  1,  8 },
		{  8,  inf,  5, 10,  6,  9 },
		{ 12,  5,  inf,  2,  1,  4 },
		{  0, 10,  2,  inf, 15,  2 },
		{  1,  6,  1, 15,  inf,  3 },
		{  8,  9,  4,  2,  3,  inf }
	};
	
	// define a cost matrix and vertex set
	vector< vector<int> > cost( N, vector<int>(N, 0));
	set<int> V;
	
	// initialize the cost matrix and vertex set
	for ( int i = 0; i < N; i++ ) {
		V.insert(i);
		for ( int j = 0; j < N; j++ ) {
			cost[i][j] = C[i][j];
		}
	}
	
	vector< pair<int,int> > tree = primMCST( cost, V );
	
	int totalcost = 0;
	for ( vector< pair<int,int> >::const_iterator e = tree.begin(); e != tree.end(); e++ ) {
		pair<int,int> edge = *e;
		cout << "(" << edge.first << "," << edge.second << ")" << endl;
		totalcost += cost[edge.first][edge.second];		
	}
	cout << "cost: " << totalcost << endl;

}


void printSet( const set<int>& s ) {
	for ( set<int>::const_iterator it = s.begin(); it != s.end(); it++ ) {
		cout << *it << " ";
	}
	cout << endl;
}

pair<int,int> findMinEdge( const vector< vector< int > >& cost, const set<int> S, set<int> V ) {

	int minCost = numeric_limits<int>::max();
	pair<int,int> minEdge;
	
	for ( set<int>::const_iterator is = S.begin(); is != S.end(); is++ ) {
		int vx = *is;
		//cout << "x:" << vx << " ";
		for ( set<int>::const_iterator iv = V.begin(); iv != V.end(); iv++ ) {
			int vy = *iv;
			//cout << "y:" << vy << "(" << cost[vx][vy] << ")";
			if ( cost[vx][vy] < minCost ) {
				minEdge = pair<int,int>(vx,vy);
				minCost = cost[vx][vy];
				//cout << "*";
			}
			//cout << " ";
		}
	}
	//cout << endl;
	//cout << "pair: " << minEdge.first << " " << minEdge.second << endl;
	return minEdge;
}

vector< pair<int,int> > primMCST( const vector< vector< int > >& cost, const set<int>& V0 ) {

	set<int> V(V0.begin(), V0.end());	// V - S 
	set<int> S;							// spanning tree vertices
	vector< pair<int,int> > tree;		// spanning tree edges
	
	S.insert(0);						// put a vertex in S
	V.erase(0);
	
	while ( !V.empty() ) {
	
		pair<int,int> minEdge = findMinEdge(cost, S, V);
		
		tree.push_back( minEdge );
		V.erase( minEdge.second );
		S.insert( minEdge.second );
		
		// cout << "V: ";
		// printSet(V);
		// cout << "S: ";
		// printSet(S);
	}
	
	return tree;
}

