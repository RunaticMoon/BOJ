#include <iostream>
using namespace std;
// 자료구조 연습용이라 링크드리스트로 구현

template<typename T>
class Tree {
private:
	struct Node {
		T data;
		Node* left;
		Node* right;
	};

	Node* _root;

public:
	Tree() {
		_root = nullptr;
	}
	void add(T v, T lv, T rv) {
		if (empty()) {
			_root = new Node;
			_root->data = v;
		}

		Node* temp = search(_root, v);
		if (lv == '.') temp->left = nullptr;
		else {
			Node* t = new Node();
			t->data = lv;
			t->left = nullptr;
			t->right = nullptr;

			temp->left = t;
		}

		if (rv == '.') temp->right = nullptr;
		else {
			Node* t = new Node();
			t->data = rv;
			t->left = nullptr;
			t->right = nullptr;

			temp->right = t;
		}
	}

	Node* search(Node* node, T v) {
		if (node->data == v)
			return node;

		Node* temp = nullptr;
		if (node->left) temp = search(node->left, v);
		if (temp) return temp;
		if (node->right) temp = search(node->right, v);
		return temp;
	}

	void preOrder(Node* root) {
		cout << root->data;
		if (root->left) preOrder(root->left);
		if (root->right) preOrder(root->right);
	}
	void inOrder(Node* root) {
		if (root->left) inOrder(root->left);
		cout << root->data;
		if (root->right) inOrder(root->right);
	}
	void postOrder(Node* root) {
		if (root->left) postOrder(root->left);
		if (root->right) postOrder(root->right);
		cout << root->data;
	}

	Node* root() const {
		return _root;
	}
	bool empty() const {
		return (_root == nullptr);
	}
};


int main() {
	Tree<char> tree;
	int T;
	char a, b, c;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a >> b >> c;
		tree.add(a, b, c);
	}

	tree.preOrder(tree.root());
	cout << endl;
	tree.inOrder(tree.root());
	cout << endl;
	tree.postOrder(tree.root());

	return 0;
}