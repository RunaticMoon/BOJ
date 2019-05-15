/*
	분류: Bit Masking
	구조: 
	21 20 ... 1 0
	x  사용     x
*/
#include <iostream>
using namespace std;

const int MAX = 1e5 + 1;

int N, M, cnt;
int op, idx, x;
int bst[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> op >> idx;

		switch (op) {
		case 1:
			cin >> x;
			bst[idx] |= (1 << x);
			break;
		case 2:
			cin >> x;
			bst[idx] &= ~(1 << x);
			break;
		case 3:
			bst[idx] <<= 1;
			bst[idx] &= ~(1 << 21);
			break;
		case 4:
			bst[idx] >>= 1;
			bst[idx] &= ~(1 << 0);
			break;
		}
	}

	for (int i = 1; i <= N; i++) {
		bool flag = true;
		for (int j = i - 1; j > 0; j--) {
			if (bst[i] == bst[j]) {
				flag = false;
				break;
			}
		}

		if (flag) cnt++;
	}

	cout << cnt;

	return 0;
}