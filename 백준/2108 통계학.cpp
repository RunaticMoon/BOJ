#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 5e5 + 1;
const int MAX_NUM = 8e3 + 1;

int N;
int arr[MAX];
pii cnt[MAX_NUM];
double sum;

bool comp(const pii& a, const pii& b) {
	if (a.first == b.first)
		return a.second < b.second;
	else return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < MAX_NUM; i++) {
		cnt[i] = { 0, i - 4000 };
	}

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];

		cnt[arr[i] + 4000].first++;
	}

	sort(arr, arr + N);
	sort(cnt, cnt + MAX_NUM, comp);

	cout << fixed << setprecision(0);
	cout << sum / N << '\n';
	cout << arr[N / 2] << '\n';
	if (cnt[0].first == cnt[1].first)
		cout << cnt[1].second << '\n';
	else
		cout << cnt[0].second << '\n';
	cout << arr[N - 1] - arr[0];

	return 0;
}