#include <iostream>
using namespace std;

int main() {
	int L, P, V, day;

	for (int T = 1;; T++) {
		cin >> L >> P >> V;

		if (L == 0 && P == 0 && V == 0)
			break;

		day = 0;
		while (V > 0) {
			if (V - P >= 0) {
				V -= P;
				day += L;
			}
			else {
				if (V > L) {
					day += L;
				}
				else {
					day += V;
				}
				V = 0;
			}
		}

		cout << "Case " << T << ": " << day << endl;
	}

	return 0;
}