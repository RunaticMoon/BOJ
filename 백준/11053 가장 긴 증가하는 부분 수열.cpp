#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e3 + 1;

int N, v;
vector<int> lis;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v;
		
		if (i == 0) 
			lis.push_back(v);
		else if (v > *lis.rbegin())
			lis.push_back(v);
		else 
			*lower_bound(lis.begin(), lis.end(), v) = v;
	}

	cout << lis.size();

	return 0;
}