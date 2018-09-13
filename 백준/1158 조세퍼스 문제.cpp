#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
	int N, M;
	list<int> circle;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		circle.push_back(i);
	}

	list<int>::iterator cur = circle.begin();
	cout << "<";
	while (!circle.empty()) {
		for (int i = 1; i < M; i++) {
			if (cur == circle.end()) {
				cur = circle.begin();
			}
			cur++;
		}
		if (cur == circle.end()) {
			cur = circle.begin();
		}
		cout << *cur;
		circle.erase(cur++);


		if (!circle.empty())
			cout << ", ";
	}
	cout << ">";

	return 0;
}