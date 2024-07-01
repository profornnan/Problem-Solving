#include <iostream>
using namespace std;

constexpr int MAX_N = 1'000'000;

int N, ans;
int darts[MAX_N];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int balloon;
		cin >> balloon;

		darts[balloon] ? --darts[balloon] : ++ans;
		++darts[balloon - 1];
	}

	cout << ans << '\n';

	return 0;
}
