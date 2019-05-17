/*
	분류: 수학
*/
#include <iostream>
using namespace std;

typedef long long ll;
const int divSize = 1e9 + 7;
const int maxN = 1e6 + 1;

int N, M;
ll fact[maxN];

ll mul(ll a, ll b) {
	ll ans = 1;
	while (b > 0) {
		if (b % 2 != 0) {
			ans *= a;
			ans %= divSize;
		}
		a *= a;
		a %= divSize;
		b /= 2;
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = (i * fact[i - 1]) % divSize;
	}

	cout << (fact[N] * mul((fact[M] * fact[N - M]) % divSize, divSize - 2)) % divSize;

	return 0;
}