#include <iostream>
#include <string>
using namespace std;

constexpr int M = 4;
const string word = "DKSH";

int N;
string str;
long long dp[M + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> str;

	dp[M] = 1;

	for (int i = N - 1; i >= 0; --i)
		for (int j = M - 1; j >= 0; --j)
			if (str[i] == word[j])
				dp[j] += dp[j + 1];

	cout << dp[0] << '\n';

	return 0;
}
