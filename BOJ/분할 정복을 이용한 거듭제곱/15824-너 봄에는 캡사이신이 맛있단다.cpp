#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MOD = 1'000'000'007;

long long power(int x, int y) {
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	if (y % 2)
		return power(x, y - 1) * x % MOD;

	long long half = power(x, y / 2);

	return half * half % MOD;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> scale(N);

	for (auto& s : scale)
		cin >> s;

	sort(scale.begin(), scale.end(), greater<int>());

	long long ans = 0;

	for (int i = 0; i < N / 2; ++i)
		ans = (ans + (scale[i] - scale[N - 1 - i]) * (power(2, N - 1 - i) - power(2, i) + MOD)) % MOD;

	cout << ans << '\n';

	return 0;
}
