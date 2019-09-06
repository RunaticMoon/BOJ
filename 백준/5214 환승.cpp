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
	������ ���� �ʹ� ���� ���� ������
	������Ʃ�굵 �������� �ΰ�
	������ ����/2�� ���·� bfs�� ������ �ȴ�.
*/