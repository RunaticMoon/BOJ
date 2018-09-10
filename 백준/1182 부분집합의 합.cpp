#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int arr[20];
int result = 0;

void func(vector<int> list) {
	int sum = 0;
	for (auto i : list) {
		sum += arr[i];
	}
	
	if (sum == S) {
		result++;
	}

	for (int i = list.back(); i < N; i++) {
		if (find(list.begin(), list.end(), i) == list.end()) {
			vector<int> temp(list);
			temp.push_back(i);
			func(temp);
		}
	}
}

int main() {
	// N 1 ~ 20, S -1000000 ~ 1000000

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	
	for (int i = 0; i < N; i++) {
		vector<int> list;
		list.push_back(i);
		func(list);
	}

	cout << result;

	return 0;
}