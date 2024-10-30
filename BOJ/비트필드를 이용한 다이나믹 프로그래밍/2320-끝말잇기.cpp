#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_N = 16;
constexpr int MAX_C = 5;

int N;
string words[MAX_N];
int dp[MAX_C][1 << MAX_N];

int char2idx(const char ch) {
	switch (ch) {
	case 'A': return 0;
	case 'E': return 1;
	case 'I': return 2;
	case 'O': return 3;
	case 'U': return 4;
	default: return -1;
	}
}

int dfs(const int last, const int state) {
	if (state == (1 << N) - 1)
		return 0;

	const int en = char2idx(words[last].back());
	int& ret = dp[en][state];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = 0; i < N; ++i) {
		if (state & (1 << i))
			continue;

		if (en != char2idx(words[i].front()))
			continue;

		ret = max(ret, dfs(i, state | (1 << i)) + static_cast<int>(words[i].size()));
	}

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> words[i];

	memset(dp, -1, sizeof(dp));

	int ans = 0;

	for (int i = 0; i < N; ++i)
		ans = max(ans, dfs(i, 1 << i) + static_cast<int>(words[i].size()));

	cout << ans << '\n';

	return 0;
}
