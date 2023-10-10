#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pii> tasks(N);

	for (auto& [limit, cost] : tasks)
		cin >> cost >> limit;

	sort(tasks.begin(), tasks.end());

	auto [now, ignore] = tasks[N - 1];

	for (int i = N - 1; i >= 0; --i) {
		const auto& [limit, cost] = tasks[i];

		now = min(now, limit);

		if (now - cost < 0) {
			cout << "-1\n";
			return 0;
		}

		now -= cost;
	}

	cout << now << '\n';

	return 0;
}
