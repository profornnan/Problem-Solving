#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

struct Node {
	bool isEnd;
	map<char, Node*> child;

	Node() : isEnd(false), child() {}

	~Node() {
		for (const auto& [idx, ptr] : child)
			delete ptr;
	}
};

class Trie {
private:
	Node head;

public:
	void insert(const string& str) {
		Node* ptr = &head;

		for (const auto& ch : str) {
			if (!ptr->child.count(ch))
				ptr->child[ch] = new Node;

			ptr = ptr->child[ch];
		}

		ptr->isEnd = true;
	}

	bool find(const string& str, const unordered_set<string>& us) {
		Node* ptr = &head;

		for (int i = 0; i < str.size(); ++i) {
			const int ch = str[i];

			if (!ptr->child.count(ch))
				break;

			if (ptr->child[ch]->isEnd && us.count(str.substr(i + 1)))
				return true;

			ptr = ptr->child[ch];
		}

		return false;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int C, N;
	cin >> C >> N;

	Trie colorTrie;
	unordered_set<string> nicknameSet;

	for (int i = 0; i < C; ++i) {
		string color;
		cin >> color;
		colorTrie.insert(color);
	}

	for (int i = 0; i < N; ++i) {
		string nickname;
		cin >> nickname;
		nicknameSet.insert(nickname);
	}

	int Q;
	cin >> Q;

	for (int i = 0; i < Q; ++i) {
		string teamname;
		cin >> teamname;

		if (colorTrie.find(teamname, nicknameSet))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}
