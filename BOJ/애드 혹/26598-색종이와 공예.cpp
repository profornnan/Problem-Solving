#include <iostream>
using namespace std;

constexpr int MAX_N = 1'000;
constexpr int MAX_M = 1'000;

int N, M;
char arr[MAX_N][MAX_M];

bool isValid(const int y, const int x) {
	const char lu = arr[y][x];
	const char ru = arr[y][x + 1];
	const char ld = arr[y + 1][x];
	const char rd = arr[y + 1][x + 1];

	if (lu == ru) {
		if (lu == ld && ru != rd)
			return false;

		if (lu != ld && ru == rd)
			return false;
	}
	else if (ld == rd) {
		if (lu == ld && ru != rd)
			return false;

		if (lu != ld && ru == rd)
			return false;
	}

	return true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int y = 0; y < N; ++y)
		for (int x = 0; x < M; ++x)
			cin >> arr[y][x];

	for (int y = 0; y < N - 1; ++y) {
		for (int x = 0; x < M - 1; ++x) {
			if (!isValid(y, x)) {
				cout << "BaboBabo\n";
				return 0;
			}
		}
	}

	cout << "dd\n";

	return 0;
}
