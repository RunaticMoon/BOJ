#include <iostream>
using namespace std;

int idx, maxNum, v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 9; i++) {
		cin >> v;
		
		if (maxNum < v) {
			maxNum = v;
			idx = i;
		}
	}

	cout << maxNum << '\n';
	cout << idx << '\n';

	return 0;
}