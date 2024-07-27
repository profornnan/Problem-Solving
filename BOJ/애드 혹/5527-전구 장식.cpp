#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> psum({ 1 });
	int prev;
	cin >> prev;

	for (int i = 1; i < N; ++i) {
		int now;
		cin >> now;

		if (now == prev)
			psum.push_back(psum.back());

		++psum.back();
		prev = now;
	}

	if (psum.size() <= 3) {
		cout << psum.back() << '\n';
		return 0;
	}

	int ans = psum[2];

	for (int i = 3; i < psum.size(); ++i)
		ans = max(ans, psum[i] - psum[i - 3]);

	cout << ans << '\n';

	return 0;
}
