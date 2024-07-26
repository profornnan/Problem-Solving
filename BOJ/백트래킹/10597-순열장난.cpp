#include <iostream>
#include <string>
using namespace std;

constexpr int MAX_N = 50;

int N;
string str;
bool visited[MAX_N + 1];
int path[MAX_N];
bool printed;

void dfs(const int level, const int idx) {
	if (printed)
		return;

	if (level >= N) {
		for (int i = 0; i < N; ++i)
			cout << path[i] << ' ';
		cout << '\n';

		printed = true;

		return;
	}

	int num = 0;

	for (int i = 0; i < 2; ++i) {
		num = num * 10 + str[idx + i] - '0';

		if (num <= 0 || num > N)
			continue;

		if (visited[num])
			continue;

		visited[num] = true;
		path[level] = num;
		dfs(level + 1, idx + i + 1);
		path[level] = 0;
		visited[num] = false;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> str;

	N = str.size() <= 9 ? str.size() : 9 + (str.size() - 9) / 2;

	dfs(0, 0);

	return 0;
}
