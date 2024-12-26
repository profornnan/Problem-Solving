#include <iostream>
#include <cstring>
using namespace std;

constexpr int MAX_N = 250'000;

long long hNum[MAX_N + 1];
bool hPrime[MAX_N + 1];
int psum[MAX_N + 1];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	for (int i = 0; i <= MAX_N; ++i)
		hNum[i] = i * 4 + 1;

	memset(hPrime, true, sizeof(hPrime));

	hPrime[0] = false;

	for (int i = 1; i <= MAX_N; ++i)
		if (hPrime[i])
			for (int j = i; (hNum[i] * hNum[j] - 1) / 4 <= MAX_N; ++j)
				hPrime[(hNum[i] * hNum[j] - 1) / 4] = false;

	for (int i = 1; i <= MAX_N; ++i)
		if (hPrime[i])
			for (int j = i; (hNum[i] * hNum[j] - 1) / 4 <= MAX_N; ++j)
				if (hPrime[j])
					psum[(hNum[i] * hNum[j] - 1) / 4] = 1;

	for (int i = 1; i <= MAX_N; ++i)
		psum[i] += psum[i - 1];

	while (true) {
		int H;
		cin >> H;

		if (!H)
			break;

		cout << H << ' ' << psum[(H - 1) / 4] << '\n';
	}

	return 0;
}
