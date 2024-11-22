#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int D;
	string str;
	long long dx;
	long long dy;

	cin >> D >> str >> dx >> dy;

	const int N = str.size();
	const long long M = 1LL << N;

	long long x = 0;
	long long y = 0;

	for (const auto& ch : str) {
		const int now = ch - '0';

		x <<= 1;
		y <<= 1;

		if (now == 1 || now == 4)
			++x;

		if (now == 3 || now == 4)
			++y;
	}

	x += dx;
	y -= dy;

	if (x < 0 || x >= M || y < 0 || y >= M) {
		cout << "-1\n";
		return 0;
	}

	string ans(N, '0');

	for (int i = 0; i < N; ++i) {
		auto& ch = ans[N - 1 - i];

		if (x & 1)
			ch += y & 1 ? 4 : 1;
		else
			ch += y & 1 ? 3 : 2;

		x >>= 1;
		y >>= 1;
	}

	cout << ans << '\n';

	return 0;
}
