#include <iostream>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int N;
char board[MAX_N][MAX_N];
bool check[MAX_N][MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int x = 0; x < N; ++x)
		cin >> board[0][x];

	for (int y = 1; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			if (board[y - 1][x] == '.')
				continue;

			for (int dir = 0; dir < 4; ++dir) {
				int ny = y - 1 + dy[dir];
				int nx = x + dx[dir];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;

				check[ny][nx] = !check[ny][nx];
			}
		}

		for (int x = 0; x < N; ++x)
			board[y][x] = check[y - 1][x] ? '#' : '.';
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x)
			cout << board[y][x];
		cout << '\n';
	}

	return 0;
}
