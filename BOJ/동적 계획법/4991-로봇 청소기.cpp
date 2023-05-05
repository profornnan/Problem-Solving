#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Pos {
	int y;
	int x;
};

struct Edge {
	int to;
	int cost;
};

const int dx[]{ 1, 0, -1, 0 };
const int dy[]{ 0, -1, 0, 1 };

const int INF = 987654321;
char MAP[20][20];
int visited[20][20], dp[11][1 << 10];
vector<Pos> v;
vector<vector<Edge>> adj;

int dfs(int now, int status) {
	if (status == (1 << v.size()) - 1)
		return 0;

	if (dp[now][status] != -1) return dp[now][status];

	int ret = INF;

	for (Edge next : adj[now]) {
		if (status & (1 << next.to)) continue;
		ret = min(ret, dfs(next.to, status | (1 << next.to)) + next.cost);
	}

	return dp[now][status] = ret;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int W, H;

	while (true) {
		cin >> W >> H;
		if (W == 0 && H == 0) break;

		int stIdx = 0;
		vector<Pos>().swap(v);

		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				cin >> MAP[y][x];

				if (MAP[y][x] == '.' || MAP[y][x] == 'x') continue;
				if (MAP[y][x] == 'o') stIdx = v.size();

				MAP[y][x] = v.size();
				v.push_back({ y, x });
			}
		}

		vector<vector<Edge>>(v.size()).swap(adj);

		for (int idx = 0; idx < v.size(); idx++) {
			Pos stPos = v[idx];

			queue<Pos> q;
			q.push(stPos);

			memset(visited, 0, sizeof(visited));
			visited[stPos.y][stPos.x] = 1;

			while (!q.empty()) {
				Pos now = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int ny = now.y + dy[dir];
					int nx = now.x + dx[dir];

					if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
					if (MAP[ny][nx] == 'x') continue;
					if (visited[ny][nx] != 0) continue;

					q.push({ ny, nx });
					visited[ny][nx] = visited[now.y][now.x] + 1;
					if (MAP[ny][nx] != '.') adj[idx].push_back({ MAP[ny][nx], visited[ny][nx] - 1 });
				}
			}
		}

		memset(dp, -1, sizeof(dp));
		int ans = dfs(stIdx, (1 << stIdx));

		if (ans == INF) cout << "-1\n";
		else cout << ans << '\n';
	}

	return 0;
}
