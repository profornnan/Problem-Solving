#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int en;
	int idx;

	bool operator<(const Node& rhs) const {
		return idx > rhs.idx;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N, K;
		cin >> N >> K;

		vector<pair<int, int>> arr(N);

		for (int i = 0; i < N; ++i) {
			auto& [st, idx] = arr[i];
			cin >> st;
			idx = i;
		}

		sort(arr.begin(), arr.end());

		long long ans = 0;
		priority_queue<Node> pq;

		for (const auto& [st, idx] : arr) {
			while (!pq.empty() && pq.top().en < st)
				pq.pop();

			if (!pq.empty() && idx > pq.top().idx)
				ans += idx - pq.top().idx;

			pq.push({ st + K, idx });
		}

		cout << "Case #" << tc << '\n' << ans << '\n';
	}

	return 0;
}
