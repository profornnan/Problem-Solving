#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S;
int num[40];
vector<int> sum1, sum2;

void dfs(int s, int e, int sum, vector<int>& v) {
	v.push_back(sum);
	
	for (int i = s + 1; i < e; i++)
		dfs(i, e, sum + num[i], v);
}

int upperBound(int target) {
	int left = 0;
	int right = sum2.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (sum2[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return right;
}

int lowerBound(int target) {
	int left = 0;
	int right = sum2.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (sum2[mid] >= target)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return right;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	dfs(-1, N / 2, 0, sum1);
	dfs(N / 2 - 1, N, 0, sum2);

	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());

	long long ans = 0;

	int cnt = 1, now = sum1[0];

	for (int i = 1; i < sum1.size(); i++) {
		if (sum1[i] == now) {
			cnt++;
			continue;
		}

		ans += (long long)cnt * (upperBound(S - now) - lowerBound(S - now));
		now = sum1[i];
		cnt = 1;
	}

	ans += (long long)cnt * (upperBound(S - now) - lowerBound(S - now));

	if (S == 0)
		ans--;

	cout << ans << '\n';

	return 0;
}
