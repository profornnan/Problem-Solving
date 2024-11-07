#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int INF = 987'654'321;
constexpr int MAX_N = 20;
constexpr int M = 5;

int N;
int A[MAX_N + 1][MAX_N + 1];
int area[MAX_N + 1][MAX_N + 1];
int sum[M + 1];
int ans = INF;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int x = 1; x <= N; x++)
		for (int y = 1; y <= N; y++)
			cin >> A[x][y];

	for (int x = 1; x <= N; x++) {
		for (int y = 2; y < N; y++) {
			for (int d1 = 1; d1 < N - 1; d1++) {
				for (int d2 = 1; d2 < N - 1; d2++) {
					if (x + d1 + d2 > N || y - d1 < 1 || y + d2 > N)
						continue;

					memset(area, 0, sizeof(area));

					for (int r = 1; r <= x + d2; r++)
						for (int c = y + 1; c <= N; c++)
							area[r][c] = 2;

					for (int r = x + d2 + 1; r <= N; r++)
						for (int c = y - d1 + d2; c <= N; c++)
							area[r][c] = 4;

					area[x][y] = 5;

					int sc = y;
					int ec = y;

					for (int i = 1; i <= d1 + d2; ++i) {
						sc += i <= d1 ? -1 : 1;
						ec += i <= d2 ? 1 : -1;

						for (int c = sc; c <= ec; c++)
							area[x + i][c] = 5;
					}

					for (int r = 1; r < x + d1; r++) {
						for (int c = 1; c <= y; c++) {
							if (area[r][c] == 5)
								break;

							area[r][c] = 1;
						}
					}

					for (int r = x + d1; r <= N; r++) {
						for (int c = 1; c < y - d1 + d2; c++) {
							if (area[r][c] == 5)
								break;

							area[r][c] = 3;
						}
					}

					memset(sum, 0, sizeof(sum));

					for (int r = 1; r <= N; r++)
						for (int c = 1; c <= N; c++)
							sum[area[r][c]] += A[r][c];

					int maxSum = sum[1];
					int minSum = sum[1];

					for (int i = 2; i <= M; i++) {
						maxSum = max(maxSum, sum[i]);
						minSum = min(minSum, sum[i]);
					}

					ans = min(ans, maxSum - minSum);
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
