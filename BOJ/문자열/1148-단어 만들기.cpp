#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

constexpr int INF = 987654321;
constexpr int SIZE = 26;
constexpr int MAX_N = 200'000;

int N;
char wordCnts[MAX_N][SIZE];
char boardCnt[SIZE];
int cnt[SIZE];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (true) {
		string word;
		cin >> word;

		if (word == "-")
			break;

		auto& wordCnt = wordCnts[N++];

		for (const auto& ch : word)
			++wordCnt[ch - 'A'];
	}

	while (true) {
		string board;
		cin >> board;

		if (board == "#")
			break;

		memset(boardCnt, 0, sizeof(boardCnt));
		memset(cnt, 0, sizeof(cnt));

		for (const auto& ch : board)
			++boardCnt[ch - 'A'];

		for (int i = 0; i < N; ++i) {
			const auto& wordCnt = wordCnts[i];

			bool possible = true;

			for (int i = 0; i < SIZE; ++i) {
				if (boardCnt[i] < wordCnt[i]) {
					possible = false;
					break;
				}
			}

			if (!possible)
				continue;

			for (int i = 0; i < SIZE; ++i)
				if (wordCnt[i])
					++cnt[i];
		}

		sort(board.begin(), board.end());
		board.erase(unique(board.begin(), board.end()), board.end());

		int minCnt = INF;
		int maxCnt = 0;

		for (const auto& ch : board) {
			minCnt = min(minCnt, cnt[ch - 'A']);
			maxCnt = max(maxCnt, cnt[ch - 'A']);
		}

		for (const auto& ch : board)
			if (cnt[ch - 'A'] == minCnt)
				cout << ch;

		cout << ' ' << minCnt << ' ';

		for (const auto& ch : board)
			if (cnt[ch - 'A'] == maxCnt)
				cout << ch;

		cout << ' ' << maxCnt << '\n';
	}

	return 0;
}
