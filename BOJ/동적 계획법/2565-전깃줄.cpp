#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int st;
	int en;

	bool operator<(const Edge& rhs) const {
		return st != rhs.st ? st < rhs.st : en < rhs.en;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Edge> edges(N);
	vector<int> dp(N, 1);

	for (auto& [st, en] : edges)
		cin >> st >> en;

	sort(edges.begin(), edges.end());

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < i; ++j)
			if (edges[j].en < edges[i].en && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;

	cout << N - *max_element(dp.begin(), dp.end()) << '\n';

	return 0;
}
