#include <iostream>
using namespace std;

int N, M;
int arr[9];

void dfs(int n, int m) {
	if (n == M) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = m; i <= N; i++) {
		arr[n] = i;  
		dfs(n + 1, i);
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