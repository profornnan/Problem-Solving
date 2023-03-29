#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int F;
int idx;
int parent[200001];
int cnt[200001];
unordered_map<string, int> um;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb) return;
	parent[pb] = pa;
	cnt[pa] += cnt[pb];
	cnt[pb] = 0;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> F;
		idx = 0;
		um.clear();

		for (int i = 0; i < 2 * F; i++) {
			parent[i] = i;
			cnt[i] = 1;
		}
		
		for (int i = 0; i < F; i++) {
			string p, q;
			cin >> p >> q;

			if (um.find(p) == um.end())
				um.insert({ p, idx++ });

			if (um.find(q) == um.end())
				um.insert({ q, idx++ });

			Union(um[p], um[q]);

			cout << cnt[Find(um[p])] << '\n';
		}
	}

	return 0;
}
