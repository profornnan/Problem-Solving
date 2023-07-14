#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

constexpr int INF = 21e8;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> values(N);

	for (int& val : values)
		cin >> val;

	int leftIdx = 0, rightIdx = N - 1;
	int leftVal = values[leftIdx], rightVal = values[rightIdx];
	int minValSum = INF;

	while (leftIdx < rightIdx) {
		int valSum = abs(values[rightIdx] + values[leftIdx]);

		if (minValSum > valSum) {
			minValSum = valSum;
			leftVal = values[leftIdx];
			rightVal = values[rightIdx];
		}

		abs(values[rightIdx] + values[leftIdx + 1]) < abs(values[rightIdx - 1] + values[leftIdx]) ? ++leftIdx : --rightIdx;
	}

	cout << leftVal << ' ' << rightVal << '\n';

	return 0;
}
