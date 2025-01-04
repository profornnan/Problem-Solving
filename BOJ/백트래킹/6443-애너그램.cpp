#include <iostream>
#include <string>
#include <cstring>
using namespace std;

constexpr int SIZE = 26;

int T;
string str;
int cnt[SIZE];
string path;

void dfs() {
	if (path.size() >= str.size()) {
		cout << path << '\n';
		return;
	}

	for (int i = 0; i < SIZE; ++i) {
		if (!cnt[i])
			continue;

		--cnt[i];
		path.push_back(i + 'a');
		dfs();
		path.pop_back();
		++cnt[i];
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	while (T--) {
		cin >> str;

		memset(cnt, 0, sizeof(cnt));

		for (const auto& ch : str)
			++cnt[ch - 'a'];

		dfs();
	}

	return 0;
}
