#include <iostream>
#include <set>
using namespace std;

int N, v, sum;
multiset<int> ms;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v;
		ms.insert(v);
	}

	for (auto& t : ms) {
		sum += t * N--;
	}

	cout << sum;

	return 0;
}