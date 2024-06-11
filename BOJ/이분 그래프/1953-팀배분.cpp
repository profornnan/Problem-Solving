#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr int COLOR = 2;
constexpr int MAX_N = 100;

int N;
int cnt[COLOR];
int teamColor[MAX_N + 1];
vector<int> adj[MAX_N + 1];

void dfs(int now, int color) {
	++cnt[color];
	teamColor[now] = color;

	for (const auto& next : adj[now])
		if (teamColor[next] == -1)
			dfs(next, (color + 1) % COLOR);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int from = 1; from <= N; ++from) {
		int M;
		cin >> M;

		while (M--) {
			int to;
			cin >> to;
			adj[from].push_back(to);
		}
	}

	memset(teamColor, -1, sizeof(teamColor));

	for (int i = 1; i <= N; ++i)
		if (teamColor[i] == -1)
			dfs(i, i % COLOR);

	for (int color = 0; color < COLOR; ++color) {
		cout << cnt[color] << '\n';

		for (int i = 1; i <= N; ++i)
			if (teamColor[i] == color)
				cout << i << ' ';
		cout << '\n';
	}

	return 0;
}
