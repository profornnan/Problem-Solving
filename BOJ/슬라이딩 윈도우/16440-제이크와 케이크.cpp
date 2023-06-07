#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int N;
	string cake;
	cin >> N >> cake;

	int scnt = 0, kcnt = 0;
	int left = 0, right = N / 2 - 1;

	for (int i = 0; i < right; i++)
		cake[i] == 's' ? scnt++ : kcnt++;

	while (left < N / 2) {
		cake[right] == 's' ? scnt++ : kcnt++;

		if (scnt == N / 4 && kcnt == N / 4)
			break;

		cake[left] == 's' ? scnt-- : kcnt--;

		right++;
		left++;
	}

	if (left == 0)
		cout << 1 << '\n' << right + 1 << '\n';
	else
		cout << 2 << '\n' << left << ' ' << right + 1 << '\n';

	return 0;
}
