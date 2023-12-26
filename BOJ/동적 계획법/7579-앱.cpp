#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int costSum{};
	vector<int> memory(N);
	vector<int> cost(N);

	for (auto& m : memory)
		cin >> m;

	for (auto& c : cost) {
		cin >> c;
		costSum += c;
	}

	vector<int> dp(costSum + 1);

	for (int i = 0; i < N; ++i)
		for (int c = costSum; c >= cost[i]; --c)
			dp[c] = max(dp[c], dp[c - cost[i]] + memory[i]);

	for (int c = 0; c <= costSum; ++c) {
		if (dp[c] >= M) {
			cout << c << '\n';
			break;
		}
	}

	return 0;
}
