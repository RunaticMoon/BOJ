#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX = 1e4 + 1;

int T, n;
bool erathos[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(erathos, true, sizeof(erathos));
	erathos[0] = false;
	erathos[1] = false;
	for (int i = 2; i < sqrt(MAX); i++) {
		if (erathos[i]) {
			for (int j = 2; i*j < MAX; j++) {
				erathos[i*j] = false;
			}
		}
	}

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;

		bool flag = false;
		for (int i = 2; i < MAX; i++) {
			if (erathos[i]) {
				if (i + i < n) continue;

				for (int j = i; j >= 2; j--) {
					if (erathos[j]) {
						if (i + j < n) break;

						if (i + j == n) {
							cout << j << ' ' << i << '\n';
							flag = true;
							break;
						}
					}
				}

				if (flag) break;
			}
		}
	}

	return 0;
}