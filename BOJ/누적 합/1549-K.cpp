#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Sub {
	long long sum;
	int idx;

	bool operator<(const Sub& rhs) const {
		return sum != rhs.sum ? sum < rhs.sum : idx < rhs.idx;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<long long> psum(N + 1);

	for (int i = 1; i <= N; ++i) {
		cin >> psum[i];
		psum[i] += psum[i - 1];
	}

	int K = 0;
	long long minDiff = psum[N];

	for (int k = 1; k <= N / 2; ++k) {
		vector<Sub> subs;

		for (int i = k; i <= N; ++i)
			subs.push_back({ psum[i] - psum[i - k], i });

		sort(subs.begin(), subs.end());

		for (int i = 1; i < subs.size(); ++i) {
			if (abs(subs[i].idx - subs[i - 1].idx) < k)
				continue;

			const long long diff = subs[i].sum - subs[i - 1].sum;

			if (minDiff >= diff) {
				minDiff = diff;
				K = k;
			}
		}

		int st = 0;

		for (int i = 1; i < subs.size(); ++i) {
			if (subs[i].sum != subs[st].sum) {
				st = i;
				continue;
			}

			if (abs(subs[i].idx - subs[st].idx) < k)
				continue;

			const long long diff = subs[i].sum - subs[st].sum;

			if (minDiff >= diff) {
				minDiff = diff;
				K = k;
			}
		}
	}

	cout << K << '\n' << minDiff << '\n';

	return 0;
}
