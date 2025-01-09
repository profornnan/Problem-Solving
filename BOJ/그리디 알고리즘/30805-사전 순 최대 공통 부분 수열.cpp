#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
	int idx;
	int num;

	bool operator<(const Node& rhs) const {
		return num != rhs.num ? num > rhs.num : idx < rhs.idx;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<Node> A(N);

	for (int i = 0; i < N; ++i) {
		auto& [idx, num] = A[i];
		idx = i;
		cin >> num;
	}

	int M;
	cin >> M;

	vector<Node> B(M);

	for (int i = 0; i < M; ++i) {
		auto& [idx, num] = B[i];
		idx = i;
		cin >> num;
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int ai = 0;
	int bi = 0;
	int aPrev = -1;
	int bPrev = -1;

	vector<int> ans;

	while (ai < N && bi < M) {
		const auto& a = A[ai];
		const auto& b = B[bi];

		if (aPrev > a.idx) {
			++ai;
		}
		else if (bPrev > b.idx) {
			++bi;
		}
		else if (a.num == b.num) {
			++ai;
			++bi;
			aPrev = a.idx;
			bPrev = b.idx;
			ans.push_back(a.num);
		}
		else if (a.num > b.num) {
			++ai;
		}
		else if (a.num < b.num) {
			++bi;
		}
	}

	cout << ans.size() << '\n';

	for (const auto& num : ans)
		cout << num << ' ';
	cout << '\n';

	return 0;
}
