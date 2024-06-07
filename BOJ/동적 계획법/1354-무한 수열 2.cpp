#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long N, P, Q, X, Y;
unordered_map<long long, long long> dp{ {0, 1} };

long long dfs(long long n) {
	if (dp.count(n))
		return dp[n];

	return dp[n] = dfs(max(0LL, (n / P) - X)) + dfs(max(0LL, (n / Q) - Y));
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> P >> Q >> X >> Y;

	cout << dfs(N) << '\n';

	return 0;
}
