#include <iostream>
#include <algorithm>
#include <string>
#include <array>
using namespace std;

constexpr int BASE = 36;
constexpr int LEN = 52;

int N, K;
array<int, LEN> ans;
array<int, LEN> subs[BASE];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		for (int j = 0; j < str.size(); ++j) {
			const char ch = str[j];
			const int digit = str.size() - j - 1;
			const int num = 'A' <= ch && ch <= 'Z' ? ch - 'A' + 10 : ch - '0';

			ans[digit] += num;
			subs[num][digit] += BASE - num - 1;
		}
	}

	for (int i = 0; i < BASE; ++i) {
		for (int j = 0; j < LEN - 1; ++j) {
			subs[i][j + 1] += subs[i][j] / BASE;
			subs[i][j] %= BASE;
		}
	}

	sort(subs, subs + BASE, [](const array<int, LEN>& lhs, const array<int, LEN>& rhs) {
		for (int i = LEN - 1; i >= 0; --i)
			if (lhs[i] != rhs[i])
				return lhs[i] > rhs[i];

		return false;
	});

	cin >> K;

	for (int i = 0; i < K; ++i)
		for (int j = 0; j < LEN; ++j)
			ans[j] += subs[i][j];

	for (int i = 0; i < LEN - 1; ++i) {
		ans[i + 1] += ans[i] / BASE;
		ans[i] %= BASE;
	}

	int digit = LEN - 1;

	for (; digit > 0; --digit)
		if (ans[digit])
			break;

	for (; digit >= 0; --digit)
		cout << static_cast<char>(ans[digit] < 10 ? ans[digit] + '0' : ans[digit] + 'A' - 10);

	cout << '\n';

	return 0;
}
