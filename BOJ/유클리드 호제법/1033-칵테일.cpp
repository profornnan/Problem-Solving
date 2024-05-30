#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_N = 10;

int N;
vector<pair<int, int>> adj[MAX_N];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int dfs(const int now, const int prev) {
	int ret = 1;

	for (const auto& [next, cost] : adj[now])
		if (next != prev)
			ret = ret * cost * dfs(next, now);

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		int a, b, p, q;
		cin >> a >> b >> p >> q;

		int g = gcd(p, q);

		adj[a].push_back({ b, p / g });
		adj[b].push_back({ a, q / g });
	}

	vector<int> ans(N);

	for (int i = 0; i < N; ++i)
		ans[i] = dfs(i, i);

	int g = ans[0];

	for (int i = 1; i < N; ++i)
		g = gcd(g, ans[i]);

	for (int i = 0; i < N; ++i)
		cout << ans[i] / g << ' ';
	cout << '\n';

	return 0;
}
