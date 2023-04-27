#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Gem {
	int weight;
	int price;
	bool operator < (const Gem &next) const {
		return weight < next.weight;
	}
};

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	
	int N, K;
	cin >> N >> K;
	
	vector<Gem> gems(N);
	vector<int> bags(K);

	for (Gem& gem : gems)
		cin >> gem.weight >> gem.price;

	for (int& bag : bags)
		cin >> bag;

	sort(gems.begin(), gems.end());
	sort(bags.begin(), bags.end());

	int idx = 0;
	long long sum = 0;
	priority_queue<int> pq;

	for (int bag : bags) {
		while (idx < N) {
			Gem gem = gems[idx];
			if (gem.weight > bag) break;
			pq.push(gem.price);
			idx++;
		}

		if (pq.empty()) continue;

		sum += pq.top();
		pq.pop();
	}

	cout << sum << '\n';

	return 0;
}
