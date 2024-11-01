#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

constexpr int INF = 987'654'321;
constexpr int MAX_H = 100;
constexpr int MAX_B = 100;
constexpr int MAX_P = 1'000;

int H, B;
int hSum, bSum;
int hDp[MAX_H * MAX_P + 1];
int bDp[MAX_B * MAX_P + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> H;

	hDp[0] = 1;

	for (int i = 0; i < H; ++i) {
		int h;
		cin >> h;
		hSum += h;

		for (int j = hSum; j >= 0; --j)
			if (j - h >= 0 && hDp[j - h])
				hDp[j] = hDp[j] == 0 ? hDp[j - h] + 1 : min(hDp[j], hDp[j - h] + 1);
	}

	cin >> B;

	bDp[0] = 1;

	for (int i = 0; i < B; ++i) {
		int b;
		cin >> b;
		bSum += b;

		for (int j = bSum; j >= 0; --j)
			if (j - b >= 0 && bDp[j - b])
				bDp[j] = bDp[j] == 0 ? bDp[j - b] + 1 : min(bDp[j], bDp[j - b] + 1);
	}

	int ans = INF;

	for (int i = min(hSum, bSum); i > 0; --i)
		if (hDp[i] && bDp[i])
			ans = min(ans, hDp[i] + bDp[i] - 2);

	cout << (ans == INF ? "impossible" : to_string(ans)) << '\n';

	return 0;
}
