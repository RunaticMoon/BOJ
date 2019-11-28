#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

const int MAX = 1e6 + 4;

struct Point {
	int x, y;
};

struct Edge {
	int left, right;
	double weight;

	Edge() {
		left = -1;
		right = -1;
		weight = 0;
	}

	Edge(int left, int right, double weight) {
		this->left = left;
		this->right = right;
		this->weight = weight;
	}

	bool operator< (const Edge& b) {
		return weight < b.weight;
	}
};

int N, M;
Point god[MAX];
int tree[MAX];
double result;
vector<Edge> v;

int finds(int u) {
	if (tree[u] == -1)
		return u;

	return tree[u] = finds(tree[u]);
}

bool merge(int u, int v) {
	u = finds(u);
	v = finds(v);
	if (u == v)
		return false;

	tree[v] = u;

	return true;
}

double len(int i, int j) {
	int x = god[i].x - god[j].x;
	int y = god[i].y - god[j].y;

	return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;

	fill(tree, tree + MAX, -1);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> god[i].x >> god[i].y;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		merge(a, b);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			v.push_back(Edge(i, j, len(i, j)));
		}
	}

	sort(v.begin(), v.end());

	for (auto& e : v) {
		if (merge(e.left, e.right)) {
			result += e.weight;
		}
	}

	cout << fixed << setprecision(2);
	cout << result;

	return 0;
}