#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

class Component {
	public:
		Component(int lbl) {
			label = lbl;
			parent = NULL;
		}
		
		Component* find() {
			Component* tmp = this;
			while ( tmp->parent != NULL ) tmp = tmp->parent;
			return tmp;
		}
		
		void merge(Component* c2) {
			c2->parent = this;
		}
		
	private:
		int label;
		Component* parent;
};

class Edge : public pair<int,int> {
	public:
		Edge( int vx, int vy, int cst ) {
			first = vx;
			second = vy;
			cost = cst;
		}
		
		bool operator< (const Edge& e2) const {
			return cost > e2.cost;
		}
		
		int edgeCost() const {
			return cost;
		}
		
	private:
		int cost;
};

void kurskalMCST( const vector< vector< int > >& );


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
	
	// define a cost matrix
	vector< vector<int> > cost( N, vector<int>(N, 0));
	
	// initialize the cost matrix and vertex set
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < N; j++ ) {
			cost[i][j] = C[i][j];
		}
	}
	
	kurskalMCST(cost);
	
	cout << "done" << endl;
	exit(0);
}

void printPriorityQueue( priority_queue<Edge> pq ) {
	// display edge set	
	while ( !pq.empty() ) {
		Edge e = pq.top();
		pq.pop();
		cout << "(" << e.first << "," << e.second << "): " << e.edgeCost() << endl;
	}
	cout << endl;
}

void kurskalMCST( const vector< vector< int > >& cost ) {

	priority_queue< Edge > pq;
	
	// create heap of edges
	for ( int vx = 0; vx < cost.size(); vx++ ) {
		for ( int vy = vx + 1; vy < cost[vx].size(); vy++ ) {
			if ( cost[vx][vy] < numeric_limits<int>::max() ) {
				pq.push( Edge(vx, vy, cost[vx][vy]) );
			}
		}
	}
	
	printPriorityQueue(pq);
	
	vector<Component*> comp; 
	for ( int v = 0; v < cost.size(); v++ ) {
		comp.push_back(new Component(v));
	}
	
	int numComponents = comp.size();
	
	while ( numComponents > 1 && !pq.empty() ) {
		Edge e = pq.top();
		pq.pop();
		
		if ( comp[e.first]->find() != comp[e.second]->find() ) {
			comp[e.first]->merge(comp[e.second]);
			cout << "(" << e.first << "," << e.second << "): " << e.edgeCost() << endl;
			numComponents--;
		}
	}
}
