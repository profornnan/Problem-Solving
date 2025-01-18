#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int>& arr, const int target) {
	int left = 0;
	int right = arr.size();

	while (left < right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}

	return right;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> arr(N);
	vector<int> seq;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	seq.push_back(arr[0]);

	for (int i = 1; i < N; ++i) {
		if (seq.back() < arr[i])
			seq.emplace_back(arr[i]);
		else
			seq[lowerBound(seq, arr[i])] = arr[i];
	}

	cout << seq.size() << '\n';

	return 0;
}
