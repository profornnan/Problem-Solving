#include <iostream>
using namespace std;

int ans[10];

void calc(int n, int ten) {
	while (n > 0) {
		ans[n % 10] += ten;
		n /= 10;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int start = 1;
	int end;
	int ten = 1;

	cin >> end;

	while (start <= end) {
		while (start % 10 != 0 && start <= end) {
			calc(start, ten);
			++start;
		}

		if (start > end)
			break;

		while (end % 10 != 9 && start <= end) {
			calc(end, ten);
			--end;
		}

		int cnt = (end / 10 - start / 10 + 1);

		for (int i = 0; i <= 9; ++i)
			ans[i] += cnt * ten;

		start /= 10;
		end /= 10;
		ten *= 10;
	}

	for (int i = 0; i <= 9; ++i)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}
