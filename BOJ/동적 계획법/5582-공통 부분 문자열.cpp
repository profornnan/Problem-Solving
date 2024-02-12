#include <iostream>
#include <string>
using namespace std;

constexpr int MAX_L = 4'000;

int dp[MAX_L + 1][MAX_L + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string A, B;
	cin >> A >> B;

	int ans = 0;

	for (int i = 1; i <= A.size(); ++i) {
		for (int j = 1; j <= B.size(); ++j) {
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			ans = ans > dp[i][j] ? ans : dp[i][j];
		}
	}

	cout << ans << '\n';

	return 0;
}
