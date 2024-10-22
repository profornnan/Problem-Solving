#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX_N = 9;

enum {
	EMPTY = 0,
	WON = 1,
	LOST = -1
};

int N, M, ans;
int match[MAX_N + 1][MAX_N + 1];
int won[MAX_N + 1];
int lost[MAX_N + 1];

void dfs(int a, int b) {
	if (b > N) {
		++a;
		b = a + 1;
	}

	if (a > N - 1) {
		++ans;
		return;
	}

	if (match[a][b] == EMPTY) {
		if (won[a] < (N - 1) / 2 && lost[b] < (N - 1) / 2) {
			++won[a];
			++lost[b];
			dfs(a, b + 1);
			--lost[b];
			--won[a];
		}

		if (won[b] < (N - 1) / 2 && lost[a] < (N - 1) / 2) {
			++won[b];
			++lost[a];
			dfs(a, b + 1);
			--lost[a];
			--won[b];
		}
	}
	else if (match[a][b] == WON) {
		if (won[a] < (N - 1) / 2 && lost[b] < (N - 1) / 2) {
			++won[a];
			++lost[b];
			dfs(a, b + 1);
			--lost[b];
			--won[a];
		}
	}
	else if (match[a][b] == LOST) {
		if (won[b] < (N - 1) / 2 && lost[a] < (N - 1) / 2) {
			++won[b];
			++lost[a];
			dfs(a, b + 1);
			--lost[a];
			--won[b];
		}
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (true) {
		cin >> N;

		if (!N)
			break;

		ans = 0;
		memset(match, 0, sizeof(match));
		memset(won, 0, sizeof(won));
		memset(lost, 0, sizeof(lost));

		cin >> M;

		for (int i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;

			match[a][b] = WON;
			match[b][a] = LOST;
		}

		dfs(1, 2);

		cout << ans << '\n';
	}

	return 0;
}
