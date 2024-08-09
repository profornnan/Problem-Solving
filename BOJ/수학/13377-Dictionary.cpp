#include <iostream>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

constexpr int N = 9;

int factorial[N];
bool visited[N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	factorial[0] = 1;

	for (int i = 1; i < N; ++i)
		factorial[i] = factorial[i - 1] * i;

	int T;
	cin >> T;

	while (T--) {
		string str;
		cin >> str;

		int ans = 0;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < N; ++i) {
			const int now = str[i] - 'a';
			const int cnt = now - accumulate(visited, visited + now, 0);

			ans += cnt * factorial[N - 1 - i];
			visited[now] = true;
		}

		cout << ans + 1 << '\n';
	}

	return 0;
}
