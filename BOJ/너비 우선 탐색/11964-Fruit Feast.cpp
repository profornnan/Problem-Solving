#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int N = 2;

int T;
int fruit[N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < N; ++i)
		cin >> fruit[i];

	queue<pair<int, bool>> q;
	vector<bool> visited(T + 1);

	q.push({ 0, true });
	visited[0] = true;

	int ans = 0;

	while (!q.empty()) {
		const auto [now, water] = q.front();
		q.pop();

		ans = ans > now ? ans : now;

		for (int i = 0; i < N; ++i) {
			const int next = now + fruit[i];

			if (next > T || visited[next])
				continue;

			q.push({ next, water });
			visited[next] = true;
		}

		if (water) {
			const int next = now / 2;

			if (visited[next])
				continue;

			q.push({ next, false });
			visited[next] = true;
		}
	}

	cout << ans << '\n';

	return 0;
}
