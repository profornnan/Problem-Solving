#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
using pli = pair<long long, int>;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<long long> monster(N + 1);
	vector<vector<pii>> items(N + 1);

	for (int i = 1; i <= N; ++i)
		cin >> monster[i];

	int P;
	cin >> P;

	for (int i = 0; i < P; ++i) {
		int u, v, c;
		cin >> u >> v >> c;

		monster[v] += c;
		items[u].push_back({ v, c });
	}

	priority_queue<pli, vector<pli>, greater<pli>> pq;
	vector<bool> visited(N + 1);

	for (int i = 1; i <= N; ++i)
		pq.push({ monster[i], i });

	long long ans = 0;
	int cnt = 0;

	while (cnt < M) {
		const auto [level, now] = pq.top();
		pq.pop();

		if (visited[now])
			continue;

		visited[now] = true;

		for (const auto& [next, sub] : items[now]) {
			if (visited[next])
				continue;

			monster[next] -= sub;
			pq.push({ monster[next], next });
		}

		ans = ans > level ? ans : level;
		++cnt;
	}

	cout << ans << '\n';

	return 0;
}
