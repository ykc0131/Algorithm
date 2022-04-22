#include <iostream>
#include <vector>

using namespace std;

vector<int>* graph;
vector<bool> visited;

void dfs(int n) {
	if (visited[n])
		return;
	visited[n] = true;
	for (int i = 0; i < graph[n].size(); i++) {
		dfs(graph[n][i]);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	graph = new vector<int>[N + 1];
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1);

	int result = 0;
	for (int i = 2; i < N + 1; i++) {
		if (visited[i])
			result++;
	}

	cout << result;
	return 0;
}