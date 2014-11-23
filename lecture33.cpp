#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void traverseDFS(vector< vector<bool> >);
void dfs(vector< vector<bool> >, vector<bool>&, int);

void traverseBFS(vector< vector<bool> >);
void bfs(vector< vector<bool> >, vector<bool>&, int);

int main() {

	const int N = 6;
	bool A[N][N] = {
		{ 1, 1, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0 },
		{ 0, 1, 0, 0, 1, 0 }
	};
	
	vector< vector<bool> > adjacent( N, vector<bool>(N, false));
	
	for ( int i = 0; i < N; i++ ) {
		for ( int j = 0; j < N; j++ ) {
			adjacent[i][j] = A[i][j];
		}
	}
	
	cout << "DFS" << endl;
	traverseDFS(adjacent);
	cout << endl;
	
	cout << "BFS" << endl;
	traverseBFS(adjacent);
	cout << endl;
}

void traverseDFS(vector< vector<bool> > adj) {

	vector<bool> visited(adj.size(), false);

	int treeCnt = 0;
	for (int v = 0; v < visited.size(); v++) {
		if (!visited[v]) {
			cout << "tree: " << ++treeCnt << endl;
			dfs(adj, visited, v);
		}
	}
}

void dfs(vector< vector<bool> > adj, vector<bool>& visited, int v) {

	cout << v << endl;
	visited[v] = true;

	// 1

	for (int w = 0; w < adj[v].size(); w++) {
		if (adj[v][w] && !visited[w]) {
			// 2
			dfs(adj, visited, w);
			// 3
		}
	}
	
	// 4
}

void traverseBFS(vector< vector<bool> > adj) {

	vector<bool> visited(adj.size(), false);

	for (int v = 0; v < visited.size(); v++) {
		if (!visited[v]) {
			bfs(adj, visited, v);
		}
	}
}

void bfs(vector< vector<bool> > adj, vector<bool>& visited, int v) {

	queue<int> q;

	visited[v] = true;
	q.push(v);
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		cout << v << endl;

		for (int w = 0; w < adj[v].size(); w++) {
			if (adj[v][w] && !visited[w]) {
				visited[w] = true;
				q.push(w);
			}
		}

	}
}

