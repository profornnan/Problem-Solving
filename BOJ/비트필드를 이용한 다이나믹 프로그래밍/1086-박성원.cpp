#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_N = 15;
constexpr int MAX_K = 100;
constexpr int MAX_L = 50;

int N, K;
string nums[MAX_N];
int tenRemains[MAX_L + 1];
int numRemains[MAX_N];
long long dp[1 << MAX_N][MAX_K];

long long dfs(int state, int remain) {
	if (state == (1 << N) - 1)
		return remain ? 0 : 1;

	long long& ret = dp[state][remain];

	if (ret != -1)
		return dp[state][remain];

	ret = 0;

	for (int i = 0; i < N; ++i)
		if (!(state & (1 << i)))
			ret += dfs(state | (1 << i), (remain * tenRemains[nums[i].size()] + numRemains[i]) % K);

	return ret;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	long long totalCnt = 1;

	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
		totalCnt *= i + 1;
	}

	cin >> K;

	tenRemains[0] = 1;

	for (int i = 1; i <= MAX_L; ++i)
		tenRemains[i] = (tenRemains[i - 1] * 10) % K;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < nums[i].size(); ++j)
			numRemains[i] = (numRemains[i] * 10 + nums[i][j] - '0') % K;

	memset(dp, -1, sizeof(dp));

	long long answerCnt = dfs(0, 0);
	long long g = gcd(totalCnt, answerCnt);

	cout << answerCnt / g << '/' << totalCnt / g << '\n';

	return 0;
}
