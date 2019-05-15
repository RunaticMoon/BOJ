/*
	분류: 기초
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e3 + 1;

int arr[MAX][MAX];
int N, a, b, v, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> a >> b;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		m = max(m, arr[a - 1][i]);
		m = max(m, arr[i][b - 1]);
	}

	cout << ((m == arr[a - 1][b - 1]) ? "HAPPY" : "ANGRY");

	return 0;
}