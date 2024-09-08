#include <iostream>
using namespace std;

const pair<int, int> dx7[]{
	{1, 0},
	{0, 1},
	{0, 1},
	{-1, 0},
	{-1, 0},
	{0, -1},
	{1, 0}
};

const pair<int, int> dy7[]{
	{0, 1},
	{-1, 0},
	{-1, 0},
	{0, -1},
	{0, -1},
	{1, 0},
	{0, 1}
};

const pair<int, int> dx15[]{
	{-1, 0},
	{0, 1},
	{1, 0},
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, 1},
	{0, -1},
	{1, 0},
	{0, -1},
	{-1, 0},
	{-1, 0},
	{0, -1},
	{1, 0},
	{0, 1}
};

const pair<int, int> dy15[]{
	{0, 1},
	{-1, 0},
	{0, 1},
	{0, -1},
	{1, 0},
	{0, -1},
	{-1, 0},
	{-1, 0},
	{0, -1},
	{1, 0},
	{0, -1},
	{0, 1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int F, S;
	cin >> F >> S;

	int x = 0;
	int y = 0;

	if (F * S == 0 || F == S) {
		cout << 7 << '\n';

		for (int i = 0; i < 7; ++i) {
			x += F * dx7[i].first + S * dx7[i].second;
			y += F * dy7[i].first + S * dy7[i].second;

			cout << x << ' ' << y << '\n';
		}
	}
	else {
		cout << 15 << '\n';

		for (int i = 0; i < 15; ++i) {
			x += F * dx15[i].first + S * dx15[i].second;
			y += F * dy15[i].first + S * dy15[i].second;

			cout << x << ' ' << y << '\n';
		}
	}

	return 0;
}
