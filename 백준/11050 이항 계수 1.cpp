#include <iostream>
using namespace std;

int N, K;
int u, b1, b2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	u = 1; 
	for (int i = 1; i <= N; i++) {
		u *= i;
	}

	b1 = 1;
	for (int i = 1; i <= K; i++) {
		b1 *= i;
	}

	b2 = 1;
	for (int i = 1; i <= N - K; i++) {
		b2 *= i;
	}

	cout << u / (b1*b2);

	return 0;
}