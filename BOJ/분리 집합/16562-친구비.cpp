#include <iostream>
#include <vector>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int n, m, k;
vector<int> cost, parent;

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (cost[u] < cost[v]) swap(u, v);
	parent[u] = v;
}

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n >> m >> k;
	cost = parent = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (0 != find(i)) {
			ans += cost[find(i)];
			merge(0, i);
		}
	}
	if (ans <= k)
		cout << ans << '\n';
	else
		cout << "Oh no\n";
	return 0;
}
