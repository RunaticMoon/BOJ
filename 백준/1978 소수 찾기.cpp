#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e3 + 1;

int N, v, prime;
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

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v;
		if (erathos[v]) prime++;
	}

	cout << prime;

	return 0;
}