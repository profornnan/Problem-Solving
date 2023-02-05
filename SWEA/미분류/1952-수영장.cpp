#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int charge[4];  // 1일, 1달, 3달, 1년
int plan[13];
int dp[16][3];

int main(void) {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';

		memset(dp, 0, sizeof(dp));

		for (int i = 0; i < 4; i++)
			cin >> charge[i];

		for (int i = 1; i <= 12; i++)
			cin >> plan[i];

		for (int m = 12; m >= 1; m--) {
			if (plan[m] != 0) {
				dp[m][0] = plan[m] * charge[0] + min(dp[m + 1][0], min(dp[m + 1][1], dp[m + 1][2]));
				dp[m][1] = charge[1] + min(dp[m + 1][0], min(dp[m + 1][1], dp[m + 1][2]));
				dp[m][2] = charge[2] + min(dp[m + 3][0], min(dp[m + 3][1], dp[m + 3][2]));
			}
			else {
				dp[m][0] = dp[m + 1][0];
				dp[m][1] = dp[m + 1][1];
				dp[m][2] = dp[m + 1][2];
			}
		}

		cout << min(min(charge[3], dp[1][0]), min(dp[1][1], dp[1][2])) << '\n';
	}
	return 0;
}
