#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;

constexpr int INF = 987'654'321;
constexpr int MAX_N = 500;

int N;
vector<int> adj[MAX_N];
int visited[MAX_N];
int parent[MAX_N];
string idx2str[MAX_N];
unordered_map<string, int> str2idx;

int bfs(const int st) {
	queue<int> q;
	memset(visited, 0, sizeof(visited));
	memset(parent, -1, sizeof(parent));

	q.push(st);
	visited[st] = 1;

	while (!q.empty()) {
		const int now = q.front();
		q.pop();

		for (const auto& next : adj[now]) {
			if (next == st) {
				parent[next] = now;
				return visited[now];
			}

			if (visited[next])
				continue;

			q.push(next);
			visited[next] = visited[now] + 1;
			parent[next] = now;
		}
	}

	return INF;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> idx2str[i];
		str2idx.insert({ idx2str[i], i });
	}

	for (int i = 0; i < N; ++i) {
		string str;
		int M;
		cin >> str >> M;

		for (int j = 0; j < M; ++j) {
			cin >> str;
			cin.ignore();
			getline(cin, str);
			str.push_back(',');

			int st = 0;
			int en = str.find(',', st);

			while (en != string::npos) {
				adj[i].push_back(str2idx[str.substr(st, en - st)]);
				st = en + 2;
				en = str.find(',', st);
			}
		}
	}

	int minCnt = INF;
	int minIdx = -1;

	for (int i = 0; i < N; ++i) {
		const int cnt = bfs(i);

		if (minCnt > cnt) {
			minCnt = cnt;
			minIdx = i;
		}
	}

	if (minIdx == -1) {
		cout << "SHIP IT\n";
		return 0;
	}

	bfs(minIdx);

	vector<int> ans;

	for (int i = 0; i < minCnt; ++i) {
		minIdx = parent[minIdx];
		ans.push_back(minIdx);
	}

	for (int i = minCnt - 1; i >= 0; --i)
		cout << idx2str[ans[i]] << ' ';
	cout << '\n';

	return 0;
}
