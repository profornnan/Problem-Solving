#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	int T;
	cin >> T;
	
	int total = (1 << 10) - 1;
	
	for (int tc = 1; tc <= T; tc++) {
		int N;
		int cnt = 0, visited = 0;

		cin >> N;

		while (true) {
			cnt++;

			string str = to_string(N * cnt);

			for (char ch : str)
				visited |= (1 << (ch - '0'));

			if (visited == total)
				break;
		}

		cout << '#' << tc << ' ' << N * cnt << '\n';
	}

	return 0;
}
