#include <iostream>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 3'000'000;
constexpr int MAX_D = 3'000;

int N, D, K, C;
int dishes[MAX_N];
int dishCnts[MAX_D + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> D >> K >> C;

	for (int i = 0; i < N; ++i)
		cin >> dishes[i];

	int left = 0;
	int right = K - 1;
	int typeCnt = 0;
	int maxTypeCnt = 0;

	for (int i = 0; i < right; ++i)
		if (!dishCnts[dishes[i]]++)
			++typeCnt;

	for (int i = 0; i < N; ++i) {
		if (!dishCnts[dishes[right]]++)
			++typeCnt;

		maxTypeCnt = max(maxTypeCnt, typeCnt + !dishCnts[C]);

		if (!(--dishCnts[dishes[left]]))
			--typeCnt;

		left = (left + 1) % N;
		right = (right + 1) % N;
	}

	cout << maxTypeCnt << '\n';

	return 0;
}
