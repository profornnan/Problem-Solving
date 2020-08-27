#include <iostream>
#include <vector>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n;
vector<int> time;
vector<vector<int> > adj;

int main(void)
{
	sws;
	freopen("input.txt", "r", stdin);
	cin >> n;
	time = vector<int>(n);
	adj = vector<vector<int> >(n);

	for (int i = 0; i < n; i++) {
		cin >> time[i];
		int b;
		while (true) {
			cin >> b;
			if (b == -1)
				break;
			adj[b - 1].push_back(i);
		}
	}

	vector<int> indegree(n, 0);
	vector<int> min_time(n, 0);
	queue<pair<int, int> > q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < adj[i].size(); j++)
			indegree[adj[i][j]] += 1;

	for (int i = 0; i < n; i++) {
		if (indegree[i] == 0) {
			min_time[i] = time[i];
			q.push(make_pair(i, time[i]));
		}
	}

	while (!q.empty()) {
		int now = q.front().first;
		int n_time = q.front().second;
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			if (n_time + time[next] > min_time[next])
				min_time[next] = n_time + time[next];
			if (--indegree[next] == 0) {
				q.push(make_pair(next, min_time[next]));
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << min_time[i] << '\n';

	return 0;
}
