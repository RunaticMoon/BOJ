#include <iostream>
#include <cmath>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 2; N != 1; i++) {
		while (N % i == 0) {
			cout << i << '\n';
			N /= i;
		}
	}

	return 0;
}