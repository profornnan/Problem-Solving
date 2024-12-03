#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int C, N;
	cin >> C >> N;

	const int M = C * N;
	vector<int> orders(C);
	vector<pair<int, int>> cards(M);

	for (int i = 0; i < C; ++i)
		orders[i] = i;

	for (auto& [color, num] : cards) {
		cin >> color >> num;
		--color;
	}

	int res = 0;

	do {
		vector<int> arr(M);
		vector<int> seq;

		for (int i = 0; i < M; ++i) {
			const auto& [color, num] = cards[i];
			arr[i] = orders[color] * N + num;
		}

		seq.push_back(arr[0]);

		for (int i = 1; i < M; ++i) {
			if (seq.back() < arr[i])
				seq.emplace_back(arr[i]);
			else
				seq[lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin()] = arr[i];
		}

		res = res > seq.size() ? res : seq.size();
	} while (next_permutation(orders.begin(), orders.end()));

	cout << M - res << '\n';

	return 0;
}
