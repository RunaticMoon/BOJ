#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b, v1, v2;
vector<int> arr[101];
queue<int> que;
vector<int> visited(101, -1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cin >> a >> b;

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;

		arr[v1].push_back(v2);
		arr[v2].push_back(v1);
	}

	visited[a] = 0;
	que.push(a);

	while (!que.empty()) {
		int v = que.front();
		que.pop();

		for (int i = 0; i < arr[v].size(); i++) {
			int& temp = arr[v][i];

			if (visited[temp] == -1) {
				visited[temp] = visited[v] + 1;
				que.push(temp);
			}
		}
	}

	cout << visited[b];

	return 0;
}