#include <iostream>
using namespace std;

int N, M;
bool visited[9];
int arr[9];

void dfs(int n, int m) {
	if (n == M) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// а╤гу
	for (int i = m; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[n] = i;
			dfs(n + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	dfs(0, 1);

	return 0;
}