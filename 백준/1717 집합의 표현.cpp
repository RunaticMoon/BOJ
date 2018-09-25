#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 1000001;
int N, M;
int a, b, c;
int tree[MAX_SIZE];

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

	memset(tree, -1, sizeof(tree));

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;

		if (a == 0) {
			merge(b, c);
		}
		else if (a == 1) {
			b = finds(b);
			c = finds(c);

			if (b == c)
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}

	return 0;
}