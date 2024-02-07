#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> pos(N + 1);

	for (int i = 0; i < N; ++i)
		cin >> pos[i];

	sort(pos.begin(), pos.end());

	int ans = 0;
	int zeroIdx = lower_bound(pos.begin(), pos.end(), 0) - pos.begin();

	for (int i = 0; i < zeroIdx; i += M)
		ans += abs(pos[i] * 2);

	for (int i = N; i > zeroIdx; i -= M)
		ans += pos[i] * 2;

	ans -= max(abs(pos[0]), abs(pos[N]));

	cout << ans << '\n';

	return 0;
}
