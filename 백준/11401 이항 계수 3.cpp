/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
using namespace std;

unsigned long long Answer;
const unsigned long long divsize = 1000000007;
unsigned long long *fact = new unsigned long long[4000001];

unsigned long long mul(unsigned long long x, unsigned long long y, unsigned long long p) {
	unsigned long long ans = 1;
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

unsigned long long comb(unsigned long long n, unsigned long long r) {
	return (fact[n] * (mul((fact[r] * fact[n - r]) % divsize, divsize - 2, divsize) % divsize)) % divsize;
}


void set_factorial(unsigned long long n) {
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

	set_factorial(4000000);

	cin >> indexN >> indexM;

	Answer = comb(indexN, indexM);
	Answer %= divsize;

	cout << Answer << endl;

	return 0;
}