#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
	Node* head;
	Node* tail;

public:
	LinkedList() : head(nullptr), tail(nullptr) {}

	~LinkedList() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	
	void insert(int idx, const vector<int>& nums) {
		int st = 0;

		if (idx == 0) {
			Node* node = new Node(nums[st]);
			node->next = head;
			head = node;
			idx = st = 1;
		}

		Node* cur = head;

		for (int i = 0; i < idx - 1; i++)
			cur = cur->next;

		for (int i = st; i < nums.size(); i++) {
			Node *node = new Node(nums[i]);
			node->next = cur->next;
			cur->next = node;
			cur = node;
		}

		if (cur->next == nullptr) tail = cur;
	}

	void erase(int idx, int cnt) {
		Node* cur = head;

		if (idx == 0) {
			for (int i = 0; i < cnt; i++) {
				Node* temp = cur;
				cur = cur->next;
				delete temp;
			}
			
			head = cur;
			return;
		}

		for (int i = 0; i < idx - 1; i++)
			cur = cur->next;

		Node* anchor = cur;

		cur = cur->next;

		for (int i = 0; i < cnt; i++) {
			Node* temp = cur;
			cur = cur->next;
			delete temp;
		}

		anchor->next = cur;

		if (anchor->next == nullptr) tail = anchor;
	}

	void add(const vector<int>& nums) {
		Node* cur = tail;

		for (int i = 0; i < nums.size(); i++) {
			Node* node = new Node(nums[i]);
			cur->next = node;
			cur = node;
		}

		tail = cur;
	}

	void print() {
		Node* cur = head;

		for (int i = 0; i < 10; i++) {
			cout << cur->data << ' ';
			cur = cur->next;
		}
	}
};

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	for (int tc = 1; tc <= 10; tc++) {
		cout << '#' << tc << ' ';

		int N, M;
		vector<int> nums;
		LinkedList linkedList;

		cin >> N;
		vector<int>(N).swap(nums);

		for (int& num : nums)
			cin >> num;

		linkedList.insert(0, nums);

		cin >> M;

		while (M--) {
			char cmd;
			int idx, cnt;
			cin >> cmd;

			if (cmd == 'I') {
				cin >> idx >> cnt;
				vector<int>(cnt).swap(nums);
				for (int& num : nums)
					cin >> num;
				linkedList.insert(idx, nums);
			}
			else if (cmd == 'D') {
				cin >> idx >> cnt;
				linkedList.erase(idx, cnt);
			}
			else if (cmd == 'A') {
				cin >> cnt;
				vector<int>(cnt).swap(nums);
				for (int& num : nums)
					cin >> num;
				linkedList.add(nums);
			}
		}

		linkedList.print();
		cout << '\n';
	}

	return 0;
}
