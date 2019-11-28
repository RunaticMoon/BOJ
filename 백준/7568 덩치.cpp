#include <iostream>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 51;

int N;
pii human[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> human[i].first >> human[i].second;
	}

	for (int i = 0; i < N; i++) {
		const int& w = human[i].first;
		const int& h = human[i].second;

		int rank = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			const int& ow = human[j].first;
			const int& oh = human[j].second;

			if (w < ow && h < oh)
				rank++;
		}

		cout << rank + 1 << ' ';
	}

	return 0;
}