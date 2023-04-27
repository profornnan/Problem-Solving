#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		int N, M;
		cin >> N >> M;

		int maskBit = (1 << N) - 1;

		cout << '#' << tc << ' ' << ((M & maskBit) == maskBit ? "ON" : "OFF") << '\n';
	}

	return 0;
}
