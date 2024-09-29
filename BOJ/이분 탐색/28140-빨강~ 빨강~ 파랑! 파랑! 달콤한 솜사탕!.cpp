#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 21e8;

int lowerBound(const vector<int>& arr, const int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (left < right) {
		const int mid = left + (right - left) / 2;

		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int upperBound(const vector<int>& arr, const int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (left < right) {
		const int mid = left + (right - left) / 2;

		if (arr[mid] <= target)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;

	vector<int> R;
	vector<int> B;

	for (int i = 0; i < N; ++i) {
		char ch;
		cin >> ch;

		if (ch == 'R')
			R.push_back(i);
		else if (ch == 'B')
			B.push_back(i);
	}

	B.push_back(INF);

	for (int i = 0; i < Q; ++i) {
		int st, en;
		cin >> st >> en;

		int ridx = lowerBound(R, st);
		int bidx = upperBound(B, en) - 1;

		if (ridx == R.size() - 1 || bidx <= 0 || R[ridx + 1] > B[bidx - 1])
			cout << "-1\n";
		else
			cout << R[ridx] << ' ' << R[ridx + 1] << ' ' << B[bidx - 1] << ' ' << B[bidx] << '\n';
	}

	return 0;
}
