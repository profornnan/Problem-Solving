#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	const int SIZE = 2 * N;

	vector<int> durability(SIZE);
	vector<bool> robot(SIZE);

	int upIdx = 0;
	int downIdx = N - 1;
	int step = 0;
	int zeroCnt = 0;

	for (int& d : durability) {
		cin >> d;
		if (!d) ++zeroCnt;
	}

	while (zeroCnt < K) {
		++step;

		upIdx = (upIdx + SIZE - 1) % SIZE;
		downIdx = (downIdx + SIZE - 1) % SIZE;

		robot[downIdx] = false;

		for (int i = N - 2; i >= 0; --i) {
			int nowIdx = (upIdx + i) % SIZE;
			int nextIdx = (upIdx + i + 1) % SIZE;

			if (robot[nowIdx] && !robot[nextIdx] && durability[nextIdx]) {
				robot[nextIdx] = true;
				robot[nowIdx] = false;
				if (!--durability[nextIdx])
					++zeroCnt;
			}
		}

		robot[downIdx] = false;

		if (durability[upIdx]) {
			robot[upIdx] = true;
			if (!--durability[upIdx])
				++zeroCnt;
		}
	}

	cout << step << '\n';

	return 0;
}
