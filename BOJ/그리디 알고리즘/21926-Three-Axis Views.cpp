#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX_N = 100;

int N;
bool cubes[MAX_N][MAX_N][MAX_N];
bool faces[3][MAX_N][MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	memset(cubes, true, sizeof(cubes));

	for (int z = N - 1; z >= 0; --z) {
		for (int y = 0; y < N; ++y) {
			char ch;
			cin >> ch;
			faces[0][z][y] = ch == '0' ? false : true;

			if (!faces[0][z][y])
				for (int x = 0; x < N; ++x)
					cubes[z][y][x] = false;
		}
	}

	for (int x = N - 1; x >= 0; --x) {
		for (int z = 0; z < N; ++z) {
			char ch;
			cin >> ch;
			faces[1][x][z] = ch == '0' ? false : true;;

			if (!faces[1][x][z])
				for (int y = 0; y < N; ++y)
					cubes[z][y][x] = false;
		}
	}

	for (int y = N - 1; y >= 0; --y) {
		for (int x = 0; x < N; ++x) {
			char ch;
			cin >> ch;
			faces[2][y][x] = ch == '0' ? false : true;

			if (!faces[2][y][x])
				for (int z = 0; z < N; ++z)
					cubes[z][y][x] = false;
		}
	}

	for (int z = N - 1; z >= 0; --z) {
		for (int y = 0; y < N; ++y) {
			if (faces[0][z][y]) {
				bool valid = false;

				for (int x = 0; x < N; ++x)
					if (cubes[z][y][x])
						valid = true;

				if (!valid) {
					cout << "No\n";
					return 0;
				}
			}
		}
	}

	for (int x = N - 1; x >= 0; --x) {
		for (int z = 0; z < N; ++z) {
			if (faces[1][x][z]) {
				bool valid = false;

				for (int y = 0; y < N; ++y)
					if (cubes[z][y][x])
						valid = true;

				if (!valid) {
					cout << "No\n";
					return 0;
				}
			}
		}
	}

	for (int y = N - 1; y >= 0; --y) {
		for (int x = 0; x < N; ++x) {
			if (faces[2][y][x]) {
				bool valid = false;

				for (int z = 0; z < N; ++z)
					if (cubes[z][y][x])
						valid = true;

				if (!valid) {
					cout << "No\n";
					return 0;
				}
			}
		}
	}

	cout << "Yes\n";

	return 0;
}
