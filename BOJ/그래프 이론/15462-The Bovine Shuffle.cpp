#include <iostream>
using namespace std;

constexpr int MAX_N = 100'000;

int N, ans;
int to[MAX_N + 1];
bool visited[MAX_N + 1];
bool finished[MAX_N + 1];

void dfs(const int now) {
	visited[now] = true;

	const int next = to[now];

	if (!visited[next])
		dfs(next);
	else if (!finished[next]) {
		int t = next;

		do {
			++ans;
			t = to[t];
		} while (t != next);
	}

	finished[now] = true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 1; i <= N; ++i)
		cin >> to[i];

	for (int i = 1; i <= N; ++i)
		if (!visited[i])
			dfs(i);

	cout << ans << '\n';

	return 0;
}
