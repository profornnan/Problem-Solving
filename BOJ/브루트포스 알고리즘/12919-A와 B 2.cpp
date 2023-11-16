#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int ans;

void dfs(const string& s, const string& t) {
	if (s.size() >= t.size()) {
		if (s == t)
			ans = 1;
		return;
	}

	if (t.back() == 'A') {
		string next = t;
		next.pop_back();
		dfs(s, next);
	}

	if (t.front() == 'B') {
		string next = t;
		reverse(next.begin(), next.end());
		next.pop_back();
		dfs(s, next);
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string s, t;
	cin >> s >> t;

	dfs(s, t);

	cout << ans << '\n';

	return 0;
}
