#include <iostream>
using namespace std;

constexpr int N = 11;

int ability[N][N];
bool visited[N];
int ans;

void dfs(int player, int sum) {
	if (player >= N) {
		ans = ans > sum ? ans : sum;
		return;
	}

	for (int pos = 0; pos < N; ++pos) {
		if (!ability[player][pos]) continue;
		if (visited[pos]) continue;

		visited[pos] = true;
		dfs(player + 1, sum + ability[player][pos]);
		visited[pos] = false;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> ability[i][j];

		ans = 0;
		dfs(0, 0);
		cout << ans << '\n';
	}

	return 0;
}
