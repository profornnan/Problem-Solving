#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int cost[1001][1001];
vector<pair<int, int> > connected;

struct DisjointSet {
	vector<int> parent, rank;
	DisjointSet(int n) : parent(n), rank(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		if (rank[u] > rank[v]) swap(u, v);
		parent[u] = v;
		if (rank[u] == rank[v]) rank[v]++;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	connected = vector<pair<int, int> >(m);
	for (int i = 0; i < m; i++)
		cin >> connected[i].first >> connected[i].second;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 0; i < connected.size(); i++)
		cost[connected[i].first][connected[i].second] = cost[connected[i].second][connected[i].first] = 0;
	int additional_cost = 0;
	vector<pair<int, int> > selected;
	vector<pair<int, pair<int, int> > > edges;
	for (int i = 2; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			edges.push_back({ cost[i][j], {i, j} });
		}
	}
	sort(edges.begin(), edges.end());
	DisjointSet sets(n + 1);
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int u = edges[i].second.first, v = edges[i].second.second;
		if (sets.find(u) == sets.find(v)) continue;
		sets.merge(u, v);
		if(cost)
			selected.push_back({ u, v });
		additional_cost += cost;
	}
	if (additional_cost) {
		cout << additional_cost << ' ' << selected.size() << '\n';
		for (int i = 0; i < selected.size(); i++)
			cout << selected[i].first << ' ' << selected[i].second << '\n';
	}
	else {
		cout << 0 << '\n' << 0 << '\n';
	}
	return 0;
}
