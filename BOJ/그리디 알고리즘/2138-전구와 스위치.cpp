#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

constexpr int INF = 987'654'321;
constexpr int dx[]{ -1, 0, 1 };

int N;
string st, en;
int ans = INF;

void push(string& state, const int x) {
	for (int i = 0; i < 3; ++i) {
		const int nx = x + dx[i];

		if (0 <= nx && nx < N)
			state[nx] = state[nx] == '0' ? '1' : '0';
	}
}

void solve(const bool pushFirst) {
	int cnt = 0;
	string state = st;

	if (pushFirst) {
		++cnt;
		push(state, 0);
	}

	for (int x = 0; x < N - 1; ++x) {
		if (state[x] != en[x]) {
			++cnt;
			push(state, x + 1);
		}
	}

	if (state[N - 1] == en[N - 1])
		ans = min(ans, cnt);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> st >> en;

	solve(true);
	solve(false);

	cout << (ans != INF ? ans : -1) << '\n';

	return 0;
}
