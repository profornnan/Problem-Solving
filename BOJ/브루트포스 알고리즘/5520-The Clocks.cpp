#include <iostream>
#include <vector>
using namespace std;

constexpr int SIZE = 9;

const vector<vector<int>> mv{
	{0, 1, 3, 4},
	{0, 1, 2},
	{1, 2, 4, 5},
	{0, 3, 6},
	{1, 3, 4, 5, 7},
	{2, 5, 8},
	{3, 4, 6, 7},
	{6, 7, 8},
	{4, 5, 7, 8}
};

int clock[SIZE];
vector<int> path;
vector<int> ans;

void dfs(int level) {
	if (ans.size() && path.size() >= ans.size())
		return;

	if (level >= SIZE) {
		for (int i = 0; i < SIZE; ++i)
			if (clock[i])
				return;

		ans = path;

		return;
	}

	dfs(level + 1);

	for (int k = 0; k < 3; ++k) {
		path.push_back(level);

		for (const auto& i : mv[level])
			clock[i] = (clock[i] + 1) % 4;

		dfs(level + 1);
	}

	path.erase(path.end() - 3, path.end());

	for (const auto& i : mv[level])
		clock[i] = (clock[i] + 1) % 4;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	for (int i = 0; i < SIZE; ++i)
		cin >> clock[i];

	dfs(0);

	for (const auto& i : ans)
		cout << i + 1 << ' ';
	cout << '\n';

	return 0;
}
