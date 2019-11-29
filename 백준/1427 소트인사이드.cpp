#include <iostream>
using namespace std;

int cnt[10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char c;

	// Counting Sort
	while ((c = cin.get()) != EOF) {
		cnt[c - '0']++;
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < cnt[i]; j++) {
			cout << i;
		}
	}

	return 0;
}