#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

struct Node {
	map<string, Node*> child;

	~Node() {
		for (const auto& node : child)
			delete node.second;
	}
};

class Trie {
private:
	Node head;

	void dfs(Node* now, int level) {
		for (const auto& [str, next] : now->child) {
			cout << string(level * 2, '-') << str << '\n';
			dfs(next, level + 1);
		}
	}

public:
	void insert(vector<string> arr) {
		Node* ptr = &head;

		for (const auto& str : arr) {
			if (ptr->child.find(str) == ptr->child.end())
				ptr->child[str] = new Node();

			ptr = ptr->child[str];
		}
	}

	void print() {
		dfs(&head, 0);
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	Trie trie;

	for (int i = 0; i < N; ++i) {
		int K;
		cin >> K;

		vector<string> arr(K);

		for (auto& str : arr)
			cin >> str;

		trie.insert(arr);
	}

	trie.print();

	return 0;
}
