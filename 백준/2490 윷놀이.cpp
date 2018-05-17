#include <iostream>
using namespace std;

int main() {
	char StringYut[5] = { 'D', 'C', 'B', 'A', 'E' };
	int n, sum[3];

	for (int i = 0; i < 3; ++i) {
		sum[i] = 0;
		for (int j = 0; j < 4; ++j) {
			cin >> n;
			sum[i] += n;
		}
	}

	for (int i = 0; i < 3; ++i) {
		cout << StringYut[sum[i]] << '\n';
	}

	return 0;
}