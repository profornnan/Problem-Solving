#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 5;
constexpr int M = 9;
constexpr int V = 12;
constexpr int SUM = 26;

const vector<vector<int>> lines = {
	{0, 2, 5, 7},
	{0, 3, 6, 10},
	{1, 2, 3, 4},
	{1, 5, 8, 11},
	{4, 6, 9, 11},
	{7, 8, 9, 10}
};

const vector<pair<int, int>> vertices = {
	{0, 4},
	{1, 1},
	{1, 3},
	{1, 5},
	{1, 7},
	{2, 2},
	{2, 6},
	{3, 1},
	{3, 3},
	{3, 5},
	{3, 7},
	{4, 4}
};

const vector<vector<int>> cross = {
	{0, 1},
	{2, 3},
	{0, 2},
	{1, 2},
	{2, 4},
	{0, 3},
	{1, 4},
	{0, 5},
	{3, 5},
	{4, 5},
	{1, 5},
	{3, 4}
};

char MAP[N][M];
bool printed;

bool isValid(const int vertex) {
	for (const auto& lineIdx : cross[vertex]) {
		int sum = 0;

		for (const auto& vertexIdx : lines[lineIdx]) {
			const auto& [y, x] = vertices[vertexIdx];

			if (MAP[y][x] == 'x') {
				sum = SUM;
				break;
			}

			sum += MAP[y][x] - 'A' + 1;
		}

		if (sum != SUM)
			return false;
	}

	return true;
}

void dfs(const int level, const int state) {
	if (printed)
		return;

	if (level >= V) {
		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x)
				cout << MAP[y][x];
			cout << '\n';
		}

		printed = true;

		return;
	}

	const auto& [y, x] = vertices[level];

	if (MAP[y][x] != 'x') {
		if (isValid(level))
			dfs(level + 1, state);

		return;
	}

	for (int i = 0; i < V; ++i) {
		if (state & (1 << i))
			continue;

		MAP[y][x] = i + 'A';

		if (isValid(level))
			dfs(level + 1, state | (1 << i));

		MAP[y][x] = 'x';
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int state = 0;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			char& ch = MAP[y][x];
			cin >> ch;

			if (ch == '.' || ch == 'x')
				continue;

			state |= (1 << (ch - 'A'));
		}
	}

	dfs(0, state);

	return 0;
}
