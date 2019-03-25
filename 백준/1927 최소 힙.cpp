#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int N, v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v;

		if (v == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		} 
		else {
			pq.push(v);
		}
	}

	return 0;
}