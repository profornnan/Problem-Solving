#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int N = 6;
constexpr int M = 4;
constexpr int BASE = 16;
constexpr int lhs[]{ 1, 2, 0, 3 };  // LIST
constexpr int rhs[]{ 4, 2, 1, 5 };  // FILO

int path[N];  // SLITFO
bool visited[BASE];

char dec2hex(const int dec) {
	return static_cast<char>(dec < 10 ? '0' + dec : 'a' + dec - 10);
}

void dfs(const int level) {
	if (level >= N) {
		int sum = 0;

		for (int i = 0; i < M; ++i) {
			sum *= BASE;
			sum += path[lhs[i]] + path[rhs[i]];
		}

		vector<int> res;

		while (sum) {
			res.push_back(sum % BASE);
			sum /= BASE;
		}

		if (res.size() != M + 1)
			return;

		reverse(res.begin(), res.end());  // STACK

		if (res[1] != path[3])
			return;

		for (int i = 2; i < M + 1; ++i)
			if (visited[res[i]])
				return;

		if (res[2] == res[3] || res[2] == res[4] || res[3] == res[4])
			return;

		for (const auto& idx : lhs)
			cout << dec2hex(path[idx]);

		cout << " + ";

		for (const auto& idx : rhs)
			cout << dec2hex(path[idx]);

		cout << " = ";

		for (const auto& dec : res)
			cout << dec2hex(dec);

		cout << '\n';

		return;
	}

	for (int i = (level == 1 || level == 4) ? 2 : 0; i < BASE; ++i) {
		if (visited[i])
			continue;

		path[level] = i;
		visited[i] = true;
		dfs(level + 1);
		visited[i] = false;
		path[level] = 0;
	}
}

int main(void) {
	path[0] = 1;
	visited[1] = true;
	dfs(1);
	visited[1] = false;
	path[0] = 0;

	return 0;
}
