#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int N, K;
int max_num = -1;

unordered_map<string, vector<string> > adj;

int main(void) {
	sws;
	freopen("input.txt", "r", stdin);
	cin >> N >> K;

	string s_num = to_string(N);

	queue<string> q;

	q.push(s_num);

	while (!q.empty()) {
		string now = q.front();
		q.pop();

		for (int i = 0; i < now.size(); i++) {
			for (int j = i + 1; j < now.size(); j++) {
				string next = now;
				swap(next[i], next[j]);

				if (next[0] == '0')
					continue;

				if (find(adj[now].begin(), adj[now].end(), next) != adj[now].end())
					continue;

				adj[now].push_back(next);

				if (now == next)
					continue;

				adj[next].push_back(now);

				q.push(next);
			}
		}
	}

	q.push(s_num);

	for (int k = 0; k < K; k++) {
		unordered_set<string> next_set;

		while (!q.empty()) {
			string now = q.front();
			q.pop();

			for (int i = 0; i < adj[now].size(); i++) {
				string next = adj[now][i];
				next_set.insert(next);
			}
		}

		for (auto next : next_set)
			q.push(next);

		if (q.size() == 0)
			break;

		next_set.clear();
	}

	while (!q.empty()) {
		max_num = max(max_num, stoi(q.front()));
		q.pop();
	}

	cout << max_num << '\n';

	return 0;
}
