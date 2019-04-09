#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> tiii;

const int MAX = 10001;
int N, p, l, r, root;
int pidx = 1;
tiii tree[MAX];
int levelWidth[MAX][2];
int level;

void inorder(int parent) {
	tiii& n = tree[parent];

	if (get<1>(n) != -1) {
		level++;
		inorder(get<1>(n));
		level--;
	}

	pidx++;

	if (levelWidth[level][0] == 0) levelWidth[level][0] = pidx - 1;
	else levelWidth[level][0] = min(levelWidth[level][0], pidx - 1);
	levelWidth[level][1] = max(levelWidth[level][1], pidx - 1);

	if (get<2>(n) != -1) {
		level++;
		inorder(get<2>(n));
		level--;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p >> l >> r;
		get<1>(tree[p]) = l;
		get<2>(tree[p]) = r;

		get<0>(tree[l]) = p;
		get<0>(tree[r]) = p;
	}

	// 루트찾기
	for (int i = 1; i <= N; i++) {
		if (get<0>(tree[i]) == 0) {
			root = i;
			break;
		}
	}

	level = 1;
	inorder(root);

	int maxIdx = 0;
	int maxValue = 0;
	for (int i = 1;; i++) {
		int& lp = levelWidth[i][0];
		int& rp = levelWidth[i][1];

		if (lp == 0 && rp == 0) break;

		if (rp - lp + 1 > maxValue) {
			maxIdx = i;
			maxValue = rp - lp + 1;
		}
	}

	cout << maxIdx << " " << maxValue;

	return 0;
}