#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 987654321;
int N;
vector<int> dp;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N;

	dp = vector<int>(N + 1, INF);
	dp[0] = 0;

	int base = 1;

	while (true) {
		int num = base * base;
		
		if (num > N) break;

		for (int i = 1; i <= N; i++) {
			if (i - num < 0) continue;
			dp[i] = min(dp[i], dp[i - num] + 1);
		}

		base++;
	}

	cout << dp[N] << '\n';

	return 0;
}
