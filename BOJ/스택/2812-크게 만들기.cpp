#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	string str;
	cin >> N >> K >> str;

	int cnt = 0;
	string ans;

	for (const auto& ch : str) {
		while (!ans.empty() && cnt < K && ch > ans.back()) {
			++cnt;
			ans.pop_back();
		}

		ans.push_back(ch);
	}

	while (cnt < K) {
		++cnt;
		ans.pop_back();
	}

	cout << ans << '\n';

	return 0;
}
