/*
	분류:Segment Tree + Lazy Propagation
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxN = 1e6 + 1;

struct Node {
	int weight;					// 가중치
	int lazy;					// lazy값
	int value;					// 서브트리의 xor값
	int size;					// 자신을 제외한 서브트리의 노드개수
	vector<Node *> children;	// 자식
	Node* parent;				// 부모

	// 생성자
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

	// 트리의 노드 생성
	for (int i = 1; i <= N; i++) {
		tree[i] = new Node();
	}

	// 그래프 연결관계리스트 받음
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		tree_maker[x].push_back(y);
		tree_maker[y].push_back(x);
	}

	// 트리 생성
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

	// 가중치 설정
	for (int i = 1; i <= N; i++) {
		cin >> D;
		tree[i]->weight = D;
	}

	// xor값 계산
	init_value(tree[1]);

	// 질의 입력
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