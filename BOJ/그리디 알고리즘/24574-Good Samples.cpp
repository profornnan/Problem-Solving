#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	long long N, M, K;
	cin >> N >> M >> K;

	vector<int> ans;

	for (int i = 0; i < N; ++i) {
		int now = min(K - (N - 1 - i), M);

		if (now <= 0)
			break;

		if (i < now) {
			now = i + 1;
			ans.push_back(now);
		}
		else
			ans.push_back(ans[i - now]);

		K -= now;
	}

	if (K != 0 || ans.size() != N) {
		cout << "-1\n";
		return 0;
	}

	for (const auto& num : ans)
		cout << num << ' ';
	cout << '\n';

	return 0;
}
