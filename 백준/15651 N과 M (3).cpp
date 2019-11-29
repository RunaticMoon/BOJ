#include <iostream>
using namespace std;

int N, M;
int arr[9];

void dfs(int n) {
	if (n == M) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	// 중복조합 (visited 체크 x)
	for (int i = 1; i <= N; i++) {
		arr[n] = i;
		dfs(n + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	dfs(0);

	return 0;
}