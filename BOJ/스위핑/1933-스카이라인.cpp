#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<pair<int, int>> info;
	multiset<int> remains({ 0 });

	for (int i = 0; i < N; ++i) {
		int left, height, right;
		cin >> left >> height >> right;
		info.push_back({ left, -height });
		info.push_back({ right, height });
	}

	sort(info.begin(), info.end());

	for (const auto& [pos, height] : info) {
		if (height < 0) {
			if (*remains.rbegin() < -height)
				cout << pos << ' ' << -height << ' ';

			remains.insert(-height);
		}
		else if (height > 0) {
			remains.erase(remains.find(height));

			if (*remains.rbegin() < height)
				cout << pos << ' ' << *remains.rbegin() << ' ';
		}
	}

	return 0;
}
