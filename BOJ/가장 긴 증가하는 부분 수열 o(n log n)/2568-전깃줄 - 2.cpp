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

int lowerBound(const vector<int>& arr, const int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Edge> edges(N);
	vector<int> idx(N);
	vector<int> seq;

	for (auto& [st, en] : edges)
		cin >> st >> en;

	sort(edges.begin(), edges.end());

	seq.push_back(edges[0].en);

	for (int i = 1; i < N; ++i) {
		if (seq.back() < edges[i].en) {
			idx[i] = seq.size();
			seq.push_back(edges[i].en);
		}
		else {
			const int lb = lowerBound(seq, edges[i].en);
			idx[i] = lb;
			seq[lb] = edges[i].en;
		}
	}

	cout << N - seq.size() << '\n';

	int k = seq.size() - 1;
	vector<bool> check(N);

	for (int i = N - 1; i >= 0; --i) {
		if (idx[i] == k) {
			check[i] = true;
			--k;
		}
	}

	for (int i = 0; i < N; ++i)
		if (!check[i])
			cout << edges[i].st << '\n';

	return 0;
}
