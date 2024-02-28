#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N;

	vector<int> weights(N);

	for (auto& weight : weights)
		cin >> weight;

	const int weightSum = accumulate(weights.begin(), weights.end(), 0);

	vector<bool> dp(weightSum + 1);

	dp[0] = true;

	for (const auto& weight : weights) {
		for (int i = weightSum - weight; i >= 0; --i)
			if (dp[i]) dp[i + weight] = true;

		for (int i = 0; i <= weightSum; ++i)
			if (dp[i]) dp[abs(i - weight)] = true;
	}

	cin >> M;

	for (int m = 0; m < M; ++m) {
		int W;
		cin >> W;
		cout << (W <= weightSum && dp[W] ? "Y " : "N ");
	}

	cout << '\n';

	return 0;
}
