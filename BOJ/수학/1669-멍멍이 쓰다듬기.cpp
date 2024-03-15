#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int st, en;
	cin >> st >> en;

	const int diff = en - st;

	if (diff == 0) {
		cout << "0\n";
		return 0;
	}

	int cnt = 1;
	long long sum = 0;

	while (diff > sum + cnt * 2) {
		sum += cnt * 2;
		++cnt;
	}

	cout << (sum + cnt >= diff ? 2 * cnt - 1 : 2 * cnt) << '\n';

	return 0;
}
