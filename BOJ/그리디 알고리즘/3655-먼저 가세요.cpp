#include <iostream>
#include <string>
#include <cstring>
using namespace std;

constexpr int MAX_UC = 256;

int cnt[MAX_UC];
bool check[MAX_UC];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N;
		string str;

		cin >> N >> str;

		memset(cnt, 0, sizeof(cnt));
		memset(check, 0, sizeof(check));

		for (const char& ch : str)
			++cnt[ch];

		int ans = 0;
		int now = 0;

		for (int i = N - 1; i >= 0; --i) {
			if (check[str[i]])
				continue;

			check[str[i]] = true;
			ans += cnt[str[i]] * (now - (N - 1 - i));
			now += cnt[str[i]];
		}

		cout << ans * 5 << '\n';
	}

	return 0;
}
