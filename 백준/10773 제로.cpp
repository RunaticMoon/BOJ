#include <iostream>
#include <stack>
using namespace std;

int K, v, sum;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> v;

		if (v == 0) s.pop();
		else s.push(v);
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}