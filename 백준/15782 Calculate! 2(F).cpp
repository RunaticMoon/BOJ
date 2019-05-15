/*
	�з�:Segment Tree + Lazy Propagation
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxN = 1e6 + 1;

struct Node {
	int weight;					// ����ġ
	int lazy;					// lazy��
	int value;					// ����Ʈ���� xor��
	int size;					// �ڽ��� ������ ����Ʈ���� ��尳��
	vector<Node *> children;	// �ڽ�
	Node* parent;				// �θ�

	// ������
	Node() {
		weight = 0;
		lazy = 0;
		value = 0;
		size = 0;
		parent = nullptr;
	}
};

int N, M, D, mid;
int op, x, y;
Node* tree[maxN];
vector<int> tree_maker[maxN];
bool used[maxN];
queue<int> q;

int init_value(Node* node) {
	if (node->children.empty()) return node->value = node->weight;

	int n = node->weight;
	for (auto v : node->children) {
		n ^= init_value(v);
		node->size += v->size + 1;
	}
	return node->value = n;
}

void update(Node* node, int lazy) {
	if (node->parent != nullptr) {
		node->parent->value ^= lazy;
		update(node->parent, lazy);
	}

	return;
}

void propagation(Node* node) {
	if (node->parent != nullptr) propagation(node->parent);

	if (node->lazy != 0) {
		if (node->children.empty()) {
			node->value ^= node->lazy;
			update(node, node->lazy);
			node->lazy = 0;
		}
		else {
			for (auto v : node->children) {
				v->lazy ^= node->lazy;
			}
			if (node->size % 2 == 0) {
				node->value ^= node->lazy;
			}
			node->lazy = 0;
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	// Ʈ���� ��� ����
	for (int i = 1; i <= N; i++) {
		tree[i] = new Node();
	}

	// �׷��� ������踮��Ʈ ����
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		tree_maker[x].push_back(y);
		tree_maker[y].push_back(x);
	}

	// Ʈ�� ����
	used[1] = true;
	q.push(1);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vector<int>& ret = tree_maker[v];

		for (int node : ret) {
			if (!used[node]) {
				used[node] = true;
				q.push(node);
				tree[v]->children.push_back(tree[node]);
				tree[node]->parent = tree[v];
			}
		}
	}

	// ����ġ ����
	for (int i = 1; i <= N; i++) {
		cin >> D;
		tree[i]->weight = D;
	}

	// xor�� ���
	init_value(tree[1]);

	// ���� �Է�
	for (int i = 0; i < M; i++) {
		cin >> op >> x;
		if (op == 1) {
			propagation(tree[x]);

			cout << tree[x]->value << "\n";
		}
		else if (op == 2) {
			cin >> y;

			tree[x]->lazy ^= y;
			if (tree[x]->children.empty()) {
				tree[x]->value ^= y;
				update(tree[x], tree[x]->lazy);
				tree[x]->lazy = 0;
			}
		}
	}

	return 0;
}