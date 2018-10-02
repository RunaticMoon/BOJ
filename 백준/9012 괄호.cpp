#include <iostream>
#include <string>
using namespace std;

// 자료구조 연습용 스택 구현
template<typename T>
class Stack {
private:
	struct Node {
		T data;
		Node* next;
	};

	Node* head;
	int _size;
public:
	Stack() {
		head = nullptr;
		_size = 0;
	}
	~Stack() {
		clear();
	}

	void push(T val) {
		Node* temp = new Node;
		temp->data = val;
		temp->next = head;

		head = temp;
		_size++;
	}
	T pop() {
		if (empty())
			return -1;

		Node* temp = head;
		head = temp->next;
		
		_size--;
		T v = temp->data;
		delete temp;
		return v;
	}
	void clear() {
		while (!empty()) {
			pop();
		}
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
};

int main() {
	int N;
	string str;
	Stack<char> stack;
	bool flag;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		flag = true;
		for (int j = 0; j < str.length(); j++) {
			char c = str[j];
			if (c == '(') {
				stack.push(c);
			}
			else if(c == ')') {
				char t = stack.pop();

				if (t == ')' || t == -1) {
					flag = false;
					break;
				}
			}
		}

		if (flag && stack.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		stack.clear();
	}

	return 0;
}