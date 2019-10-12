#include <iostream>
#include <cmath>
using namespace std;

int T;
int x, y, dis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> x >> y;

		dis = y - x;
		int idx = ceil(sqrt(dis));
		if (dis > idx * (idx - 1)) {
			cout << 2 * idx - 1 << '\n';
		}
		else {
			cout << 2 * idx - 2 << '\n';
		}
	}

	return 0;
}