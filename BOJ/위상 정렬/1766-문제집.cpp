#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define sws ios::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int N, M;

int main(void) {
	sws;
	freopen("input.txt", "r", stdin);
	cin >> N >> M;

	vector<vector<int> > adj(N + 1, vector<int>());
	vector<int> income(N + 1);
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		adj[A].push_back(B);
		income[B]++;
	}

	for (int i = 1; i <= N; i++)
		if (income[i] == 0)
			pq.push(i);

	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		cout << now << ' ';
		
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];

			if (income[next] == 0)
				continue;

			if (--income[next] == 0)
				pq.push(next);
		}
	}

	return 0;
}
