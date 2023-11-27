#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

constexpr int MAX_N = 1000;
constexpr int MAX_M = 1000;

int N, M;
int MAP[MAX_N + 1][MAX_M + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y) {
		string row;
		cin >> row;

		for (int x = 0; x < M; ++x)
			MAP[y + 1][x + 1] = row[x] - '0';
	}

	int maxLen = 0;

	for (int y = 1; y <= N; ++y) {
		for (int x = 1; x <= M; ++x) {
			if (!MAP[y][x])
				continue;

			MAP[y][x] = min({ MAP[y - 1][x], MAP[y - 1][x - 1], MAP[y][x - 1] }) + 1;
			maxLen = max(maxLen, MAP[y][x]);
		}
	}

	cout << maxLen * maxLen << '\n';

	return 0;
}
