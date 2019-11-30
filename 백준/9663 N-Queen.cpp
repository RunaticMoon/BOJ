#include <iostream>
using namespace std;

int N, result;
bool board[16][16];
int diag[5] = { -1, -1, 1, 1, -1 };

bool check(int r, int c) {
	for (int i = 0; i < N; i++) {
		if (board[r][i]) return false;
		if (board[i][c]) return false;
	}
	
	for (int i = 0; i < 4; i++) {
		int dr = diag[i];
		int dc = diag[i + 1];

		int tr = r;
		int tc = c;

		while (tr + dr >= 0 && tr + dr < N && tc + dc >= 0 && tc + dc < N) {
			tr += dr;
			tc += dc;

			if (board[tr][tc]) return false;
		}
	}

	return true;
}

void func(int n) {
	if (n == N) {
		result++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (check(n, i)) {
			board[n][i] = true;
			func(n + 1);
			board[n][i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	func(0);

	cout << result;

	return 0;
}