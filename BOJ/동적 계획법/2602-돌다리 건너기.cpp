#include <iostream>
#include <string>
#include <numeric>
using namespace std;

string str;
string MAP[2];
int dp[20][2][100];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> str;
	cin >> MAP[0] >> MAP[1];

	const int N = str.length();
	const int M = MAP[0].length();

	for (int r = 0; r < 2; ++r)
		for (int c = 0; c < M; ++c)
			if (MAP[r][c] == str[0])
				dp[0][r][c] = 1;

	for (int i = 0; i < N - 1; ++i)
		for (int r = 0; r < 2; ++r)
			for (int c = i; c < M; ++c)
				for (int nc = c + 1; nc < M; ++nc)
					if (MAP[(r + 1) % 2][nc] == str[i + 1])
						dp[i + 1][(r + 1) % 2][nc] += dp[i][r][c];

	cout << accumulate(dp[N - 1][0], dp[N - 1][2], 0) << '\n';

	return 0;
}
