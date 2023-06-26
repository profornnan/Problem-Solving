#include <iostream>
#include <algorithm>
using namespace std;

int N;
int S[200000];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int gcdArr(int left, int right) {
	int ret = 0;

	for (int i = left; i <= right; i++)
		ret = gcd(ret, S[i]);

	return ret;
}

int dfs(int left, int right) {
	if (left == right)
		return S[left];

	int mid = (left + right - 1) / 2;

	return max(gcdArr(left, mid) + dfs(mid + 1, right), dfs(left, mid) + gcdArr(mid + 1, right));
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> S[i];

	cout << dfs(0, N - 1) << '\n';

	return 0;
}
