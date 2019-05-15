#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

int T;
int M, N, K, x, y;
bool map[50][50];
bool visited[50][50];
int worm;

void bfs(int i, int j) {

}

int main() {
	ifstream fin("input.txt");
	cin.rdbuf(fin.rdbuf());

	for (int test_case = 0; test_case < T; test_case++) {
		memset(visited, 0, sizeof(visited));
		worm = 0;

		cin >> M >> N >> K;

		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			map[y][x] = true;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && !visited[i][j]) {
					bfs(i, j);
					worm++;
				}
			}
		}
	}

	return 0;
}