#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

constexpr int MAX_L = 1000;

int dp[MAX_L + 1][MAX_L + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string A, B;
	cin >> A >> B;

	for (int i = 1; i <= A.size(); ++i) {
		for (int j = 1; j <= B.size(); ++j) {
			if (A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[A.size()][B.size()] << '\n';

	return 0;
}
