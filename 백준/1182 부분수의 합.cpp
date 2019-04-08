#include <iostream>
#include <vector>
using namespace std;

int N, S;
int arr[21];
int result;

void func(vector<int> list) {
	int sum = 0;

	for (int& n : list) {
		sum += arr[n];
	}

	if (sum == S) {
		result++;
	}

	for (int i = *list.rbegin() + 1; i <= N; i++) {
		vector<int> temp = list;
		temp.push_back(i);
		func(temp);
	}
}

int main() {
	cin >> N >> S;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		vector<int> temp;
		temp.push_back(i);
		func(temp);
	}

	cout << result;

	return 0;
}