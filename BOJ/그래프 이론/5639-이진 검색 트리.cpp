#include <iostream>
#include <vector>
using namespace std;

vector<int> preorder;

void dfs(int left, int right) {
	if (left == right) return;

	int mid = left + 1;

	for (; mid < right; ++mid)
		if (preorder[left] < preorder[mid])
			break;

	dfs(left + 1, mid);
	dfs(mid, right);

	cout << preorder[left] << '\n';
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int num;

	while (cin >> num)
		preorder.emplace_back(num);

	dfs(0, preorder.size());

	return 0;
}
