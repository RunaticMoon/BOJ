#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int N, a, b, sum;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		pq.push(a);
	}

	if (N == 1) {
		sum = 0;
		pq.pop();
	}

	while (!pq.empty()) {
		if (pq.size() == 1) {
			pq.pop();
		}
		else {
			a = pq.top();
			pq.pop();
			b = pq.top();
			pq.pop();
			sum += a + b;
			pq.push(a + b);
		}
	}

	cout << sum << "\n";

	return 0;
}