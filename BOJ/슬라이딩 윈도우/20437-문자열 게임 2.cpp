#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

constexpr int INF = 987654321;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		string str;
		int K;

		cin >> str >> K;

		int minLen = INF;
		int maxLen = -1;

		for (char ch = 'a'; ch <= 'z'; ++ch) {
			int cnt = 0;
			int left = 0;
			int right = 0;

			while (right < str.size()) {
				if (str[right++] != ch)
					continue;

				++cnt;

				while (cnt >= K) {
					if (str[left++] != ch)
						continue;

					--cnt;

					minLen = min(minLen, right - left + 1);
					maxLen = max(maxLen, right - left + 1);
				}
			}
		}

		if (minLen == INF)
			cout << "-1\n";
		else
			cout << minLen << ' ' << maxLen << '\n';
	}

	return 0;
}
