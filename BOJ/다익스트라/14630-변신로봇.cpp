#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

constexpr int INF = 987'654'321;

struct Edge {
	int to;
	int cost;

	bool operator<(const Edge& rhs) const {
		return cost > rhs.cost;
	}
};

int calcCost(const string& lhs, const string& rhs) {
	int ret = 0;

	for (int i = 0; i < rhs.size(); ++i)
		ret += (rhs[i] - lhs[i]) * (rhs[i] - lhs[i]);

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<string> state(N);

	for (auto& s : state)
		cin >> s;

	int st, en;
	cin >> st >> en;
	--st, --en;

	priority_queue<Edge> pq;
	vector<int> dist(N, INF);

	pq.push({ st, 0 });
	dist[st] = 0;

	while (!pq.empty()) {
		const Edge now = pq.top();
		pq.pop();

		if (now.to == en) {
			cout << dist[now.to] << '\n';
			return 0;
		}

		if (dist[now.to] < now.cost)
			continue;

		for (int next = 0; next < N; ++next) {
			const int ncost = now.cost + calcCost(state[now.to], state[next]);

			if (dist[next] <= ncost)
				continue;

			pq.push({ next, ncost });
			dist[next] = ncost;
		}
	}

	return 0;
}
