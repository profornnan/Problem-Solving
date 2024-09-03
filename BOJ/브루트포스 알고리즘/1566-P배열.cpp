#include <iostream>
using namespace std;

constexpr int INF = 21e8;
constexpr int MAX_N = 18;
constexpr int MAX_M = 18;

int N, M;
int arr[MAX_N][MAX_M];
int ans = INF;

void solve(const int rowState) {
	int cnt = 0;
	int colState = 0;

	for (int y = 0; y < N; ++y)
		if (rowState & (1 << y))
			++cnt;

	if (ans <= cnt)
		return;

	for (int x = 0; x < M; ++x) {
		int sum = 0;

		for (int y = 0; y < N; ++y)
			sum += arr[y][x] * (rowState & (1 << y) ? -1 : 1);

		if (sum == 0)
			return;

		if (sum > 0)
			continue;

		++cnt;
		colState |= (1 << x);

		if (ans <= cnt)
			return;
	}

	for (int y = 0; y < N; ++y) {
		int sum = 0;

		for (int x = 0; x < M; ++x)
			sum += arr[y][x] * (rowState & (1 << y) ? -1 : 1) * (colState & (1 << x) ? -1 : 1);

		if (sum <= 0)
			return;
	}

	ans = ans < cnt ? ans : cnt;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> arr[y][x];

	for (int rowState = 0; rowState < (1 << N); ++rowState)
		solve(rowState);

	cout << (ans == INF ? -1 : ans) << '\n';

	return 0;
}
