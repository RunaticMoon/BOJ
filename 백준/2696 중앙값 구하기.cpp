#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int T, M, v;
priority_queue<int, vector<int>, less<int>> bgpq;
priority_queue<int, vector<int>, greater<int>> smpq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> M;
		cout << (M + 1) / 2 << "\n";
		for (int i = 0; i < M; i++) {
			cin >> v;

			if (i == 0) smpq.push(v);
			else {
				const int& mid = smpq.top();

				if (mid > v) bgpq.push(v);
				else smpq.push(v);

				if (smpq.size() > bgpq.size() + 1) {
					bgpq.push(smpq.top());
					smpq.pop();
				}
				else if (smpq.size() < bgpq.size() + 1) {
					smpq.push(bgpq.top());
					bgpq.pop();
				} 
			}

			if (i % 2 == 0) cout << smpq.top() << " ";
			if (i % 20 == 18) cout << "\n";
		}
		cout << "\n";
		
		priority_queue<int, vector<int>, less<int>>().swap(bgpq);
		priority_queue<int, vector<int>, greater<int>>().swap(smpq);
	}

	return 0;
}