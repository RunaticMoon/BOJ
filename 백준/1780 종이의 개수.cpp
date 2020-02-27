#include <iostream>
using namespace std;

const int MAX = 3*3*3*3*3*3*3 + 1;

int N;
int paper[MAX][MAX];
int result[3];

void func(int r, int c, int n) {
	if (n == 0) return;

	int num = paper[r][c];
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (num != paper[i][j]) {
				int sn = n / 3;
				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						func(r + sn * a, c + sn * b, sn);
					}
				}
				return;
			}
		}
	}

	result[num + 1]++;
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
	for (int i = 0; i < 3; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}