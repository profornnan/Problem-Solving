#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int>& arr, const int target) {
	int left = 0;
	int right = arr.size() - 1;

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
	vector<int> idx(N);
	vector<int> seq;

	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	seq.push_back(arr[0]);

	for (int i = 1; i < N; ++i) {
		if (seq.back() < arr[i]) {
			idx[i] = seq.size();
			seq.push_back(arr[i]);
		}
		else {
			const int lb = lowerBound(seq, arr[i]);
			idx[i] = lb;
			seq[lb] = arr[i];
		}
	}

	vector<int> ans;

	for (int i = N - 1; i >= 0; --i)
		if (idx[i] == seq.size() - ans.size() - 1)
			ans.push_back(arr[i]);

	cout << ans.size() << '\n';

	for (int i = ans.size() - 1; i >= 0; --i)
		cout << ans[i] << ' ';
	cout << '\n';

	return 0;
}
