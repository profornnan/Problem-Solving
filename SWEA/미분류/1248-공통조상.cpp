#include <iostream>
#include <vector>
using namespace std;

struct Node {
	vector<int> child;
	int parent;
};

vector<Node> tree;

void traverse(int now, vector<int>& ancestor) {
	int parent = tree[now].parent;
	if (parent != 0) traverse(parent, ancestor);
	ancestor.emplace_back(now);
}

int dfs(int now) {
	if (tree[now].child.size() == 0) return 1;
	int ret = 1;
	for (int next : tree[now].child) ret += dfs(next);
	return ret;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int V, E, A, B, ans = 0;
		cin >> V >> E >> A >> B;

		vector<Node>(V + 1).swap(tree);

		for (int i = 0; i < E; i++) {
			int p, c;
			cin >> p >> c;
			tree[p].child.emplace_back(c);
			tree[c].parent = p;
		}

		vector<int> ancestorA, ancestorB;
		traverse(A, ancestorA);
		traverse(B, ancestorB);

		for (int i = 0; i < V; i++) {
			if (ancestorA[i] != ancestorB[i]) break;
			ans = ancestorA[i];
		}

		cout << '#' << tc << ' ' << ans << ' ' << dfs(ans) << '\n';
	}

	return 0;
}
