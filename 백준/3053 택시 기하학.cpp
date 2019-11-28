#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r;

	cout << fixed << setprecision(6);
	cout << M_PI * r * r << '\n';
	cout << 2.0 * r * r;

	return 0;
}