#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

long long N;
int P, Q;
unordered_map<long long, long long> dp{ {0, 1} };

long long dfs(long long now) {
	if (dp.count(now))
		return dp[now];

	return dp[now] = dfs(floor(static_cast<double>(now) / P)) + dfs(floor(static_cast<double>(now) / Q));
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> P >> Q;

	cout << dfs(N) << '\n';

	return 0;
}
