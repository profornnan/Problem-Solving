#include <iostream>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
using namespace std;

constexpr int MAX_N = 512;

int T, N;
char board[MAX_N][MAX_N];

bool isAllSame(const int sy, const int sx, const int sz) {
	for (int y = sy; y < sy + sz; ++y)
		for (int x = sx; x < sx + sz; ++x)
			if (board[y][x] != board[sy][sx])
				return false;
	return true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	while (T--) {
		cin >> N;

		for (int y = 0; y < N; ++y)
			for (int x = 0; x < N; ++x)
				cin >> board[y][x];

		string bin;

		queue<tuple<int, int, int>> q;
		q.push({ 0, 0, N });

		while (!q.empty()) {
			const auto [sy, sx, sz] = q.front();
			q.pop();

			if (isAllSame(sy, sx, sz)) {
				bin.push_back('0');
				bin.push_back(board[sy][sx]);
				continue;
			}

			bin.push_back('1');

			const int half = sz / 2;

			q.push({ sy, sx, half });
			q.push({ sy, sx + half, half });
			q.push({ sy + half, sx, half });
			q.push({ sy + half, sx + half, half });
		}

		bin = string(4 - bin.size() % 4, '0') + bin;

		for (int st = 0; st < bin.size(); st += 4) {
			int digit = 0;

			for (int i = st; i < st + 4; ++i) {
				digit <<= 1;

				if (bin[i] == '1')
					++digit;
			}

			cout << (digit < 10 ? static_cast<char>('0' + digit) : static_cast<char>('A' + digit - 10));
		}

		cout << '\n';
	}

	return 0;
}
