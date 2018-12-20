#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

bool startUpper(pii a, pii b) {
	return a.first < b.first;
}

/*
	200,000 x 200,000���� ���Ͽ� O(logn)���� �ؾߵ�
	�������� ������� �õ��ϴ� �ȵǾ �˻���� PQ��� �ȴٰ� ��
*/

int main() {
	int N, start, end;
	vector<pii> arr;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		arr.push_back({ start, end });
	}

	sort(arr.begin(), arr.end(), startUpper);

	pq.push(arr[0].second);
	for (int i = 1; i < N; i++) {
		if (arr[i].first < pq.top()) {
			pq.push(arr[i].second);
		}
		else {
			pq.pop();
			pq.push(arr[i].second);
		}
	}

	cout << pq.size() << endl;

	return 0;
}