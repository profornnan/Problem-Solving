#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

struct Pos {
	int y;
	int x;
};

struct Node {
	int to;
	int cost;
};

const int MAX = 987654321;
int N;
Pos pos[12];
vector<Node> adj[12];
int dp[12][1 << 12];

int dfs(int now, int state) {
	if (now == 1) {
		if (state == (1 << N) - 1)
			return 0;
		return MAX;
	}

	if (dp[now][state] != -1)
		return dp[now][state];

	int dist = MAX;

	for (int i = 0; i < adj[now].size(); i++) {
		Node next = adj[now][i];

		if (state & (1 << next.to)) continue;

		dist = min(dist, dfs(next.to, state | (1 << next.to)) + next.cost);
	}

	return dp[now][state] = dist;
}

int main(void) {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(dp, -1, sizeof(dp));

		cin >> N;
		N += 2;

		for (int i = 0; i < N; i++) {
			cin >> pos[i].y >> pos[i].x;
			adj[i].clear();
		}

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int dist = abs(pos[i].y - pos[j].y) + abs(pos[i].x - pos[j].x);
				adj[i].push_back({ j, dist });
				adj[j].push_back({ i, dist });
			}
		}

		cout << '#' << tc << ' ' << dfs(0, 1) << '\n';
	}

	return 0;
}
