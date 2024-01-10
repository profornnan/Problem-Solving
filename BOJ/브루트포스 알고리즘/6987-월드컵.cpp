#include <iostream>
#include <vector>
using namespace std;

constexpr int T = 4;
constexpr int N = 6;

struct Country {
	int win;
	int draw;
	int lose;
};

vector<Country> countries(N);
vector<pair<int, int>> matches;
int ans;

void dfs(int level) {
	if (level >= matches.size()) {
		for (const auto& [win, draw, lose] : countries)
			if (win != 0 || draw != 0 || lose != 0)
				return;
		ans = 1;
		return;
	}

	const auto& [u, v] = matches[level];

	auto& U = countries[u];
	auto& V = countries[v];

	if (U.win > 0 && V.lose > 0) {
		--U.win;
		--V.lose;
		dfs(level + 1);
		++V.lose;
		++U.win;
	}

	if (U.draw > 0 && V.draw > 0) {
		--U.draw;
		--V.draw;
		dfs(level + 1);
		++V.draw;
		++U.draw;
	}

	if (U.lose > 0 && V.win > 0) {
		--U.lose;
		--V.win;
		dfs(level + 1);
		++V.win;
		++U.lose;
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	for (int u = 0; u < N; ++u)
		for (int v = u + 1; v < N; ++v)
			matches.push_back({ u, v });

	for (int tc = 1; tc <= T; ++tc) {
		ans = 0;

		for (auto& [win, draw, lose] : countries)
			cin >> win >> draw >> lose;

		dfs(0);

		cout << ans << ' ';
	}

	return 0;
}
