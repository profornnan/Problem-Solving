#include <iostream>
using namespace std;

constexpr int MAX_R = 10'000;
constexpr int MAX_C = 500;
constexpr int dx[]{ 1, 1, 1 };
constexpr int dy[]{ -1, 0, 1 };

int R, C;
char MAP[MAX_R][MAX_C];
bool isValid;
int ans;

void dfs(int y, int x) {
	if (isValid)
		return;

	MAP[y][x] = 'x';

	if (x >= C - 1) {
		++ans;
		isValid = true;
		return;
	}

	for (int dir = 0; dir < 3; ++dir) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;

		if (MAP[ny][nx] == 'x')
			continue;

		dfs(ny, nx);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> R >> C;

	for (int y = 0; y < R; ++y)
		for (int x = 0; x < C; ++x)
			cin >> MAP[y][x];

	for (int y = 0; y < R; ++y) {
		isValid = false;
		dfs(y, 0);
	}

	cout << ans << '\n';

	return 0;
}
