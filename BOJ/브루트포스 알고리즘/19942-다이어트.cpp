#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 987654321;

struct Nutrient {
	int p, f, s, v;

	Nutrient operator+(const Nutrient& rhs) {
		return { p + rhs.p, f + rhs.f, s + rhs.s, v + rhs.v };
	}
};

struct Ingredient {
	Nutrient n;
	int c;
};

int N;
Nutrient m;
vector<Ingredient> ingredients;
vector<int> path;

int minCost = INF;
vector<int> minCostPath;

void dfs(int prev, Nutrient nutrient, int cost) {
	if (cost >= minCost)
		return;

	if (nutrient.p >= m.p && nutrient.f >= m.f && nutrient.s >= m.s && nutrient.v >= m.v) {
		minCost = cost;
		minCostPath = path;
		return;
	}

	for (int now = prev + 1; now < N; ++now) {
		const auto& [n, c] = ingredients[now];

		path.push_back(now);
		dfs(now, nutrient + n, cost + c);
		path.pop_back();
	}
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;
	cin >> m.p >> m.f >> m.s >> m.v;

	ingredients.assign(N, {});

	for (auto& [n, c] : ingredients)
		cin >> n.p >> n.f >> n.s >> n.v >> c;

	dfs(-1, {}, 0);

	if (minCost == INF) {
		cout << "-1\n";
		return 0;
	}

	cout << minCost << '\n';

	for (const auto& idx : minCostPath)
		cout << idx + 1 << ' ';
	cout << '\n';

	return 0;
}
