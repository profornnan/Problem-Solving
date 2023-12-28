#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_M = 1'000'000;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> players(N);
	vector<bool> isCard(MAX_M + 1);
	vector<int> scores(MAX_M + 1);

	for (auto& player : players) {
		cin >> player;
		isCard[player] = true;
	}

	for (const auto& player : players) {
		for (int multiple = player * 2; multiple <= MAX_M; multiple += player) {
			if (!isCard[multiple])
				continue;

			++scores[player];
			--scores[multiple];
		}
	}

	for (const auto& player : players)
		cout << scores[player] << ' ';
	cout << '\n';

	return 0;
}
