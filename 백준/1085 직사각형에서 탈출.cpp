#include <iostream>
#include <algorithm>
using namespace std;

int x, y, w, h;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x >> y >> w >> h;

	cout << min({ x, y, w - x, h - y });

	return 0;
}