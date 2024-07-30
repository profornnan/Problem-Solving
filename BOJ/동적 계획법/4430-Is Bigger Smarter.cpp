#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Elephant {
	int id;
	int weight;
	int intelligence;

	bool operator<(const Elephant& rhs) const {
		return weight != rhs.weight ? weight < rhs.weight : intelligence < rhs.intelligence;
	}
};

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int weight, intelligence;
	vector<Elephant> elephants;

	while (cin >> weight >> intelligence)
		elephants.push_back({ static_cast<int>(elephants.size() + 1), weight, intelligence });

	sort(elephants.begin(), elephants.end());

	int maxIdx = 0;
	vector<int> dp(elephants.size(), 1);
	vector<int> parent(elephants.size());

	for (int i = 0; i < elephants.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (elephants[j].intelligence > elephants[i].intelligence && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				parent[i] = j;
			}
		}

		if (dp[maxIdx] < dp[i])
			maxIdx = i;
	}

	cout << dp[maxIdx] << '\n';

	int now = maxIdx;
	vector<int> path;

	while (now) {
		path.push_back(elephants[now].id);
		now = parent[now];
	}

	for (int i = path.size() - 1; i >= 0; --i)
		cout << path[i] << '\n';

	return 0;
}
