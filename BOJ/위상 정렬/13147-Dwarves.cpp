#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

constexpr int MAX_N = 100'000;

int N, M;
vector<int> adj[MAX_N];
unordered_map<string, int> str2idx;
int indegree[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> M;

	for (int i = 0; i < M; ++i) {
		string uStr, sign, vStr;
		cin >> uStr >> sign >> vStr;

		if (!str2idx.count(uStr))
			str2idx.insert({ uStr, N++ });

		if (!str2idx.count(vStr))
			str2idx.insert({ vStr, N++ });

		const int u = str2idx[uStr];
		const int v = str2idx[vStr];

		if (sign == "<") {
			adj[u].push_back(v);
			++indegree[v];
		}
		else if (sign == ">") {
			adj[v].push_back(u);
			++indegree[u];
		}
	}

	int cnt = 0;
	queue<int> q;

	for (int u = 0; u < N; ++u)
		if (indegree[u] == 0)
			q.push(u);

	while (!q.empty()) {
		const int now = q.front();
		q.pop();
		++cnt;

		for (const auto& next : adj[now]) {
			if (indegree[next] == 0) continue;
			if (--indegree[next] == 0) q.push(next);
		}
	}

	cout << (cnt == N ? "possible" : "impossible") << '\n';

	return 0;
}
