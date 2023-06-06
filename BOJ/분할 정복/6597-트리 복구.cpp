#include <iostream>
#include <string>
using namespace std;

string preorder;
string inorder;
int inorderIdx[128];

void solve(int preLeft, int preRight, int inLeft, int inRight) {
	if (preLeft > preRight || inLeft > inRight) return;

	char root = preorder[preLeft];
	int rootIdx = inorderIdx[root];
	int leftSize = rootIdx - inLeft;

	solve(preLeft + 1, preLeft + leftSize, inLeft, rootIdx - 1);
	solve(preLeft + leftSize + 1, preRight, rootIdx + 1, inRight);
	
	cout << root;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	while (cin >> preorder) {
		cin >> inorder;

		for (int i = 0; i < inorder.size(); i++)
			inorderIdx[inorder[i]] = i;

		solve(0, preorder.size() - 1, 0, inorder.size() - 1);
		cout << '\n';
	}

	return 0;
}
