#include <iostream>
#include <cmath>
using namespace std;

constexpr int MAX_N = 1'000;

int N;
int res[MAX_N];
int card[MAX_N];
int temp[MAX_N];

void shuffle(const int k) {
	int en = N;

	for (int i = 1; i <= k + 1; ++i) {
		const int cnt = pow(2, k + 1 - i);

		for (int j = 0; j < en; ++j)
			temp[j] = card[(en - cnt + j) % en];

		for (int j = 0; j < en; ++j)
			card[j] = temp[j];

		en = cnt;
	}
}

bool isSame() {
	for (int i = 0; i < N; ++i)
		if (res[i] != card[i])
			return false;
	return true;
}

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; ++i)
		cin >> res[i];

	for (int k1 = 1; pow(2, k1) <= N; ++k1) {
		for (int k2 = 1; pow(2, k2) <= N; ++k2) {
			for (int i = 0; i < N; ++i)
				card[i] = i + 1;

			shuffle(k1);
			shuffle(k2);

			if (isSame()) {
				cout << k1 << ' ' << k2 << '\n';
				return 0;
			}
		}
	}

	return 0;
}
