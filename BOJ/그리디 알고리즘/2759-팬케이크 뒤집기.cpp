#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector<int> arr(N);

		for (auto& num : arr)
			cin >> num;

		vector<int> ans;

		for (int en = N - 1; en > 0; --en) {
			const int maxIdx = max_element(arr.begin(), arr.begin() + en + 1) - arr.begin();

			if (maxIdx == en)
				continue;

			if (maxIdx != 0) {
				reverse(arr.begin(), arr.begin() + maxIdx + 1);
				ans.push_back(maxIdx + 1);
			}

			reverse(arr.begin(), arr.begin() + en + 1);
			ans.push_back(en + 1);
		}

		cout << ans.size() << ' ';

		for (const auto& cnt : ans)
			cout << cnt << ' ';
		cout << '\n';
	}

	return 0;
}
