#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 100;
constexpr int MAX_M = 100;
constexpr int dx[]{ 1, 0, -1, 0 };
constexpr int dy[]{ 0, -1, 0, 1 };

int N, M;
int MAP[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M][2];

bool isValid(const int target) {
	if (MAP[0][0] > target)
		return false;

	queue<tuple<int, int, bool>> q;
	memset(visited, 0, sizeof(visited));

	q.push({ 0, 0, false });
	visited[0][0][false] = true;

	while (!q.empty()) {
		const auto [y, x, jumped] = q.front();
		q.pop();

		if (y == N - 1 && x == M - 1)
			return true;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (visited[ny][nx][jumped])
				continue;

			if (MAP[ny][nx] > target)
				continue;

			q.push({ ny, nx, jumped });
			visited[ny][nx][jumped] = true;
		}

		if (jumped)
			continue;

		for (int dir = 0; dir < 4; ++dir) {
			int ny = y + dy[dir] * 2;
			int nx = x + dx[dir] * 2;

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;

			if (visited[ny][nx][true])
				continue;

			if (MAP[ny][nx] > target)
				continue;

			q.push({ ny, nx, true });
			visited[ny][nx][true] = true;
		}
	}

	return false;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	int ans = INF;
	int left = INF;
	int right = 0;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> MAP[y][x];
			left = left < MAP[y][x] ? left : MAP[y][x];
			right = right > MAP[y][x] ? right : MAP[y][x];
		}
	}

	while (left <= right) {
		const int mid = left + (right - left) / 2;

		if (isValid(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << ans << '\n';

	return 0;
}
