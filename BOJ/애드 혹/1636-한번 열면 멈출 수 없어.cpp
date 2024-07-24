#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 100'000;

struct Range {
	int st;
	int en;
};

int N, sum;
Range ranges[MAX_N];
int records[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> ranges[i].st >> ranges[i].en;

	int stress = 0;
	auto [left, right] = ranges[0];

	for (int i = 0; i < N; ++i) {
		const auto& [st, en] = ranges[i];

		if (en < left) {
			stress = left;
			break;
		}
		else if (right < st) {
			stress = right;
			break;
		}

		stress = left = max(left, st);
		right = min(right, en);
	}

	for (int i = 0; i < N; ++i) {
		const auto& [st, en] = ranges[i];

		if (en < stress) {
			sum += stress - en;
			stress = en;
		}
		else if (stress < st) {
			sum += st - stress;
			stress = st;
		}

		records[i] = stress;
	}

	cout << sum << '\n';

	for (int i = 0; i < N; ++i)
		cout << records[i] << '\n';

	return 0;
}
