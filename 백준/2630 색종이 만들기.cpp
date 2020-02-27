#include <iostream>
using namespace std;

int N;
bool paper[129][129];
int blue, white;
bool arrow[] = { 0, 1, 1, 0, 0 };

void func(int r, int c, int n) {
	bool color = paper[r][c];
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (color != paper[i][j]) {
				int sn = n / 2;
				for (int k = 0; k < 4; k++) {
					func(r + sn * arrow[k], c + sn * arrow[k + 1], sn);
				}
				return;
			}
		}
	}

	if (color) blue++;
	else white++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	func(0, 0, N);

	cout << white << "\n"
		<< blue;

	return 0;
}