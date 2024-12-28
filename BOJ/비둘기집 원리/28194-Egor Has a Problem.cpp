#include <iostream>
#include <cmath>
using namespace std;

constexpr int MAX_N = 500'000;
constexpr int M = 4;

int N;
long long arr[MAX_N];
int path[M];
bool printed;

void dfs(const int level, const int prev) {
	if (printed)
		return;

	if (level >= M) {
		if (arr[path[1]] / arr[path[0]] == arr[path[3]] / arr[path[2]]) {
			cout << "YES\n";

			for (int i = 0; i < M; ++i)
				cout << path[i] + 1 << ' ';

			cout << '\n';

			printed = true;
		}

		return;
	}

	for (int now = prev + 1; now < N; ++now) {
		path[level] = now;
		dfs(level + 1, now);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	if (log2(arr[N - 1]) + M - 1 < N) {
		cout << "YES\n";

		int cnt = 0;

		for (int i = 1; i < N; ++i) {
			if (arr[i] / arr[i - 1] == 1) {
				cout << i << ' ' << i + 1 << ' ';

				if (++cnt == 2)
					break;

				++i;
			}
		}

		cout << '\n';
	}
	else {
		dfs(0, -1);

		if (!printed)
			cout << "NO\n";
	}

	return 0;
}
