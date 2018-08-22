#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
queue<int> que;

void dfs(int n) {
	visited[n] = true;
	cout << n << ' ';
	
	for (int next : graph[n]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int n) {
	que.push(n);
	visited[n] = true;

	while (!que.empty()) {
		int f = que.front();
		que.pop();
		cout << f << ' ';

		for (int next : graph[f]) {
			if (!visited[next]) {
				visited[next] = true;
				que.push(next);
			}
		}
	}
}

int main() {
	int N, M, V;
	int a, b;

	cin >> N >> M >> V;

	graph.resize(N + 1);
	visited.resize(N + 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i < N + 1; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	cout << endl;

	fill(visited.begin(), visited.end(), false);

	bfs(V);

	return 0;
}