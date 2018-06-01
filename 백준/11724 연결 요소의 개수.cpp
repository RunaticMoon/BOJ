#include <iostream>
#include <vector>
using namespace std;


vector<int> tree;

int finds(int u) {
	if (tree[u] == -1)
		return u;

	return tree[u] = finds(tree[u]);
}

void merge(int u, int v) {
	u = finds(u);
	v = finds(v);
	if (u == v)
		return;

	tree[v] = u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, a, b;
	cin >> N >> M;

	tree.assign(N + 1, -1);


	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		merge(a, b);
	}

	int ans = 0;
	for (int i = 1; i < tree.size(); ++i) {
		if (tree[i] == -1)
			ans++;
	}

	cout << ans;

	return 0;
}