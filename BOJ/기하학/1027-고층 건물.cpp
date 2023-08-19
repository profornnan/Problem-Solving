#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> heights(N);
	vector<int> cnt(N);

	for (auto& h : heights)
		cin >> h;

	for (int i = 0; i < N; ++i) {
		double gradient = -21e8;

		for (int j = i + 1; j < N; ++j) {
			double g = ((double)heights[j] - heights[i]) / ((double)j - i);

			if (g <= gradient)
				continue;

			gradient = g;
			++cnt[i];
			++cnt[j];
		}
	}

	cout << *max_element(cnt.begin(), cnt.end()) << '\n';

	return 0;
}
