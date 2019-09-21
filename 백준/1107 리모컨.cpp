#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxN = 1e6 + 1;

int N, M, v;
bool btn[10];
int result;

bool check(int n) {
	bool result = true;
	do {
		if (!btn[n % 10]) {
			result = false;
			break;
		}
		n /= 10;
	} while (n != 0);
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(btn, btn + 10, true);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> v;
		btn[v] = false;
	}

	result = abs(N - 100);

	int digits = 1;
	for (int i = 0; i < maxN; i++) {
		if (i >= pow(10, digits)) digits++;
		if (check(i)) {
			result = min(result, abs(N - i) + digits);
		}
	}
	
	cout << result;

	return 0;
} 