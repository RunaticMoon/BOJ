#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int N, M, a, b;
bool user[100][100];

int bfs(int n) {
	int visited[100][100];
	memset(visited, 0, sizeof(visited));

	queue<pair<int, int>> q;
	q.push({ n, n });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		int r = cur.first;
		int c = cur.second;
		int v = visited[r][c];

		for (int i = 0; i < N; i++) {
			if (user[r][i] && visited[r][i] == 0) {
				q.push({i, r});
				visited[r][i] = v + 1;
				visited[i][r] = v + 1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		if (i == n) {
			continue;
		}

		int num = INT_MAX;
		for (int j = 0; j < N; j++) {
			const int& ret = visited[i][j];
			if (ret != 0 && ret < num) {
				num = ret;
			}
		}
		result += num;
	}

	return result;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		user[a - 1][b - 1] = true;
		user[b - 1][a - 1] = true;
	}

	int chk = bfs(0);
	int index = 1;
	for (int i = 1; i < N; i++) {
		const int& tmp = bfs(i);
		if (tmp < chk) {
			index = i + 1;
			chk = tmp;
		}
	}

	cout << index;

	return 0;
}