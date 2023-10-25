#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	long long X;
	cin >> N >> X;

	vector<long long> C(N);

	for (auto& c : C)
		cin >> c;

	sort(C.begin(), C.end());

	int left = 0;
	int right = N - 1;
	int cnt = 0;

	while (right >= 0 && C[right] == X) {
		--right;
		++cnt;
	}

	int remain = N - cnt;

	while (left < right) {
		if (C[left] + C[right] >= (X + 1) / 2) {
			++cnt;
			--right;
			remain -= 2;
		}

		++left;
	}

	cout << cnt + remain / 3 << '\n';

	return 0;
}
