#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

long long ans;
string str;
unordered_set<char> vowels = { 'A','E','I','O','U' };

void dfs(int idx, long long cnt, int consonantCnt, int vowelCnt, bool isContainL) {
	if (idx >= str.size()) {
		if (isContainL)
			ans += cnt;
		return;
	}

	const char ch = str[idx];

	if (ch == '_') {
		if (vowelCnt < 2)
			dfs(idx + 1, cnt * 5, 0, vowelCnt + 1, isContainL);

		if (consonantCnt < 2) {
			dfs(idx + 1, cnt * 20, consonantCnt + 1, 0, isContainL);
			dfs(idx + 1, cnt, consonantCnt + 1, 0, true);
		}
	}
	else if (vowels.find(ch) != vowels.end()) {
		if (vowelCnt < 2)
			dfs(idx + 1, cnt, 0, vowelCnt + 1, isContainL);
	}
	else {
		if (consonantCnt < 2)
			dfs(idx + 1, cnt, consonantCnt + 1, 0, isContainL || (ch == 'L'));
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> str;

	dfs(0, 1, 0, 0, false);

	cout << ans << '\n';

	return 0;
}
