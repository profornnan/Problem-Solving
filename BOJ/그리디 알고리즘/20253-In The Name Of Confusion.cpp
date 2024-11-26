#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

constexpr int MOD = 1'000'000'007;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> pos;
	vector<int> neg;
	vector<int> zero;

	for (int i = 0; i < N; ++i) {
		int num;
		cin >> num;

		if (num > 0)
			pos.emplace_back(num);
		else if (num < 0)
			neg.emplace_back(num);
		else
			zero.emplace_back(num);
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	long long minCost = 0;
	long long maxCost = 0;

	if (!pos.empty() && !neg.empty()) {
		// pos, neg
		for (int i = 0; i < pos.size(); ++i)
			minCost = (minCost + static_cast<long long>(neg[0]) * pos[i]) % MOD;

		for (int i = 1; i < neg.size(); ++i)
			minCost = (minCost + static_cast<long long>(neg[i]) * pos[pos.size() - 1]) % MOD;

		for (int i = 1; i < neg.size(); ++i)
			maxCost = (maxCost + static_cast<long long>(neg[0]) * neg[i]) % MOD;

		for (int i = 0; i < pos.size() - 1; ++i)
			maxCost = (maxCost + static_cast<long long>(pos[i]) * pos[pos.size() - 1]) % MOD;

		if (zero.empty())
			maxCost = (maxCost + static_cast<long long>(neg[neg.size() - 1]) * pos[0]) % MOD;

		while (minCost < 0)
			minCost = (minCost + MOD) % MOD;

		while (maxCost < 0)
			maxCost = (maxCost + MOD) % MOD;
	}
	else if (!pos.empty()) {
		// pos
		if (zero.empty())
			for (int i = 1; i < pos.size(); ++i)
				minCost = (minCost + static_cast<long long>(pos[0]) * pos[i]) % MOD;

		for (int i = 0; i < pos.size() - 1; ++i)
			maxCost = (maxCost + static_cast<long long>(pos[i]) * pos[pos.size() - 1]) % MOD;
	}
	else if (!neg.empty()) {
		// neg
		if (zero.empty())
			for (int i = 0; i < neg.size() - 1; ++i)
				minCost = (minCost + static_cast<long long>(neg[i]) * neg[neg.size() - 1]) % MOD;

		for (int i = 1; i < neg.size(); ++i)
			maxCost = (maxCost + static_cast<long long>(neg[0]) * neg[i]) % MOD;
	}

	cout << minCost << ' ' << maxCost << '\n';

	return 0;
}
