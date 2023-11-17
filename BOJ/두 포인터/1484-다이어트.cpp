#include <iostream>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int G;
	cin >> G;

	int left = 1;
	int right = 2;
	int cnt = 0;

	while (left < right) {
		int g = right * right - left * left;

		if (g == G) {
			cout << right << ' ';
			++cnt;
			++left;
		}
		else if (g < G)
			++right;
		else if (g > G)
			++left;
	}

	if (!cnt)
		cout << -1;
	cout << '\n';

	return 0;
}
