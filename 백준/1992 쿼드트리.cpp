#include <iostream>
#include <string>
using namespace std;

const int MAX = 65;

int N;
string str, result;
bool video[MAX][MAX];

void func(int r, int c, int n) {
	if (n == 0) return;

	bool point = video[r][c];
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (point != video[i][j]) {
				result += "(";
				func(r, c, n / 2);
				func(r, c + n / 2, n / 2);
				func(r + n / 2, c, n / 2);
				func(r + n / 2, c + n / 2, n / 2);
				result += ")";
				return;
			}
		}
	}
	result += point + '0';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;

		for (int j = 0; j < N; j++) {
			video[i][j] = str[j] - '0';
		}
	}

	func(0, 0, N);
	cout << result;

	return 0;
}