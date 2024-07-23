#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

const string st = "Baba";

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<vector<int>> adj;
	vector<string> idx2str;
	unordered_map<string, int> str2idx;

	for (int i = 0; i < N; ++i) {
		string u, is, v;
		cin >> u >> is >> v;

		if (!str2idx.count(u)) {
			str2idx.insert({ u, idx2str.size() });
			idx2str.emplace_back(u);
			adj.push_back({});
		}

		if (!str2idx.count(v)) {
			str2idx.insert({ v, idx2str.size() });
			idx2str.emplace_back(v);
			adj.push_back({});
		}

		adj[str2idx[u]].push_back(str2idx[v]);
	}

	if (!str2idx.count(st))
		return 0;

	queue<int> q;
	vector<bool> visited(idx2str.size());
	vector<string> ans;

	q.push(str2idx[st]);
	visited[str2idx[st]] = true;

	while (!q.empty()) {
		const int now = q.front();
		q.pop();

		for (const auto& next : adj[now]) {
			if (visited[next])
				continue;

			q.push(next);
			visited[next] = true;
			ans.push_back(idx2str[next]);
		}
	}

	sort(ans.begin(), ans.end());

	for (const auto& str : ans)
		cout << str << '\n';

	return 0;
}
