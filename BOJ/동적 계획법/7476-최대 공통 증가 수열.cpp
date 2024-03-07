#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

constexpr int MAX_N = 500;
constexpr int MAX_M = 500;

int N, M;
int A[MAX_N];
int B[MAX_M];
int dp[MAX_N][MAX_M];
int pj[MAX_N][MAX_M];
pii parent[MAX_N][MAX_M];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> A[i];

	cin >> M;

	for (int i = 0; i < M; ++i)
		cin >> B[i];

	for (int i = 0; i < N; ++i) {
		int idx = -1;

		for (int j = 0; j < M; ++j) {
			if (A[i] == B[j])
				idx = j;

			pj[i][j] = idx;
		}
	}

	int maxLen = 0;
	pii maxIdx = { 0, 0 };

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			parent[i][j] = { i, j };

			if (A[i] != B[j])
				continue;

			dp[i][j] = 1;

			for (int pi = 0; pi < i; ++pi) {
				if (A[pi] >= A[i])
					continue;

				if (pj[pi][j] == -1)
					continue;

				if (dp[i][j] < dp[pi][pj[pi][j]] + 1) {
					dp[i][j] = dp[pi][pj[pi][j]] + 1;
					parent[i][j] = { pi, pj[pi][j] };
				}
			}

			if (maxLen < dp[i][j]) {
				maxLen = dp[i][j];
				maxIdx = { i, j };
			}
		}
	}

	vector<int> path;
	pii now = maxIdx;

	while (parent[now.first][now.second] != now) {
		path.push_back(A[now.first]);
		now = parent[now.first][now.second];
	}

	path.push_back(A[now.first]);

	cout << maxLen << '\n';

	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i] << ' ';
	cout << '\n';

	return 0;
}
