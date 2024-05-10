#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int INF = 987654321;

struct Rain {
	int en;
	int id;

	bool operator<(const Rain& rhs) const {
		return en > rhs.en;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int Z;
	cin >> Z;

	while (Z--) {
		int N, M;
		cin >> N >> M;

		vector<int> rain(M);
		vector<int> en(M);

		vector<int> prev(N + 1, INF);
		vector<bool> water(N + 1, true);

		vector<int> drink;

		for (int i = 0; i < M; ++i)
			cin >> rain[i];

		for (int i = M - 1; i >= 0; --i) {
			const int id = rain[i];

			if (id == 0)
				continue;

			en[i] = prev[id];
			prev[id] = i;
		}

		bool possible = true;
		priority_queue<Rain> pq;

		for (int i = 1; i <= N; ++i)
			if (prev[i] != INF)
				pq.push({ prev[i], i });

		for (int i = 0; i < M; ++i) {
			int id = rain[i];

			if (id == 0) {
				if (!pq.empty()) {
					id = pq.top().id;
					pq.pop();
					water[id] = false;
				}

				drink.emplace_back(id);
			}
			else {
				if (water[id]) {
					possible = false;
					break;
				}

				pq.push({ en[i], id });
				water[id] = true;
			}
		}

		if (possible) {
			cout << "YES\n";

			for (const auto& id : drink)
				cout << id << ' ';

			cout << '\n';
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
