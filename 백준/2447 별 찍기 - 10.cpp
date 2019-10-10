#include <iostream>
using namespace std;

const int MAX = 6562;

int N;
char star[MAX][MAX];

void init(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star[i][j] = ' ';
		}
	}
}

void func(int r, int c, int n) {
	if (n == 1) {
		star[r][c] = '*';
		return;
	}

	n /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {}
			else func(r + i * n, c + j * n, n);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	init(N);
	func(0, 0, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}

	return 0;
}