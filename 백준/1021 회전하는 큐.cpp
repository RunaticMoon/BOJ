#include <iostream>
#include <algorithm>
using namespace std;

// 자료구조 연습용 큐 구현
template<typename T>
class CircularQueue {
private:
	struct Node {
		T data;
		Node* prev;
		Node* next;
	};
	Node* head;
	int _size;
public:
	CircularQueue() {
		head = nullptr;
		_size = 0;
	}

	void push(T val) {
		Node* temp = new Node;
		temp->data = val;

		if (empty()) {
			temp->prev = temp;
			temp->next = temp;
			head = temp;
		}
		else {
			head->prev->next = temp;
			temp->prev = head->prev;

			temp->next = head;
			head->prev = temp;
		}
		_size++;
	}
	T pop() {
		if (empty())
			cout << "pop을 할 수 없습니다." << endl;

		Node* temp = head;
		head = temp->next;

		T v = temp->data;

		_size--;
		if (empty()) {
			head = nullptr;
		}
		else {
			temp->prev->next = head;
			head->prev = temp->prev;
		}

		delete temp;
		return v;
	}

	T front() const {
		return head->data;
	}
	int size() const {
		return _size;
	}
	bool empty() const {
		return (_size == 0);
	}

	void next() {
		head = head->next;
	}
	void prev() {
		head = head->prev;
	}
};


int main() {
	CircularQueue<int> que;
	int N, M, num, result;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		que.push(i);
	}

	result = 0;
	for (int i = 0; i < M; i++) {
		cin >> num;

		if (que.front() == num) {
			que.pop();
		}
		else {
			int pos = 0;

			while (que.front() != num) {
				que.next();
				pos++;
			}

			result += min(pos, que.size() - pos);
			que.pop();
		}
	}

	cout << result;

	return 0;
}