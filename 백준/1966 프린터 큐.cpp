#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1e2 + 1;

int T;
int N, M;
int prio[MAX];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> prio[i];
			q.push(i);
		}

		int doc = -1;
		do {
			int p = prio[q.front()];
			if (p == *max_element(prio, prio + N)) {
				doc = q.front();
				prio[doc] = -1;
			}
			else {
				q.push(q.front());
			}

			q.pop();
		} while (doc != M);

		cout << N - q.size() << '\n';

		while (!q.empty()) q.pop();
	}

	return 0;
}