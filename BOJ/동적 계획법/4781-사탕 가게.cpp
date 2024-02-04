#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (true) {
		double d;

		int N;
		cin >> N >> d;
		int M = d * 100 + 0.5;

		if (N == 0 && M == 0)
			break;

		vector<int> dp(M + 1);

		for (int k = 0; k < N; ++k) {
			int calorie;
			cin >> calorie >> d;
			int price = d * 100 + 0.5;

			for (int i = price; i <= M; ++i)
				dp[i] = max(dp[i], dp[i - price] + calorie);
		}

		cout << dp[M] << '\n';
	}

	return 0;
}
