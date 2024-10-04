#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

constexpr int MAX_W = 200;
constexpr int MAX_D = 8;
constexpr int dx[]{ 1, 1, 0, -1, -1, -1, 0, 1 };
constexpr int dy[]{ 0, -1, -1, -1, 0, 1, 1, 1 };

int W, D;
string words[MAX_W];
char board[MAX_D][MAX_D];
bool visited[MAX_D][MAX_D];
bool exist;

void dfs(const int level, const int y, const int x, const string& word) {
	if (exist)
		return;

	if (level >= word.length()) {
		exist = true;
		return;
	}

	for (int dir = 0; dir < 8; ++dir) {
		const int ny = y + dy[dir];
		const int nx = x + dx[dir];

		if (ny < 0 || ny >= D || nx < 0 || nx >= D)
			continue;

		if (visited[ny][nx])
			continue;

		if (board[ny][nx] != word[level])
			continue;

		if (board[ny][nx] != 'q') {
			visited[ny][nx] = true;
			dfs(level + 1, ny, nx, word);
			visited[ny][nx] = false;
		}
		else if (level + 1 < word.length() && word[level + 1] == 'u') {
			visited[ny][nx] = true;
			dfs(level + 2, ny, nx, word);
			visited[ny][nx] = false;
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> W;

	for (int i = 0; i < W; ++i)
		cin >> words[i];

	sort(words, words + W);

	while (true) {
		cin >> D;

		if (!D)
			break;

		for (int y = 0; y < D; ++y)
			for (int x = 0; x < D; ++x)
				cin >> board[y][x];

		for (int i = 0; i < W; ++i) {
			const string& word = words[i];
			exist = false;

			for (int y = 0; y < D; ++y) {
				for (int x = 0; x < D; ++x) {
					if (board[y][x] != word[0])
						continue;

					if (board[y][x] != 'q') {
						visited[y][x] = true;
						dfs(1, y, x, word);
						visited[y][x] = false;
					}
					else if (1 < word.length() && word[1] == 'u') {
						visited[y][x] = true;
						dfs(2, y, x, word);
						visited[y][x] = false;
					}
				}
			}

			if (exist)
				cout << word << '\n';
		}

		cout << "-\n";
	}

	return 0;
}
