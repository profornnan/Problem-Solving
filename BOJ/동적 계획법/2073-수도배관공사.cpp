#include <iostream>
#include <algorithm>
using namespace std;

constexpr int INF = 987654321;
constexpr int MAX_D = 100'000;

int D, P;
int dp[MAX_D + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> D >> P;

	dp[0] = INF;

	for (int i = 0; i < P; ++i) {
		int L, C;
		cin >> L >> C;

		for (int j = D; j >= L; --j)
			dp[j] = max(dp[j], min(dp[j - L], C));
	}

	cout << dp[D] << '\n';

	return 0;
}
