#include <iostream>
using namespace std;

int N, M;
bool visited[9];
int arr[9];

void func(int n) {
	if (n == M) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[n] = i;

			func(n + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	func(0);

	return 0;
}