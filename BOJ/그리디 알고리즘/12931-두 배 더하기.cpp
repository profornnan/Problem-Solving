#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N);

	int ans = 0;
	int zeroCnt = 0;

	for (auto& num : arr) {
		cin >> num;

		if (num == 0)
			++zeroCnt;
	}

	while (true) {
		for (auto& num : arr) {
			if (!(num & 1))
				continue;

			if (--num == 0)
				++zeroCnt;

			++ans;
		}

		if (zeroCnt == N)
			break;

		++ans;

		for (auto& num : arr)
			num >>= 1;
	}

	cout << ans << '\n';

	return 0;
}
