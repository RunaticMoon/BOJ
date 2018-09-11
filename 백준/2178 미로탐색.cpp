#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[102][102];
int visited[102][102];

void bfs() {
	queue<pair<int, int>> q;
	visited[1][1] = 1;
	q.push({ 1, 1 });

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int i = cur.first;
		int j = cur.second;
		int v = visited[i][j];

		if (map[i][j + 1] == 1 && !visited[i][j + 1]) {
			visited[i][j + 1] = v + 1;
			q.push({ i, j + 1 });
		}
		if (map[i + 1][j] == 1 && !visited[i + 1][j]) {
			visited[i + 1][j] = v + 1;
			q.push({ i + 1, j });
		}
		if (map[i - 1][j] == 1 && !visited[i - 1][j]) {
			visited[i - 1][j] = v + 1;
			q.push({ i - 1, j });
		}
		if (map[i][j - 1] == 1 && !visited[i][j - 1]) {
			visited[i][j - 1] = v + 1;
			q.push({ i, j - 1 });
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = cin.get() - '0';
			if (map[i][j] == '\n' - '0') {
				map[i][j] = cin.get() - '0';
			}
		}
	}

	bfs();

	cout << visited[N][M];

	return 0;
}