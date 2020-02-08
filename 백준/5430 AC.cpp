#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXP = 1e5 + 1;

int T;
int p;
string cmd, value;

class Queue {
public:
	Queue(int _size, string v)
		: size(_size),
		  front(0),
		  back(_size - 1),
		  reversed(false)
	{
		size_t bef = 1;
		for (int i = 0; i < size; i++) {
			size_t pos = v.find(',', bef);
			if (pos == string::npos) {
				arr[i] = stoi(v.substr(bef, v.size() - bef - 1));
			}
			else {
				arr[i] = stoi(v.substr(bef, pos - bef));
			}
			bef = pos + 1;
		}
	}

	void drop() {
		size--;
		if (reversed) back--;
		else front++;
	}

	void reverse() {
		reversed = !reversed;
	}

	void print() {
		if (size < 0) cout << "error" << '\n';
		else {
			cout << '[';
			if (reversed) {
				for (int i = 0; i < size; i++) {
					cout << arr[back - i];
					if (i != size - 1)
						cout << ',';
				}
			}
			else {
				for (int i = 0; i < size; i++) {
					cout << arr[front + i];
					if (i != size - 1)
						cout << ',';
				}
			}
			cout << ']' << '\n';
		}
	}

private:
	int arr[MAXP];
	int size;
	int front, back;
	bool reversed;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> cmd;
		cin >> p;
		cin >> value;

		Queue q(p, value);

		for (auto& ch : cmd) {
			switch (ch) {
			case 'R':
				q.reverse();
				break;
			case 'D':
				q.drop();
				break;
			}
		}

		q.print();
	}

	return 0;
}
