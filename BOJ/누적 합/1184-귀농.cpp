#include <iostream>
#include <unordered_map>
using namespace std;

constexpr int MAX_N = 50;

int N;
int psum[MAX_N + 1][MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> psum[i][j];
			psum[i][j] += psum[i][j - 1];
		}
	}

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			psum[i][j] += psum[i - 1][j];

	int ans = 0;

	for (int si = 1; si < N; ++si) {
		for (int sj = 1; sj < N; ++sj) {
			unordered_map<int, int> UL, UR;

			for (int i = si; i >= 1; --i)
				for (int j = sj; j >= 1; --j)
					++UL[psum[si][sj] - psum[i - 1][sj] - psum[si][j - 1] + psum[i - 1][j - 1]];

			for (int i = si; i >= 1; --i)
				for (int j = sj + 1; j <= N; ++j)
					++UR[psum[si][j] - psum[i - 1][j] - psum[si][sj] + psum[i - 1][sj]];

			for (int i = si + 1; i <= N; ++i) {
				for (int j = sj; j >= 1; --j) {
					const int sum = psum[i][sj] - psum[si][sj] - psum[i][j - 1] + psum[si][j - 1];
					if (UR.count(sum)) ans += UR[sum];
				}
			}

			for (int i = si + 1; i <= N; ++i) {
				for (int j = sj + 1; j <= N; ++j) {
					const int sum = psum[i][j] - psum[si][j] - psum[i][sj] + psum[si][sj];
					if (UL.count(sum)) ans += UL[sum];
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
