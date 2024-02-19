#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int T, N, M;
	cin >> T >> N;

	vector<int> aSum(N + 1);

	for (int i = 1; i <= N; ++i) {
		cin >> aSum[i];
		aSum[i] += aSum[i - 1];
	}

	cin >> M;

	vector<int> bSum(M + 1);

	for (int i = 1; i <= M; ++i) {
		cin >> bSum[i];
		bSum[i] += bSum[i - 1];
	}

	vector<int> A, B;

	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j <= N; ++j)
			A.push_back(aSum[j] - aSum[i]);

	for (int i = 0; i < M; ++i)
		for (int j = i + 1; j <= M; ++j)
			B.push_back(bSum[j] - bSum[i]);

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	long long ans = 0;
	int left = 0;
	int right = B.size() - 1;

	while (left < A.size() && right >= 0) {
		int sum = A[left] + B[right];

		if (sum == T) {
			int acnt = 0, bcnt = 0;
			int a = A[left], b = B[right];

			while (left < A.size() && A[left] == a) {
				++left;
				++acnt;
			}

			while (right >= 0 && B[right] == b) {
				--right;
				++bcnt;
			}

			ans += static_cast<long long>(acnt) * bcnt;
		}
		else if (sum < T)
			++left;
		else
			--right;
	}

	cout << ans << '\n';

	return 0;
}
