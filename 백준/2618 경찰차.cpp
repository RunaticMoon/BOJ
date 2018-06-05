#include <iostream>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;
typedef tuple<int, int, bool> tiib;

int dp[1003][1003];
tiib point[1003];
int N, W, a, b;

int func(int x, int y, int cnt) {
	int &ret = dp[x][y];
	if (ret != -1)
		return ret;

	if (cnt == W)
		return ret = 0;

	int gox = func(cnt, y, cnt + 1) + abs(get<0>(point[cnt]) - get<0>(point[x])) + abs(get<1>(point[cnt]) - get<1>(point[x]));
	int goy = func(x, cnt, cnt + 1) + abs(get<0>(point[y]) - get<0>(point[cnt])) + abs(get<1>(point[y]) - get<1>(point[cnt]));

	return ret = min(gox, goy);
}

void track(int x, int y, int cnt) {
	if (cnt == W)
		return;

	int gox = dp[cnt][y] + abs(get<0>(point[cnt]) - get<0>(point[x])) + abs(get<1>(point[cnt]) - get<1>(point[x]));
	int goy = dp[x][cnt] + abs(get<0>(point[y]) - get<0>(point[cnt])) + abs(get<1>(point[y]) - get<1>(point[cnt]));

	if (gox <= goy) {
		get<2>(point[cnt]) = true;
		track(cnt, y, cnt + 1);
	}
	else {
		get<2>(point[cnt]) = false;
		track(x, cnt, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> N >> W;

	W += 2;

	point[0] = make_tuple(1, 1, false);
	point[1] = make_tuple(N, N, false);
	for (int i = 2; i < W; ++i) {
		cin >> a >> b;
		point[i] = make_tuple(a, b, false);
	}

	cout << func(0, 1, 2) << endl;

	track(0, 1, 2);
	for (int i = 2; i < W; ++i) {
		if (get<2>(point[i])) {
			cout << 1 << endl;
		}
		else {
			cout << 2 << endl;
		}
	}

	return 0;
}