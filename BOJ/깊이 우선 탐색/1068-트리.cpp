#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 50;

int N, S, D;
vector<int> adj[MAX_N];

int dfs(int now) {
	if (now == D)
		return 0;

	int childCnt = 0;

	for (const int& next : adj[now])
		childCnt += dfs(next);

	return childCnt ? childCnt : 1;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int child = 0; child < N; ++child) {
		int parent;
		cin >> parent;

		if (parent == -1) {
			S = child;
			continue;
		}

		adj[parent].push_back(child);
	}

	cin >> D;

	cout << dfs(S) << '\n';

	return 0;
}
