#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr int MAX_N = 1000;
constexpr int MAX_M = 1000;

int N, M;
vector<int> adj[MAX_N + 1];
int employeeMatch[MAX_N + 1];
int taskMatch[MAX_M + 1];
bool visited[MAX_N + 1];

bool dfs(int employeeIdx) {
	if (visited[employeeIdx])
		return false;

	visited[employeeIdx] = true;

	for (const int& taskIdx : adj[employeeIdx]) {
		if (taskMatch[taskIdx] == -1 || dfs(taskMatch[taskIdx])) {
			employeeMatch[employeeIdx] = taskIdx;
			taskMatch[taskIdx] = employeeIdx;
			return true;
		}
	}

	return false;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int e = 1; e <= N; ++e) {
		int n;
		cin >> n;

		while (n--) {
			int t;
			cin >> t;
			adj[e].emplace_back(t);
		}
	}

	memset(employeeMatch, -1, sizeof(employeeMatch));
	memset(taskMatch, -1, sizeof(taskMatch));

	int ans = 0;

	for (int e = 1; e <= N; ++e) {
		memset(visited, 0, sizeof(visited));

		if (dfs(e))
			++ans;
	}

	cout << ans << '\n';

	return 0;
}
