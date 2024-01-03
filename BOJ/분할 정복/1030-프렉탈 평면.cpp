#include <iostream>
using namespace std;

int N, K;
int blackSt, blackEn;

int fractal(int r, int c, int s) {
	if (s == 0)
		return 0;

	const int nr = r % N;
	const int nc = c % N;

	if (nr >= blackSt && nr <= blackEn && nc >= blackSt && nc <= blackEn)
		return 1;

	return fractal(r / N, c / N, s - 1);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int s, r1, r2, c1, c2;
	cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;

	blackSt = (N - K) / 2;
	blackEn = N - 1 - blackSt;

	for (int r = r1; r <= r2; ++r) {
		for (int c = c1; c <= c2; ++c)
			cout << fractal(r, c, s);
		cout << '\n';
	}

	return 0;
}
