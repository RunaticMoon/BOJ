#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, sum;
	queue<int> que;

	while (true) {
		cin >> n;

		if (n == -1) {
			return 0;
		}

		sum = 0;
		for (int i = 1; i < n; ++i) {
			if (n % i == 0) {
				sum += i;
				que.push(i);
			}
		}

		cout << n;
		if (sum == n) {
			cout << " = ";
			int max = que.size();
			for (int i = 0; i < max; ++i) {
				cout << que.front();
				que.pop();
				if (que.size() != 0) {
					cout << " + ";
				}
			}
			cout << endl;
		}
		else {
			cout << " is NOT perfect." << endl;
			queue<int> empty;
			swap(que, empty);
		}
	}

	return 0;
}