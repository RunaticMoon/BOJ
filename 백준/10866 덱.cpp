#include <iostream>
#include <string>
using namespace std;

template<class T>
class deque {
public:
	deque() : capacity(10000), left(5000), right(5000) {
		arr = new T[capacity];
	}
	~deque() {
		delete[] arr;
	}

	void push_front(T x) {
		_size++;
		arr[left--] = x;

		if (left == -1) 
			left = capacity - 1;
		if (_size == 1)
			right++;
	}
	void push_back(T x) {
		_size++;
		arr[right++] = x;

		if (right == capacity) 
			right = 0;
		if (_size == 1)
			left--;
	}
	T pop_front() {
		if (empty()) return -1;
		else {
			_size--;
			if (_size == 0)
				right--;

			if (++left == capacity)
				left = 0;

			return arr[left];
		}
	}
	T pop_back() {
		if (empty()) return -1;
		else {
			_size--;
			if (_size == 0)
				left++;

			if (--right == -1)
				right = capacity - 1;

			return arr[right];
		}
	}
	size_t size() const {
		return _size;
	}
	bool empty() const {
		if (_size == 0) return true;
		else return false;
	}
	T front() const {
		if (empty()) return -1;
		else return arr[left + 1];
	}
	T back() const {
		if (empty()) return -1;
		else return arr[right - 1];
	}
private:
	T* arr;
	size_t capacity, _size;
	int left, right;
};

int N, v;
string cmd;
deque<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cmd;

		if (cmd == "push_back") {
			cin >> v;
			q.push_back(v);
		}
		else if (cmd == "push_front") {
			cin >> v;
			q.push_front(v);
		}
		else if (cmd == "pop_back") {
			cout << q.pop_back() << '\n';
		}
		else if (cmd == "pop_front") {
			cout << q.pop_front() << '\n';
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