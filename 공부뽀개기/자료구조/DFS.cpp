#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; 
vector<int>* graph;
vector<bool> visited;

//��� �̿�
void dfs(int start) {
	if (visited[start]) //�̹� �湮�� ��� return;
		return;

	visited[start] = true; //�湮
	for (int i = 0; i < graph[start].size(); i++) {
		dfs(graph[start][i]); // ���� ���� ��� �湮
	}
}

int main() {
	cin >> N >> M;
	graph = new vector<int>[N + 1];
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) { 
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//����
	for (int i = 1; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].begin());
	}

	dfs(1);

	return 0;
}