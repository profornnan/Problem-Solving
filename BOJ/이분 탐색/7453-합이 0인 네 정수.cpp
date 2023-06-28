#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<vector<int>> v(4, vector<int>(N));
	vector<vector<int>> sum(2, vector<int>(N * N));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++)
			cin >> v[j][i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum[0][i * N + j] = v[0][i] + v[1][j];
			sum[1][i * N + j] = v[2][i] + v[3][j];
		}
	}

	sort(sum[1].begin(), sum[1].end());

	long long ans = 0;

	for (const int& target : sum[0])
		ans += upper_bound(sum[1].begin(), sum[1].end(), -target) - lower_bound(sum[1].begin(), sum[1].end(), -target);

	cout << ans << '\n';

	return 0;
}
