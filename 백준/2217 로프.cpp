#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, maxNum;
vector<int> rope;

int main() {
	cin >> N;

	rope.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> rope[i];
	}

	sort(rope.rbegin(), rope.rend() - 1);

	for (int i = 1; i <= N; i++) {
		if (maxNum < rope[i] * i) {
			maxNum = rope[i] * i;
		}
	}

	cout << maxNum;

	return 0;
}