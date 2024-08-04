#include <iostream>
using namespace std;

constexpr int MAX_M = 1'000;

int N, M;
int prev, now;
int cnt[MAX_M];
long long ans;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		cin >> now;

		now = (::prev + now) % M;

		if (now == 0)
			++ans;

		ans += cnt[now];
		++cnt[now];
		::prev = now;
	}

	cout << ans << '\n';

	return 0;
}
