#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
queue<int> q;
vector<int>* graph;
vector<bool> visited;

void bfs(int v) {
	q.push(v);
	
	while (!q.empty()) {
		int n = q.front(); q.pop();

		if (!visited[n]) {
			visited[n] = true;
			for (int i = 0; i < graph[n].size(); i++) {
				int next = graph[n][i];
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> N;
	graph = new vector<int>(N+1, 0);
	visited.resize(N+1, 0);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//Á¤·Ä
	for (int i = 1; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].begin());
	}

	bfs(1);

	return 0;
}