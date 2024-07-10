#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

constexpr int MAX_N = 100'000;

struct Node {
	int idx;
	long long val;
};

int N, D;
long long dp[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> D;

	deque<Node> dq;

	for (int i = 0; i < N; ++i) {
		cin >> dp[i];

		while (!dq.empty()) {
			if (dq.front().idx >= i - D) {
				dp[i] += max(0LL, dq.front().val);
				break;
			}

			dq.pop_front();
		}

		while (!dq.empty()) {
			if (dq.back().val >= dp[i])
				break;

			dq.pop_back();
		}

		dq.push_back({ i, dp[i] });
	}

	cout << *max_element(dp, dp + N) << '\n';

	return 0;
}
