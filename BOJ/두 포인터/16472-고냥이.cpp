#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

constexpr int SIZE = 26;

int cnts[SIZE];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	string str;
	cin >> str;

	int left = 0;
	int right = 0;
	int typeCnt = 0;
	int ans = 0;

	while (left < str.size() && right < str.size()) {
		if (typeCnt <= N && cnts[str[right++] - 'a']++ == 0)
			++typeCnt;
		else if (typeCnt > N && --cnts[str[left++] - 'a'] == 0)
			--typeCnt;

		if (typeCnt <= N)
			ans = max(ans, right - left);
	}

	cout << ans << '\n';

	return 0;
}
