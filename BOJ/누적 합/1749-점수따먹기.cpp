#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> psum(N + 1, vector<int>(M + 1));

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> psum[i][j];
			psum[i][j] += psum[i - 1][j];
		}
	}

	int ans = psum[1][1];

	for (int si = 1; si <= N; ++si) {
		for (int ei = si; ei <= N; ++ei) {
			int sum = 0;

			for (int j = 1; j <= M; ++j) {
				int now = psum[ei][j] - psum[si - 1][j];
				sum = max(now, sum + now);
				ans = max(ans, sum);
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
