/*
	분류: 그리디
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, h, v, temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		h = max(h, temp);
	}
	for (int i = 0; i < M; i++) {
		cin >> temp;
		v = max(v, temp);
	}

	cout << h + v;

	return 0;
}