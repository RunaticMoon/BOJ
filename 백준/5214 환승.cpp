#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K, M;
int a, result;
vector<int> v[101002];
bool visited[101002];
int dist[101002];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> M;

	for (int i = N + 1; i < N + M + 1; i++) {
		for (int j = 0; j < K; j++) {
			cin >> a;
			v[i].push_back(a);
			v[a].push_back(i);
		}
	}

	q.push(1);
	dist[1] = 2;
	visited[1] = true;
	result = -1;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		if (pos == N) {
			result = dist[pos] / 2;
			break;
		}

		for (int next : v[pos]) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				dist[next] = dist[pos] + 1;
			}
		}
	}

	cout << result;
	
	return 0;
}

/*
	간선의 수가 너무 많아 지기 때문에
	하이퍼튜브도 정점으로 두고
	지나온 간선/2의 형태로 bfs를 돌리면 된다.
*/