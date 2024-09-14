#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 25;
constexpr int MAX_M = 25;

int N, M;
bool visited[MAX_N + 1][MAX_M + 1];
int ans;

void dfs(int y, int x) {
	if (x > M) {
		x = 1;
		++y;
	}

	if (y > N) {
		++ans;
		return;
	}

	dfs(y, x + 1);

	if (visited[y][x - 1] && visited[y - 1][x - 1] && visited[y - 1][x])
		return;

	visited[y][x] = true;
	dfs(y, x + 1);
	visited[y][x] = false;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	if (N < M)
		swap(N, M);

	dfs(1, 1);

	cout << ans << '\n';

	return 0;
}
