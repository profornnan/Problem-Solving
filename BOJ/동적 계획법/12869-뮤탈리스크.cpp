#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_N = 3;
constexpr int MAX_HP = 60;

const vector<tuple<int, int, int>> ATK{
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

int N;
int hp[MAX_N];
int dp[MAX_HP + 1][MAX_HP + 1][MAX_HP + 1];

int dfs(int x, int y, int z) {
	if (x == 0 && y == 0 && z == 0)
		return 0;

	int& ret = dp[x][y][z];

	if (ret != -1)
		return ret;

	ret = INF;

	for (const auto& [dx, dy, dz] : ATK) {
		int nx = max(0, x - dx);
		int ny = max(0, y - dy);
		int nz = max(0, z - dz);

		ret = min(ret, dfs(nx, ny, nz) + 1);
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> hp[i];

	memset(dp, -1, sizeof(dp));

	cout << dfs(hp[0], hp[1], hp[2]) << '\n';

	return 0;
}
