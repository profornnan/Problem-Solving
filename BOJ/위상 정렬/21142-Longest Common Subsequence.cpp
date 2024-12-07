#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

constexpr int MAX_K = 26;

int N, K;
bool adj[MAX_K][MAX_K];
int indegree[MAX_K];
int dist[MAX_K];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		for (int i = 0; i < K; ++i)
			for (int j = i + 1; j < K; ++j)
				adj[str[i] - 'A'][str[j] - 'A'] = true;
	}

	for (int i = 0; i < K; ++i)
		for (int j = i + 1; j < K; ++j)
			if (adj[i][j] && adj[j][i])
				adj[i][j] = adj[j][i] = false;

	for (int i = 0; i < K; ++i)
		for (int j = 0; j < K; ++j)
			if (adj[i][j])
				++indegree[j];

	queue<int> q;

	for (int i = 0; i < K; ++i) {
		if (indegree[i] == 0) {
			q.push(i);
			dist[i] = 1;
		}
	}

	while (!q.empty()) {
		const int now = q.front();
		q.pop();

		for (int next = 0; next < K; ++next) {
			if (!adj[now][next])
				continue;

			if (indegree[next] == 0)
				continue;

			if (--indegree[next] == 0) {
				q.push(next);
				dist[next] = dist[now] + 1;
			}
		}
	}

	cout << *max_element(dist, dist + K) << '\n';

	return 0;
}
