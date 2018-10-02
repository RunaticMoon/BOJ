#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int city[201];
set<int> plan;

int finds(int u) {
	if (city[u] == -1)
		return u;

	return city[u] = finds(city[u]);
}

void merge(int u, int v) {
	u = finds(u);
	v = finds(v);
	if (u == v)
		return;

	city[v] = u;
}

int main() {
	int N, M, n;
	memset(city, -1, sizeof(city));

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			if (j >= i + 1 && i != N - 1) {
				if (n == 1) {
					merge(i + 1, j + 1);
				}
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> n;
		plan.insert(n);
	}

	int check = finds(*plan.begin());
	bool flag = true;
	for (auto p : plan) {
		if (check != finds(p)) {
			flag = false;
		}
	}

	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}