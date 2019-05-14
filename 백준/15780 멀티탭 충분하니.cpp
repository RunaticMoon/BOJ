/*
	분류: 기초
*/
#include <iostream>
using namespace std;

int N, K, A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> A;

		N -= (A + 1) / 2;
	}

	cout << ((N > 0) ? "NO" : "YES") << "\n";

	return 0;
}