#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int INF = 987'654'321;

bool isValid(const int K, vector<int> coins) {
	sort(coins.begin(), coins.end());

	int en = 0;

	for (const auto& coin : coins) {
		if (en + 1 < coin)
			break;

		en += coin;

		if (en >= K)
			return true;
	}

	return false;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int N, K;
		cin >> N >> K;

		vector<int> coins(N);

		for (auto& coin : coins)
			cin >> coin;

		int left = 0;
		int right = N;
		int ans = INF;

		while (left <= right) {
			const int mid = left + (right - left) / 2;

			if (isValid(K, vector<int>(coins.begin(), coins.begin() + mid))) {
				ans = mid;
				right = mid - 1;
			}
			else
				left = mid + 1;
		}

		cout << (ans == INF ? -1 : ans) << '\n';
	}

	return 0;
}
