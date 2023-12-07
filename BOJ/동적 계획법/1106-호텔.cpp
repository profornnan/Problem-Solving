#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int C, N;
	cin >> C >> N;

	const int maxC = C * 100;

	vector<pii> ad(N);
	vector<int> dp(maxC + 1);

	for (auto& [cost, client] : ad)
		cin >> cost >> client;

	for (const auto& [cost, client] : ad)
		for (int i = 1; i <= maxC; ++i)
			if (i - cost >= 0)
				dp[i] = max(dp[i], dp[i - cost] + client);

	for (int i = 1; i <= maxC; ++i) {
		if (dp[i] >= C) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}
