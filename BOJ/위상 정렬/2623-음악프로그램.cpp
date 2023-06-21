#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> adj(N + 1);
	vector<int> income(N + 1);
	queue<int> q;
	vector<int> path;

	for (int i = 0; i < M; i++) {
		int K;
		cin >> K;
		vector<int> order(K);
		for (int& num : order)
			cin >> num;
		for (int i = 1; i < K; i++) {
			adj[order[i - 1]].push_back(order[i]);
			income[order[i]]++;
		}
	}

	for (int i = 1; i <= N; i++)
		if (income[i] == 0) q.push(i);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		path.push_back(now);

		for (const int& next : adj[now]) {
			if (income[next] == 0) continue;
			if (--income[next] == 0) q.push(next);
		}
	}

	if (path.size() != N) {
		cout << "0\n";
		return 0;
	}

	for (const int& num : path)
		cout << num << '\n';

	return 0;
}
