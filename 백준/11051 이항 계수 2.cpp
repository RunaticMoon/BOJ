#include <iostream>
using namespace std;

int Answer;
const int divsize = 10007;
int *fact = new int[1001];

int mul(int x, int y, int p) {
	int ans = 1;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}

int comb(int n, int r) {
	return (fact[n] * (mul((fact[r] * fact[n - r]) % divsize, divsize - 2, divsize) % divsize)) % divsize;
}


void set_factorial(int n) {
	fact[0] = 1;
	fact[1] = 1;
	fact[2] = 2;
	for (int i = 3; i <= n; ++i) {
		fact[i] = (i * fact[i - 1]) % divsize;
	}
}

int main()
{
	int indexN, indexM;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	set_factorial(1000);

	cin >> indexN >> indexM;

	Answer = comb(indexN, indexM);
	Answer %= divsize;

	cout << Answer << endl;

	return 0;
}