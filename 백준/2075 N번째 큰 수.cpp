#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

priority_queue<int, vector<int>, greater<int>> arr;
int N, v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v;
			if (i == 0) {
				arr.push(v);
				continue;
			}

			if (v > arr.top()) {
				arr.pop();
				arr.push(v);
			}
		}
	}

	cout << arr.top();

	return 0;
}