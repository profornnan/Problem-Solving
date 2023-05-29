#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

constexpr int MAX_N = 100000;

int N;
vector<int> adj[MAX_N + 1];
int parent[MAX_N + 1][20];
int depth[MAX_N + 1];

int LCA(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	if (parent[v][0] == u) return 1;
	
	int cnt = 0;
	
	for (int h = 19; h >= 0; h--) {
		if (depth[v] - depth[u] >= (1 << h)) {
			v = parent[v][h];
			cnt += (1 << h);
		}
	}

	if (parent[u][0] != parent[v][0]) {
		for (int h = 19; h >= 0; h--) {
			if (parent[u][h] != parent[v][h]) {
				cnt += 2 * (1 << h);
				u = parent[u][h];
				v = parent[v][h];
			}
		}
	}
	
	return cnt + 2;
}

long long bfs() {
	long long ret = 0;
	int pre, cur;
	queue<int> q;
	q.push(1);
	pre = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (const int& next : adj[now]) {
			q.push(next);
			cur = next;
			ret += LCA(pre, cur);
			pre = cur;
		}
	}

	return ret;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		
		for (int i = 0; i < MAX_N + 1; i++) adj[i].clear();
		memset(depth, 0, sizeof(depth));

		parent[1][0] = 0;
		depth[1] = 0;

		for (int c = 2; c <= N; c++) {
			int p;
			cin >> p;
			adj[p].emplace_back(c);
			parent[c][0] = p;
			depth[c] = depth[p] + 1;
		}

		for (int h = 1; h < 20; h++)
			for (int i = 1; i <= N; i++)
				parent[i][h] = parent[parent[i][h - 1]][h - 1];

		cout << '#' << tc << ' ' << bfs() << '\n';
	}

	return 0;
}
