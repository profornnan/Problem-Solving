#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Square {
	int x;
	int r;
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	int M = 0;
	vector<Square> squares(1);

	for (int i = 1; i <= N; ++i) {
		int nr;
		cin >> nr;

		int nx = nr;

		for (const auto& [x, r] : squares)
			nx = max(nx, x + min(nr, r) * 2);

		M = max(M, nx + nr);
		squares.push_back({ nx, nr });
	}

	vector<int> arr(M);

	for (int i = 1; i <= N; ++i) {
		auto& [x, r] = squares[i];

		for (int c = max(0, x - r); c < x + r; ++c)
			if (squares[arr[c]].r < r)
				arr[c] = i;
	}

	arr.push_back(0);

	int now = arr[0];

	for (const auto& i : arr) {
		if (i != now) {
			cout << now << ' ';
			now = i;
		}
	}

	cout << '\n';

	return 0;
}
