#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

bool endUpper(pii a, pii b) {
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main() {
	int N, start, end, count;
	vector<pii> arr;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		arr.push_back({ start, end });
	}

	sort(arr.begin(), arr.end(), endUpper);
	
	end = 0;
	count = 0;
	for (auto v : arr) {
		if (end <= v.first) {
			end = v.second;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}