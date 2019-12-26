#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 5e2 + 1;

int N, a, b;
vector<pii> v;
vector<pii> lis;

bool comp(const pii& a, const pii& b) {
	return a.second < b.second;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	for (auto& line : v) {
		if (lis.empty()) {
			lis.push_back(line);
			continue;
		}

		if (line.first > lis.rbegin()->first &&
			line.second > lis.rbegin()->second)
				lis.push_back(line);
		else
			*lower_bound(lis.begin(), lis.end(), line, comp) = line;
	}

	cout << N - lis.size();


	return 0;
}