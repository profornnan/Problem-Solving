#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	int maxLen = 0, maxIdx = 0;
	vector<int> arr(N), dp(N, 1), parent(N);
	
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		parent[i] = i;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				parent[i] = j;
			}
		}
		if (maxLen < dp[i]) {
			maxLen = dp[i];
			maxIdx = i;
		}
	}

	vector<int> path;

	int now = maxIdx;

	while (parent[now] != now) {
		path.push_back(arr[now]);
		now = parent[now];
	}

	path.push_back(arr[now]);

	cout << dp[maxIdx] << '\n';

	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << ' ';
	cout << '\n';

	return 0;
}
