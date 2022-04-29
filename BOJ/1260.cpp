#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N, M, V;
queue<int> q;
vector<int>* graph;
vector<bool> visited;
string dfsResult = "";
string bfsResult = "";

void dfs(int n) {
	if (visited[n])
		return;

	visited[n] = true;
	dfsResult += (to_string(n) + " ");

	for (int i = 0; i < graph[n].size(); i++) {
		dfs(graph[n][i]);
	}
}

void bfs(int n) {
	q.push(n);

	while (!q.empty()) {
		int top = q.front(); q.pop();
		if (visited[top])
			continue;
		visited[top] = true;
		bfsResult += (to_string(top) + " ");

		for (int i = 0; i < graph[top].size(); i++) {
			q.push(graph[top][i]);
		}
	}
}

int main() {
	cin >> N >> M >> V;
	graph = new vector<int>[N + 1];
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	fill(visited.begin(), visited.end(), false);
	bfs(V);

	cout << dfsResult << "\n" << bfsResult;

	return 0;
}