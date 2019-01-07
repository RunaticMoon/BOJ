#include <iostream>
using namespace std;

int main() {
	int L, P, V;
	int count = 0;

	for (int i = 1;; i++, count = 0) {
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0) break;

		while (V != 0) {
			if (V >= P) {
				count += L;
				V -= P;
			}
			else {
				count += (V >= L) ? L : V;
				V = 0;
			}
		}
		cout << "Case " << i << ": " << count << endl;
	}

	return 0;
}