#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

constexpr long long BASE = 127;
constexpr int SIZE = 26;

long long power[SIZE];

int main(void) {
	cin.tie(nullptr)->sync_with_stdio(false);

	power[0] = 1;

	for (int i = 1; i < SIZE; ++i)
		power[i] = power[i - 1] * BASE;

	string a, b;
	cin >> a >> b;

	if (a.length() > b.length())
		swap(a, b);

	for (int len = a.length() - 1; len >= 0; --len) {
		long long aHash = 0;
		vector<long long> aHashArr;

		for (int i = 0; i < len; ++i)
			aHash += a[i] * power[a[i] - 'a'];

		for (int i = len; i < a.length(); ++i) {
			aHash += a[i] * power[a[i] - 'a'];
			aHashArr.push_back(aHash);
			aHash -= a[i - len] * power[a[i - len] - 'a'];
		}

		sort(aHashArr.begin(), aHashArr.end());

		long long bHash = 0;

		for (int i = 0; i < len; ++i)
			bHash += b[i] * power[b[i] - 'a'];

		for (int i = len; i < b.length(); ++i) {
			bHash += b[i] * power[b[i] - 'a'];

			if (binary_search(aHashArr.begin(), aHashArr.end(), bHash)) {
				cout << len + 1 << '\n';
				return 0;
			}

			bHash -= b[i - len] * power[b[i - len] - 'a'];
		}
	}

	cout << "0\n";

	return 0;
}
