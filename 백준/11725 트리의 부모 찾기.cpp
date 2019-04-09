#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, a, b;
vector<int> arr[100001];
int visited[100001];
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	visited[1] = -1;
	q.push(1);

	while (!q.empty()) {
		int idx = q.front();
		q.pop();
		
		for (const int& c : arr[idx]) {
			if (visited[c] == 0) {
				visited[c] = idx;
				q.push(c);
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << visited[i] << "\n";
	}

	return 0;
}