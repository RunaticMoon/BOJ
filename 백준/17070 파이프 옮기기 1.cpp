#include <iostream>
using namespace std;

int N, v, result;
bool house[17][17];
enum class Status {
	HOR,
	VER,
	DIA
};

void dfs(int r, int c, Status status) {
	if (r == N && c == N) {
		result++;
		return;
	}

	if ((status == Status::HOR || status == Status::DIA) &&
		c + 1 <= N && !house[r][c + 1]) {
		dfs(r, c + 1, Status::HOR);
	}
	if ((status == Status::VER || status == Status::DIA) &&
		r + 1 <= N && !house[r + 1][c]) {
		dfs(r + 1, c, Status::VER);
	}
	if (r + 1 <= N && c + 1 <= N &&
		!house[r + 1][c] && !house[r][c + 1] && 
		!house[r + 1][c + 1]) {
		dfs(r + 1, c + 1, Status::DIA);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> house[i][j];
		}
	}

	dfs(1, 2, Status::HOR);

	cout << result;

	return 0;
}