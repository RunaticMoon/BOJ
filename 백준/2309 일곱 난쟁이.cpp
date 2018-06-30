#include <iostream>
#include <algorithm>
using namespace std;

int tall[9];

int main() {
	int sum;
	bool bflag = false;

	for (int i = 0; i < 9; ++i) {
		cin >> tall[i];
	}

	for (int i = 0; i < 8; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			sum = 0;

			for (int k = 0; k < 9; ++k) {
				if (k != i && k != j) {
					sum += tall[k];
				}
			}
			if (sum == 100) {
				tall[i] = 0;
				tall[j] = 0;
				bflag = true;
			}

			if (bflag) break;
		}
		if (bflag) break;
	}

	sort(tall, tall + 9);
	for (int i = 2; i < 9; ++i) {
		cout << tall[i] << endl;
	}

	return 0;
}