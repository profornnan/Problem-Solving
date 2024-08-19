#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	string str;
	int K;

	cin >> str >> K;

	const int step = str.size() - K;
	int ans = 0;

	for (int st = 0; st < step; ++st) {
		vector<int> cnts('z' - 'a' + 1);

		int maxIdx = str[st] - 'a';

		for (int i = st; i < str.size(); i += step) {
			const int idx = str[i] - 'a';

			++cnts[idx];

			if (cnts[maxIdx] < cnts[idx])
				maxIdx = idx;
		}

		for (int i = st; i < str.size(); i += step)
			if (str[i] - 'a' != maxIdx)
				++ans;
	}

	cout << ans << '\n';

	return 0;
}
