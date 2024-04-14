#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N;

	int minIdx = 0;
	vector<int> price(N);
	vector<int> ans;

	for (int i = 0; i < N; ++i) {
		cin >> price[i];

		if (minIdx == 0 || price[i] <= price[minIdx])
			minIdx = i;
	}

	cin >> M;

	if (M < price[minIdx]) {
		cout << "0\n";
		return 0;
	}

	ans.push_back(minIdx);
	M -= price[minIdx];

	if (price[0] < price[minIdx])
		minIdx = 0;

	while (price[minIdx] <= M) {
		ans.push_back(minIdx);
		M -= price[minIdx];
	}

	for (auto& i : ans) {
		for (int j = N - 1; j > i; --j) {
			if (M + price[i] < price[j])
				continue;

			M += price[i] - price[j];
			i = j;
			break;
		}
	}

	for (const auto& i : ans)
		cout << i;
	cout << '\n';

	return 0;
}
