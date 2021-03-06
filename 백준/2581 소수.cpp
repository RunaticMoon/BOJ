#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1e4 + 1;

int N, M, minN, sum;
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

	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		if (erathos[i]) {
			if (minN == 0) minN = i;
			sum += i;
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << '\n' << minN;

	return 0;
} 