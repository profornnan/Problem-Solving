#include <iostream>
using namespace std;

char MAP[3072][6143];

void triangle(int y, int x, int n) {
	if (n == 3) {
		MAP[y][x] = '*';

		MAP[y + 1][x - 1] = '*';
		MAP[y + 1][x + 1] = '*';

		for (int i = 0; i < 5; ++i)
			MAP[y + 2][x - 2 + i] = '*';

		return;
	}

	const int half = n / 2;

	triangle(y, x, half);
	triangle(y + half, x - half, half);
	triangle(y + half, x + half, half);
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N * 2 - 1; ++x)
			MAP[y][x] = ' ';

	triangle(0, N - 1, N);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N * 2 - 1; ++x)
			cout << MAP[y][x];
		cout << '\n';
	}

	return 0;
}
