#include <iostream>
#include <cmath>
using namespace std;

int A, B, V;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> V;

	cout << (int)ceil(((double)V - A) / (A - B)) + 1;

	return 0;
}