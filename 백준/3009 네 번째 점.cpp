#include <iostream>
#include <algorithm>
using namespace std;

int x[3], y[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}

	for (int i = 0; i < 3; i++) {
		if (x[i]) {
			for (int j = i + 1; j < 3; j++) {
				if (x[i] == x[j]) {
					x[i] = 0;
					x[j] = 0;
				}
			}
		}
		if (y[i]) {
			for (int j = i + 1; j < 3; j++) {
				if (y[i] == y[j]) {
					y[i] = 0;
					y[j] = 0;
				}
			}
		}
	}

	sort(x, x + 3);
	sort(y, y + 3);

	cout << x[2] << ' ' << y[2];

	return 0;
}