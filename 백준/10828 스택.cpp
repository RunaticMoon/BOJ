#include <iostream>
#include <string>
using namespace std;

int N, temp, _size, arr[10000];
string str;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		if (str == "push") {
			cin >> arr[_size++];
		}
		else if (str == "pop") {
			cout << ((_size == 0) ? -1 : arr[--_size]) << endl;
		}
		else if (str == "top") {
			cout << ((_size == 0) ? -1 : arr[_size - 1]) << endl;
		}
		else if (str == "size") {
			cout << _size << endl;
		}
		else if (str == "empty") {
			cout << ((_size == 0) ? 1 : 0) << endl;
		}
	}

	return 0;
}