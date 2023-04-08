#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[101][101];

string add(string a, string b) {
	string res;
	int sum = 0;
	int len = max(a.size(), b.size());

	for (int i = 0; i < len; i++) {
		if (i < a.size())
			sum += a[i] - '0';
		if (i < b.size())
			sum += b[i] - '0';

		res += sum % 10 + '0';
		sum /= 10;
	}

	if (sum != 0)
		res += sum + '0';

	return res;
}

string combination(int n, int m) {
	if (n == m || m == 0)
		return "1";

	if (!dp[n][m].empty())
		return dp[n][m];

	return dp[n][m] = add(combination(n - 1, m), combination(n - 1, m - 1));
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	string res = combination(n, m);
	reverse(res.begin(), res.end());

	cout << res << '\n';

	return 0;
}
