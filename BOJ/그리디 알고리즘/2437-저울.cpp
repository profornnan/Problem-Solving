#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> weights(N);

	for (auto& weight : weights)
		cin >> weight;

	sort(weights.begin(), weights.end());

	int en = 1;

	for (const auto& weight : weights) {
		if (en < weight)
			break;

		en += weight;
	}

	cout << en << '\n';

	return 0;
}
