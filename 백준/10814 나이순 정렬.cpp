#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int, string> pis;

const int MAX = 1e5 + 1;

bool comp(const pis& a, const pis& b) {
	return a.first < b.first;
}

int N;
pis member[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> member[i].first >> member[i].second;
	}

	// stable_sort: 같은 수에 대해서 입력순서를 보장
	stable_sort(member, member + N, comp);

	for (int i = 0; i < N; i++) {
		cout << member[i].first << ' ' << member[i].second << '\n';
	}

	return 0;
}