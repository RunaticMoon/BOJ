#include <iostream>
using namespace std;

// 원랜 중국인의 나머지 정리 문제...
int main() {
	int E = 1, S = 1, M = 1;
	// E : 1~15, S : 1~28, M : 1~19

	int a, b, c, n = 1;

	cin >> a >> b >> c;

	while (true) {
		if (E == a && S == b && M == c)
			break;
		
		n++;
		E++;
		S++;
		M++;
		if (E > 15) E = 1;
		if (S > 28) S = 1;
		if (M > 19) M = 1;
	}

	cout << n;

	return 0;
}