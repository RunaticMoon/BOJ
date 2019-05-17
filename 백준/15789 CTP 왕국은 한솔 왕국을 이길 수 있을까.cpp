/*
	ºÐ·ù: Disjoint-set(Union Find)
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1e5 + 1;

int N, M, C, H, K;
int x, y;
int tree[MAX];
vector<int> fpower;

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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	memset(tree, -1, sizeof(tree));

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		merge(x, y);
	}
	for (int i = 1; i <= N; i++) {
		finds(i);
	}

	cin >> C >> H >> K;

	int u = finds(C);
	int v = finds(H);
	int power = count(tree + 1, tree + N + 1, u) + 1;

	for (int i = 1; i <= N; i++) {
		if (tree[i] == -1 && i != u && i != v) {
			fpower.push_back(count(tree + 1, tree + N + 1, i) + 1);
		}
	}

	sort(fpower.rbegin(), fpower.rend());

	for (int i = 0; i < K; i++) {
		power += fpower[i];
	}

	cout << power;

	return 0;
}