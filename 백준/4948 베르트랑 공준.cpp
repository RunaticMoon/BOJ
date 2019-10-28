#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 3 * 1e5;

int n, prime;
bool erathos[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(erathos, true, sizeof(erathos));
	erathos[0] = false;
	erathos[1] = false;
	for (int i = 2; i < MAX; i++) {
		if (erathos[i]) {
			for (int j = 2; i*j < MAX; j++) {
				erathos[i*j] = false;
			}
		}
	}

	while (cin >> n, n != 0) {
		prime = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (erathos[i]) {
				prime++;
			}
		}
		cout << prime << '\n';
	}

	return 0;
}