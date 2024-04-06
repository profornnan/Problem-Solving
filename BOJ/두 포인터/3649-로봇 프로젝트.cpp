#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 1'000'000;

int W, N;
int width[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	while (cin >> W >> N) {
		W *= 10'000'000;

		for (int i = 0; i < N; ++i)
			cin >> width[i];

		sort(width, width + N);

		int left = 0;
		int right = N - 1;

		while (left < right) {
			const int sum = width[left] + width[right];

			if (sum == W)
				break;
			else if (sum < W)
				++left;
			else if (sum > W)
				--right;
		}

		if (left < right)
			cout << "yes " << width[left] << ' ' << width[right] << '\n';
		else
			cout << "danger\n";
	}

	return 0;
}
