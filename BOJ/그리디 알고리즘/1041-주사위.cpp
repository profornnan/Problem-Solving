#include <iostream>
#include <algorithm>
using namespace std;

constexpr int INF = 987654321;

long long N, ans;
int dice[6];
int sum, maxNum;
int one = INF, two = INF, three = INF;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < 6; ++i) {
		cin >> dice[i];
		sum += dice[i];
		maxNum = max(maxNum, dice[i]);
	}

	for (int i = 0; i < 6; ++i) {
		one = min(one, dice[i]);

		for (int j = i + 1; j < 6; ++j) {
			if (i + j == 5)
				continue;

			two = min(two, dice[i] + dice[j]);

			for (int k = j + 1; k < 6; ++k) {
				if (i + k == 5 || j + k == 5)
					continue;

				three = min(three, dice[i] + dice[j] + dice[k]);
			}
		}
	}

	if (N == 1)
		ans = sum - maxNum;
	else
		ans = 4 * three + (8 * N - 12) * two + (5 * N - 6) * (N - 2) * one;

	cout << ans << '\n';

	return 0;
}
