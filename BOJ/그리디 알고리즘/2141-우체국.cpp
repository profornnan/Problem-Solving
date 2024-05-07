#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> town(N);

	long long totalSum = 0;
	long long sum = 0;

	for (auto& [pos, cnt] : town) {
		cin >> pos >> cnt;
		totalSum += cnt;
	}

	sort(town.begin(), town.end());

	for (const auto& [pos, cnt] : town) {
		sum += cnt;

		if (sum >= (totalSum + 1) / 2) {
			cout << pos << '\n';
			break;
		}
	}

	return 0;
}
