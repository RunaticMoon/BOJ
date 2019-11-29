#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 1e5 + 1;

int N;
pii arr[MAX];

bool comp(const pii& a, const pii& b) {
	if (a.first == b.first)
		return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, arr + N, comp);

	for (int i = 0; i < N; i++) {
		cout << arr[i].first << ' ' << arr[i].second << '\n';
	}

	return 0;
}