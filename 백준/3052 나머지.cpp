#include <iostream>
#include <set>
using namespace std;

set<int> dup;
int v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> v;
		dup.insert(v % 42);
	}
	
	cout << dup.size();

	return 0;
}