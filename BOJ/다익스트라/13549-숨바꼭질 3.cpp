#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100'000;

struct Node {
	int x;
	int cost;
	bool operator<(Node next) const {
		if (cost < next.cost)
			return false;
		if (cost > next.cost)
			return true;
		return false;
	}
};

int dx[]{ 1, -1 };
int N, K;
vector<int> dist;
int ans;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N >> K;

	priority_queue<Node> pq;
	pq.push({ N, 0 });
	dist = vector<int>(MAX + 1, MAX);
	dist[N] = 0;

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (dist[now.x] < now.cost)
			continue;

		for (int i = 0; i < 2; i++) {
			int nx = now.x + dx[i];

			if (nx < 0 || nx > MAX)
				continue;

			int ncost = now.cost + 1;

			if (dist[nx] <= ncost)
				continue;

			dist[nx] = ncost;
			pq.push({ nx, ncost });
		}

		int nx = now.x * 2;

		if (nx < 0 || nx > MAX)
			continue;

		int ncost = now.cost;

		if (dist[nx] <= ncost)
			continue;

		dist[nx] = ncost;
		pq.push({ nx, ncost });
	}

	cout << dist[K] << '\n';

	return 0;
}
