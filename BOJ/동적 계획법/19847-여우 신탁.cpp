#include <iostream>
using namespace std;

constexpr int MAX_X = 1'000'000;

int N, X;
int dp[MAX_X];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cout << fixed;
	cout.precision(12);

	cin >> N >> X;

	for (int i = 0; i < X; ++i)
		dp[i] = 1;

	int minX = X;

	for (int i = 1; i < N; ++i) {
		int x;
		cin >> x;

		if (minX <= x)
			continue;

		for (int j = x; j < minX; ++j)
			dp[j % x] += dp[j];

		minX = x;
	}

	long long sum = 0;

	for (int i = 0; i < minX; ++i)
		sum += i * dp[i];

	cout << static_cast<double>(sum) / X << '\n';

	return 0;
}
