#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N);

	for (int& a : A)
		cin >> a;

	for (int& b : B)
		cin >> b;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int ans = 0;

	for (int& a : A) {
		for (int& b : B) {
			if (b && a > b) {
				ans += 2;
				a = 0;
				b = 0;
				break;
			}
		}
	}

	for (int& a : A) {
		if (a == 0)
			continue;

		for (int& b : B) {
			if (b && a == b) {
				++ans;
				b = 0;
				break;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
