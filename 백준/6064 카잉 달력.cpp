#include <iostream>
#include <cmath>
using namespace std;

int T;
int M, N, x, y;
bool flag;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> M >> N >> x >> y;
		
		if (y == N) y = 0;
		flag = true;
		for (int i = 0; x + M * i < M*N; i++) {
			if ((x + M * i) % N == y) {
				cout << x + M * i << "\n";
				flag = false;
				break;
			}
		}

		if (flag) cout << -1 << "\n";
	}

	return 0;
}