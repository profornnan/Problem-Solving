#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

constexpr int MAX_N = 500;

struct Matrix {
	int r;
	int c;
};

int N;
Matrix matrix[MAX_N];
int dp[MAX_N][MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> matrix[i].r >> matrix[i].c;

	for (int cnt = 1; cnt < N; ++cnt) {
		for (int left = 0; left + cnt < N; ++left) {
			int right = left + cnt;

			dp[left][right] = numeric_limits<int>::max();

			for (int mid = left; mid < right; ++mid)
				dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right] + matrix[left].r * matrix[mid].c * matrix[right].c);
		}
	}

	cout << dp[0][N - 1] << '\n';

	return 0;
}
