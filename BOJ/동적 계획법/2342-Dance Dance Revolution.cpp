#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

constexpr int MAX_N = 100'000;

int moveCost[5][5]{
	{0, 2, 2, 2, 2},
	{0, 1, 3, 4, 3},
	{0, 3, 1, 3, 4},
	{0, 4, 3, 1, 3},
	{0, 3, 4, 3, 1}
};

int N;
int note[MAX_N + 1];
int dp[MAX_N][5][5];

int dfs(int idx, int leftFoot, int rightFoot) {
	if (idx == N)
		return 0;

	int& ret = dp[idx][leftFoot][rightFoot];

	if (ret != -1)
		return ret;	

	int nextPos = note[idx];

	if (leftFoot == nextPos)
		ret = moveCost[leftFoot][nextPos] + dfs(idx + 1, nextPos, rightFoot);
	else if (rightFoot == nextPos)
		ret = moveCost[rightFoot][nextPos] + dfs(idx + 1, leftFoot, nextPos);
	else
		ret = min(moveCost[leftFoot][nextPos] + dfs(idx + 1, nextPos, rightFoot), moveCost[rightFoot][nextPos] + dfs(idx + 1, leftFoot, nextPos));

	return ret;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (true) {
		cin >> note[N];
		if (!note[N]) break;
		++N;
	}

	memset(dp, -1, sizeof(dp));

	cout << dfs(0, 0, 0) << '\n';

	return 0;
}
