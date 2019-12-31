#include <iostream>
#include <string>
using namespace std;

template<class T>
class queue {
public:
	queue() : capacity(10000), in(0), out(0) {
		arr = new T[capacity];
	}
	~queue() {
		delete[] arr;
	}

	void push(T x) {
		arr[in++] = x;
		_size++;
	}
	T pop() {
		if (empty()) return -1;
		else {
			_size--;
			return arr[out++];
		}
	}
	T size() const {
		return _size;
	}
	bool empty() const {
		if (_size == 0) return true;
		else return false;
	}
	T front() const {
		if (empty()) return -1;
		else return arr[out];
	}
	T back() const {
		if (empty()) return -1;
		else return arr[in - 1];
	}
private:
	T* arr;
	size_t capacity, _size;
	int in, out;
};

int N, v;
string cmd;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> v;
			q.push(v);
		}
		else if (cmd == "pop") {
			cout << q.pop() << '\n';
		}
		else if (cmd == "size") {
			cout << q.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << q.empty() << '\n';
		}
		else if (cmd == "front") {
			cout << q.front() << '\n';
		}
		else if (cmd == "back") {
			cout << q.back() << '\n';
		}
	}

	return 0;
}