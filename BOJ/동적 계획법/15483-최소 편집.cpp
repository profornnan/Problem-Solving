#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_L = 1'000;

string A, B;
int dp[MAX_L][MAX_L];

int dfs(int aIdx, int bIdx) {
	if (aIdx >= A.size() && bIdx >= B.size())
		return 0;
	else if (aIdx >= A.size())
		return B.size() - bIdx;
	else if (bIdx >= B.size())
		return A.size() - aIdx;

	int& ret = dp[aIdx][bIdx];

	if (ret != -1)
		return ret;

	return ret = min({ dfs(aIdx + 1, bIdx + 1) + (A[aIdx] != B[bIdx]), dfs(aIdx, bIdx + 1) + 1, dfs(aIdx + 1, bIdx) + 1 });
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> A >> B;
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << '\n';

	return 0;
}
