#include <iostream>
using namespace std;

constexpr int MAX_N = 1'000'000;

int T, N;
bool dp[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	for (int i = 0; i <= MAX_N; ++i)
		if (!dp[i])
			for (int j = 1; i + j * j <= MAX_N; ++j)
				dp[i + j * j] = true;

	cin >> T;

	while (T--) {
		cin >> N;
		cout << (dp[N] ? "koosaga" : "cubelover") << '\n';
	}

	return 0;
}
