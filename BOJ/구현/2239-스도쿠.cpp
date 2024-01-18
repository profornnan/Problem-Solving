#include <iostream>
#include <string>
using namespace std;

constexpr int SIZE = 9;

int MAP[SIZE][SIZE];
int rowState[SIZE];
int colState[SIZE];
int squareState[SIZE / 3][SIZE / 3];
bool isPrinted;

void dfs(int level) {
	if (isPrinted)
		return;

	if (level >= SIZE * SIZE) {
		for (int y = 0; y < SIZE; ++y) {
			for (int x = 0; x < SIZE; ++x)
				cout << MAP[y][x];
			cout << '\n';
		}

		isPrinted = true;
		return;
	}

	const int y = level / SIZE;
	const int x = level % SIZE;

	if (MAP[y][x] != 0) {
		dfs(level + 1);
		return;
	}

	for (int num = 1; num <= SIZE; ++num) {
		int mask = (1 << num);

		if ((rowState[y] & mask) || (colState[x] & mask) || (squareState[y / 3][x / 3] & mask))
			continue;

		MAP[y][x] = num;
		rowState[y] |= mask;
		colState[x] |= mask;
		squareState[y / 3][x / 3] |= mask;

		dfs(level + 1);

		squareState[y / 3][x / 3] &= ~mask;
		colState[x] &= ~mask;
		rowState[y] &= ~mask;
		MAP[y][x] = 0;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	for (int y = 0; y < SIZE; ++y) {
		string row;
		cin >> row;

		for (int x = 0; x < SIZE; ++x) {
			int num = row[x] - '0';
			MAP[y][x] = num;

			if (num == 0)
				continue;

			rowState[y] |= (1 << num);
			colState[x] |= (1 << num);
			squareState[y / 3][x / 3] |= (1 << num);
		}
	}

	dfs(0);

	return 0;
}
