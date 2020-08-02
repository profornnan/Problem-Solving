#include <iostream>
#include <vector>
#include <algorithm>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, m;
vector<int> truth;
vector<vector<int> > parties;

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
		if (rank[u] == rank[v]) ++rank[v];
	}
};

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);

	int d, p, ans = 0;

	cin >> n >> m;
	cin >> d;

	DisjointSet d_set(n + 1);
	parties = vector<vector<int> >(m);
	truth = vector<int>(d);

	for (int i = 0; i < d; i++)
		cin >> truth[i];

	for (int i = 0; i < m; i++) {
		cin >> d;
		parties[i] = vector<int>(d);
		for (int j = 0; j < d; j++)
			cin >> parties[i][j];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < parties[i].size(); j++) {
			for (int k = j + 1; k < parties[i].size(); k++) {
				d_set.merge(parties[i][j], parties[i][k]);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		bool isPossible = true;
		for (int j = 0; j < parties[i].size(); j++) {
			for (int k = 0; k < truth.size(); k++) {
				if (d_set.find(parties[i][j]) == d_set.find(truth[k])) {
					isPossible = false;
					break;
				}
			}
		}
		if (isPossible)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}
