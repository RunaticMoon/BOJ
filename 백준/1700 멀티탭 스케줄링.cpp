#include <iostream>
using namespace std;

int N, K, counter;
int plug[101], arr[101];
bool check[101];

int main() {
	cin >> N >> K;

	for (int i = 1; i <= K; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= K; i++) {
		// �÷��׿� ���� ������ ���
		if (check[arr[i]]) continue;

		// �÷��װ� ��������� �ȱ�
		for (int j = 1; j <= N; j++) {
			if (plug[j] == 0) {
				plug[j] = arr[i];
				check[arr[i]] = true;
				break;
			}
		}

		// �÷��׿� ���� ������ ���
		if (check[arr[i]]) continue;

		// �÷��׸� ���� �װ��� �ȱ�
		int idx, tidx = -1;
		for (int j = 1; j <= N; j++) {
			int lastidx = 0;
			for (int k = i + 1; k <= K; k++) {
				if (arr[k] == plug[j]) break;
				lastidx++;
			}

			if (lastidx > tidx) {
				idx = j;
				tidx = lastidx;
			}
		}

		check[plug[idx]] = false;
		plug[idx] = arr[i];
		check[arr[i]] = true;
		counter++;
	}

	cout << counter;

	return 0;
}