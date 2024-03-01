#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int maxLen = 0;
	vector<int> len(N);

	for (int i = 0; i < N; ++i) {
		string name;
		cin >> name;
		len[i] = name.length();
		maxLen = maxLen > len[i] ? maxLen : len[i];
	}

	vector<int> cnt(maxLen + 1);

	int left = 0;
	int right = K;
	long long ans = 0;

	for (int i = 0; i < right; ++i) {
		const int now = len[i];

		if (cnt[now])
			ans += cnt[now];

		++cnt[now];
	}

	while (right < N) {
		const int now = len[right];
		const int prev = len[left];

		if (cnt[now])
			ans += cnt[now];

		++cnt[now];
		--cnt[prev];

		++right;
		++left;
	}

	cout << ans << '\n';

	return 0;
}
