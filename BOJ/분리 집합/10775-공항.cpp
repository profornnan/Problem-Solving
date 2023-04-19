#include <iostream>
using namespace std;

int G, P;
int parent[100001];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

int Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb) return 0;
	parent[pb] = pa;
	return 1;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> G >> P;

	for (int i = 1; i <= G; i++)
		parent[i] = i;

	int ans = 0;

	while (P--) {
		int g;
		cin >> g;

		if (Union(Find(g) - 1, g))
			ans++;
		else
			break;
	}

	cout << ans << '\n';

	return 0;
}
